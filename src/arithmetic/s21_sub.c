#include "../s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int ret = 0;
  int extr = 0;
  s21_BIG_decimal temp = {{0, 0, 0, 0, 0}};
  if (sign(value_1) != sign(value_2)) {
    changing_sign(&value_2);
    ret = s21_add(value_1, value_2, result);
  } else {
    if (normalization(&value_1, &value_2) != 0) {
      anti_normalization(&value_1, &value_2);
    }
    int less = s21_is_less(value_1, value_2);
    if (sign(value_1) == 1) less = !less;
    s21_decimal *minuend = less ? &value_2 : &value_1;
    s21_decimal *subtrahend = less ? &value_1 : &value_2;
    for (int i = 0; i < 97; i++) {
      int res = get_bit(*minuend, i) - get_bit(*subtrahend, i) - extr;
      if (res < 0) {
        res += 2;
        extr = 1;
      } else
        extr = 0;
      temp.bits[i / 32] |= (res & 1) << i % 32;
    }
    if (temp.bits[3] == 0) {
      result->bits[3] = value_1.bits[3];
      if (less) changing_sign(result);
      for (int i = 0; i < 3; i++) {
        result->bits[i] = temp.bits[i];
      }
    } else
      ret = 1;
    if (sign(value_1) == 1 && ret == 1) ret = 2;
    if (is_zero(*result) == 0) result->bits[3] = 0;
  }
  return ret;
}
