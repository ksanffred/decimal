#include "s21_decimal.h"

int get_bit(s21_decimal value, int index) {
  return (value.bits[index / 32] >> index % 32) & 1;
}

int get_BIG_bit(s21_BIG_decimal value, int index) {
  return (value.bits[index / 32] >> index % 32) & 1;
}

int power(s21_decimal value) {
  int res = 0;
  int power = 1;
  for (int i = 0; i < 8; i++) {
    res += ((value.bits[3] >> (i + 16)) & 1) * power;
    power *= 2;
  }
  return res;
}

int changing_power(s21_decimal *value, int new_index) {
  int ret = 0;
  int minus = sign(*value);
  value->bits[3] = new_index << 16;
  value->bits[3] |= minus << 31;
  return ret;
}

int sign(s21_decimal value) { return value.bits[3] < 0; }

void changing_sign(s21_decimal *value) {
  value->bits[3] = !sign(*value) << 31 | power(*value) << 16;
}

int signB(s21_BIG_decimal value) { return value.bits[3] < 0; }

int normalization(s21_decimal *value_1, s21_decimal *value_2) {
  int ret = 0;
  int pow1 = power(*value_1);
  int pow2 = power(*value_2);
  s21_BIG_decimal temp = {{0, 0, 0, 0, 0}};
  if (pow1 != pow2) {
    int extrpow = pow1 < pow2 ? pow2 - pow1 : pow1 - pow2;
    for (int i = 0; i < 3; i++) {
      temp.bits[i] = pow1 < pow2 ? value_1->bits[i] : value_2->bits[i];
    }
    for (int i = 0; i < extrpow; i++) {
      if (multiten(&temp) == 1) {
        ret = pow1 < pow2 ? 1 : 2;
        break;
      }
    }
    if (ret == 0) {
      for (int i = 0; i < 3; i++) {
        if (pow1 < pow2)
          value_1->bits[i] = temp.bits[i];
        else
          value_2->bits[i] = temp.bits[i];
      }
      changing_power(pow1 < pow2 ? value_1 : value_2,
                     pow1 < pow2 ? pow2 : pow1);
    }
  }
  return ret;
}

int anti_normalization(s21_decimal *value_1, s21_decimal *value_2) {
  int ret = 0;
  int pow1 = power(*value_1);
  int pow2 = power(*value_2);
  int extrpow = pow1 < pow2 ? pow2 - pow1 : pow1 - pow2;
  for (int i = 0; i < extrpow - 1; i++) {
    divten(pow1 > pow2 ? value_1 : value_2);
  }
  int last = pow1 > pow2 ? value_1->bits[0] % 10 : value_2->bits[0] % 10;
  divten(pow1 > pow2 ? value_1 : value_2);
  if (last > 5) pow1 > pow2 ? value_1->bits[0]++ : value_2->bits[0]++;
  changing_power(pow1 > pow2 ? value_1 : value_2, pow1 > pow2 ? pow2 : pow1);
  return ret;
}

int divten(s21_decimal *value) {
  int ret = 0;
  s21_BIG_decimal temp = {{0, 0, 0, 0, 0}};
  unsigned remainder = 0;

  for (int i = 95; i >= 0; i--) {
    remainder <<= 1;
    remainder |= get_bit(*value, i);
    if (remainder >= 10) {
      remainder -= 10;
      temp.bits[i / 32] |= (1 << i % 32);
    }
  }
  if (temp.bits[3] == 0) {
    for (int i = 0; i < 4; i++) {
      value->bits[i] = temp.bits[i];
    }
  }
  return ret;
}

// divten version that keeps the sign and exp
int div_ten_signed(s21_decimal *value) {
  s21_BIG_decimal temp = {{0, 0, 0, 0, 0}};
  unsigned carry = 0;

  for (int i = 95; i >= 0; i--) {
    carry <<= 1;
    carry |= get_bit(*value, i);
    if (carry >= 10) {
      carry -= 10;
      temp.bits[i / 32] |= (1 << (i % 32));
    }
  }
  for (int i = 0; i < 3; i++) {
    value->bits[i] = temp.bits[i];
  }
  return 0;
}

