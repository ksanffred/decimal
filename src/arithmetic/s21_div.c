#include "../s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = 0;

  if (!is_zero(value_2)) {
    error = 3;
  } else if (result != NULL) {
    int scale_1 = get_scale_decimal(value_1);
    int scale_2 = get_scale_decimal(value_2);

    s21_BIG_decimal big_1 = {0};
    s21_BIG_decimal big_2 = {0};
    decimal_to_big(value_1, &big_1);
    decimal_to_big(value_2, &big_2);

    int diff_scale = (int)scale_1 - (int)scale_2;

    if (diff_scale > 0) {
      scale_1 = (int)diff_scale;
      scale_2 = 0;
    } else if (diff_scale == 0) {
      scale_1 = 0;
      scale_2 = 0;
    } else if (diff_scale < 0) {
      scale_1 = 0;
      mul_ten_n_times_big(&big_1, -diff_scale);
      scale_2 = 0;
    }

    s21_BIG_decimal big_result = {0};
    int scale_result =
        division_with_remainder(big_1, scale_1, big_2, &big_result);

    int result_sign = sign(value_1) ^ sign(value_2);

    error = big_to_decimal(big_result, result, &scale_result, result_sign);
  }
  return error;
}
