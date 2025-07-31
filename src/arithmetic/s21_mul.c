#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  *result = s21_decimal_zero();

  int sign_1 = sign(value_1);
  int sign_2 = sign(value_2);
  int result_sign = sign_1 ^ sign_2;

  int scale_1 = power(value_1);
  int scale_2 = power(value_2);
  int result_scale = scale_1 + scale_2;

  s21_BIG_decimal big_value_1 = {0}, big_value_2 = {0}, big_result = {0};
  decimal_to_big(value_1, &big_value_1);
  decimal_to_big(value_2, &big_value_2);

  for (int i = 0; i < 96; i++) {
    if (get_BIG_bit(big_value_2, i)) {
      s21_BIG_decimal temp = big_value_1;
      shift_left_big(&temp, i);
      add_big_decimals(big_result, temp, &big_result);
    }
  }
  int error_code =
      big_to_decimal(big_result, result, &result_scale, result_sign);

  if (error_code == 0) {
    set_sign(result, result_sign);
    set_scale(result, result_scale);
  }

  return error_code;
}