int multiten(s21_BIG_decimal *value) {
  int ret = 0;
  s21_BIG_decimal temp = {{0, 0, 0, 0, 0}};
  int carry = 0;
  for (int i = 0; i < 97; i++) {
    int bit = get_BIG_bit(*value, i);
    int res = (bit * 10) + carry;
    temp.bits[i / 32] |= (res & 1) << (i % 32);
    carry = res >> 1;
  }
  if (temp.bits[3] == 0) {
    for (int i = 0; i < 4; i++) {
      value->bits[i] = temp.bits[i];
    }
  } else
    ret = 1;
  return ret;
}

int s21_print_two(s21_decimal value) {
  int ret = 0;
  for (int k = 3; k >= 0; k--) {
    for (int i = 31; i >= 0; --i) {
      printf("%d", (value.bits[k] >> i) & 1);
    }
    printf("\n");
  }
  return ret;
}

void print_float_two(float src) {
  int isrc = *((int *)&src);
  for (int i = 31; i >= 0; --i) {
    printf("%d", (isrc >> i) & 1);
  }
  printf("\n");
}

int divtwo(s21_decimal *value) {
  int ret = 0;
  s21_BIG_decimal temp = {{0, 0, 0, 0, 0}};
  unsigned remainder = 0;

  for (int i = 95; i >= 0; i--) {
    remainder <<= 1;
    remainder |= get_bit(*value, i);
    if (remainder >= 2) {
      remainder -= 2;
      temp.bits[i / 32] |= (1 << i % 32);
    }
  }
  if (temp.bits[3] == 0) {
    for (int i = 0; i < 4; i++) {
      value->bits[i] = temp.bits[i];
    }
  }
  return ret;
}

int two_minus_pow(int pow) {
  int num = 100000000;
  for (int i = 1; i <= pow; i++) {
    num /= 2;
  }
  return num;
}

int is_devided_ten(s21_decimal value) { return (value.bits[0] % 10) == 0; }

s21_decimal s21_decimal_zero(void) {
  s21_decimal res = {0};  // Initialize all bits to null
  return res;
}

int is_zero(s21_decimal value) {
  int ret = 0;
  for (int i = 0; i < 3; i++) {
    if (value.bits[i] != 0) ret = 1;
  }
  return ret;
}

// ADDED

void shift_left_big(s21_BIG_decimal *value, int shift) {
  if (shift > 0) {
    int size = sizeof(value->bits) / sizeof(value->bits[0]);
    for (int a = 0; a < shift; a++) {
      int overflow_bit = 0;
      for (int i = 0; i < size; i++) {
        int new_overflow_bit = (value->bits[i] >> 31) & 1;
        value->bits[i] = (value->bits[i] << 1) | overflow_bit;
        overflow_bit = new_overflow_bit;
      }
    }
  }
}

void add_big_decimals(s21_BIG_decimal value_1, s21_BIG_decimal value_2,
                      s21_BIG_decimal *result) {
  int overflow_bit = 0;

  for (int i = 0; i < 32 * 6; ++i) {
    int bit1 = get_BIG_bit(value_1, i);
    int bit2 = get_BIG_bit(value_2, i);
    int sum = bit1 + bit2 + overflow_bit;

    set_BIG_bit(result, i, sum % 2);
    overflow_bit = sum / 2;
  }
}

void set_BIG_bit(s21_BIG_decimal *value, int index, int bit_value) {
  if (bit_value)
    value->bits[index / 32] |= (1 << (index % 32));
  else
    value->bits[index / 32] &= ~(1 << (index % 32));
}

int is_something_in_extra_bits(const s21_BIG_decimal *ptr_big) {
  int bool = 0;
  if (ptr_big->bits[5] || ptr_big->bits[4] || ptr_big->bits[3]) {
    bool = 1;
  }

  return bool;
}

void mul_ten_n_times_big(s21_BIG_decimal *ptr_big, int n) {
  while (n > 0) {
    mul_ten_big(ptr_big);
    n--;
  }
}

void mul_ten_big(s21_BIG_decimal *ptr_big) {
  shift_left_big(ptr_big, 1);

  s21_BIG_decimal temp = *ptr_big;
  shift_left_big(ptr_big, 2);

  add_big_decimals(temp, *ptr_big, ptr_big);
}

