#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int success = OK;

  if (!dst) {
    success = ERROR;
  } else {
    *dst = 0;
    s21_decimal temp = src;

    if (power(src) > 0) {
      s21_truncate(src, &temp);
    }

    s21_decimal int_min_decimal, int_max_decimal;
    s21_from_int_to_decimal(INT_MIN, &int_min_decimal);
    s21_from_int_to_decimal(INT_MAX, &int_max_decimal);

    if (s21_is_less(temp, int_min_decimal) == TRUE) {
      success = ERROR;
    } else if (s21_is_greater(temp, int_max_decimal) == TRUE) {
      success = ERROR;
    } else {
      for (int bitIndex = 0; bitIndex < 96; bitIndex++) {
        if (get_bit(temp, bitIndex)) {
          *dst += pow(2, bitIndex);
        }
      }
      if (sign(src) == NEGATIVE) {
        *dst *= -1;
      }
    }
  }
  return success;
}