int is_zero_big_decimal(const s21_BIG_decimal *ptr_big) {
  int zero = 0;
  if (ptr_big->bits[5] == 0 && ptr_big->bits[4] == 0 && ptr_big->bits[3] == 0 &&
      ptr_big->bits[2] == 0 && ptr_big->bits[1] == 0 && ptr_big->bits[0] == 0) {
    zero = 1;
  }
  return zero;
}

int big_to_decimal(s21_BIG_decimal big, s21_decimal *result,
                   int *ptr_scale_result, int result_sign) {
  int error = 0, removed_digits = 0;
  s21_BIG_decimal buffer = {{0, 0, 0, 0, 0, 0}};
  s21_BIG_decimal last_digit = {{0, 0, 0, 0, 0, 0}};

  while (!is_zero_big_decimal(&big) && *ptr_scale_result > 0 &&
         (*ptr_scale_result > 28 || is_something_in_extra_bits(&big))) {
    div_ten_big(&big, &last_digit);
    mul_ten_n_times_big(&last_digit, removed_digits);
    add_big_decimals(last_digit, buffer, &buffer);
    removed_digits++;
    *ptr_scale_result -= 1;
  }

  if (is_something_in_extra_bits(&big)) {
    if (result_sign == 1) {
      error = 2;
    } else {
      error = 1;
    }
  } else {
    if (*ptr_scale_result > 28) {
      result->bits[0] = 0;
      result->bits[1] = 0;
      result->bits[2] = 0;
    } else {
      if (!is_zero_big_decimal(&buffer)) {
        s21_BIG_decimal temp = big;
        div_ten_big(&temp, &last_digit);

        s21_BIG_decimal one = {{1, 0, 0, 0, 0, 0}};
        s21_BIG_decimal five = {{5, 0, 0, 0, 0, 0}};
        mul_ten_n_times_big(&five, removed_digits - 1);

        if (compare_big_decimals(&buffer, &five) == 1) {
          add_big_decimals(big, one, &big);
        } else if (compare_big_decimals(&buffer, &five) == 0) {
          if (!is_even_big(last_digit)) {
            add_big_decimals(big, one, &big);
          }
        }
      }
      if (is_something_in_extra_bits(&big)) {
        if (result_sign == 1) {
          error = 2;
        } else {
          error = 1;
        }
      }

      if (!error) {
        result->bits[0] = big.bits[0];
        result->bits[1] = big.bits[1];
        result->bits[2] = big.bits[2];
        set_scale_decimal(result, *ptr_scale_result);
      }
    }
    if (result_sign) {
      set_sign_decimal(result);
    }
  }
  return error;
}

void div_ten_big(s21_BIG_decimal *ptr_big, s21_BIG_decimal *ptr_last_digit) {
  s21_BIG_decimal ten = {{10, 0, 0, 0, 0, 0}};
  bit_div(*ptr_big, ten, ptr_big, ptr_last_digit);
}

int compare_big_decimals(s21_BIG_decimal *ptr_big_1,
                         s21_BIG_decimal *ptr_big_2) {
  int result = 0;
  int bit_1 = 0;
  int bit_2 = 0;
  int stop = 0;
  for (int i = 191; i >= 0 && !stop; i--) {
    bit_1 = get_BIG_bit(*ptr_big_1, i);
    bit_2 = get_BIG_bit(*ptr_big_2, i);
    if (bit_1 > bit_2) {
      result = 1;
      stop = 1;
    }
    if (bit_1 < bit_2) {
      result = -1;
      stop = 1;
    }
  }
  return result;
}

void bit_subtraction(s21_BIG_decimal big_1, s21_BIG_decimal big_2,
                     s21_BIG_decimal *ptr_result) {
  int borrow = 0;
  int bit_1 = 0;
  int bit_2 = 0;
  for (int i = 0; i < 192; i++) {
    bit_1 = get_BIG_bit(big_1, i);
    bit_2 = get_BIG_bit(big_2, i);
    int result = bit_1 - bit_2 - borrow;
    if (result < 0) {
      result += 2;
      borrow = 1;
    } else {
      borrow = 0;
    }
    set_BIG_bit(ptr_result, i, result % 2);
  }
}

int get_index_of_highest_bit(s21_BIG_decimal *ptr_big) {
  int bit = 0;
  int index_of_highest = 0;
  for (int i = 191; bit == 0 && i >= 0; i--) {
    bit = get_BIG_bit(*ptr_big, i);
    index_of_highest = i;
  }
  return index_of_highest;
}

int is_even_big(s21_BIG_decimal big) { return (!get_BIG_bit(big, 0)); }

void set_scale_decimal(s21_decimal *ptr_decimal, int scale) {
  int sign_value = sign(*ptr_decimal);

  ptr_decimal->bits[3] = scale;
  ptr_decimal->bits[3] <<= 16;

  if (sign_value == 1) {
    set_sign_decimal(ptr_decimal);
  }
}

void set_sign_decimal(s21_decimal *ptr_decimal) {
  set_bit_int(&(ptr_decimal->bits[3]), 31, 1);
}

void set_bit_int(int *ptr_int, int index, int bit) {
  int mask = 1u << index;
  if (bit == 1) {
    *ptr_int |= mask;
  } else if (bit == 0) {
    *ptr_int &= ~mask;
  }
}

void bit_div(s21_BIG_decimal dividend, s21_BIG_decimal divisor,
             s21_BIG_decimal *big_result, s21_BIG_decimal *ptr_remainder) {
  s21_BIG_decimal temp_result = {0};
  s21_BIG_decimal temp_remainder = {0};
  int highest_bit = get_index_of_highest_bit(&dividend);
  for (int i = highest_bit; i >= 0; i--) {
    shift_left_big(&temp_remainder, 1);
    if (get_BIG_bit(dividend, i)) {
      set_BIG_bit(&temp_remainder, 0, 1);
    }
    if (compare_big_decimals(&temp_remainder, &divisor) >= 0) {
      bit_subtraction(temp_remainder, divisor, &temp_remainder);
      set_BIG_bit(&temp_result, i, 1);
    } else {
      set_BIG_bit(&temp_result, i, 0);
    }
  }
  if (big_result != NULL) {
    *big_result = temp_result;
  }
  if (ptr_remainder != NULL) {
    *ptr_remainder = temp_remainder;
  }
}

void decimal_to_big(s21_decimal value, s21_BIG_decimal *big) {
  for (int i = 0; i < 3; i++) {
    big->bits[i] = value.bits[i];
  }
}

void set_sign(s21_decimal *value, int sign) {
  if (sign) {
    value->bits[3] |= (1 << 31);
  } else {
    value->bits[3] &= ~(1 << 31);
  }
}

void set_scale(s21_decimal *value, int scale) {
  value->bits[3] &= ~(0xFF << 16);
  value->bits[3] |= (scale << 16);
}

int get_scale_decimal(s21_decimal decimal) {
  clear_sign_decimal(&decimal);
  return power(decimal);
}

int division_with_remainder(s21_BIG_decimal dividend, int scale_dividend,
                            s21_BIG_decimal divisor,
                            s21_BIG_decimal *ptr_result) {
  int scale_result = scale_dividend;
  if (ptr_result != NULL) {
    s21_BIG_decimal temp_remainder = {0};
    s21_BIG_decimal temp_result = {0};

    while (scale_result < 31 && !is_zero_big_decimal(&dividend)) {
      bit_div(dividend, divisor, &temp_result, &temp_remainder);
      if (!is_zero_big_decimal(&temp_remainder)) {
        mul_ten_big(&temp_remainder);
        scale_result++;
      }
      dividend = temp_remainder;
      zero_big_decimal(&temp_remainder);
      mul_ten_big(ptr_result);
      add_big_decimals(*ptr_result, temp_result, ptr_result);
      zero_big_decimal(&temp_result);
    };
    if (scale_result == 31) {
      scale_result--;
    }
  }
  return scale_result;
}

void clear_sign_decimal(s21_decimal *ptr_decimal) {
  set_bit_decimal(ptr_decimal, 127, 0);
}

void zero_big_decimal(s21_BIG_decimal *ptr_big) {
  ptr_big->bits[0] = 0;
  ptr_big->bits[1] = 0;
  ptr_big->bits[2] = 0;
  ptr_big->bits[3] = 0;
  ptr_big->bits[4] = 0;
  ptr_big->bits[5] = 0;
}

void set_bit_decimal(s21_decimal *ptr_decimal, int index, int bit) {
  int i = index / 32;
  int shift = index % 32;

  set_bit_int(&(ptr_decimal->bits[i]), shift, bit);
}