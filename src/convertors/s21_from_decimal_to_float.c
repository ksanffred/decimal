#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int success = OK;

  if (!dst) {
    success = ERROR;
  } else {
    *dst = 0;
    double tmp = 0.0;

    for (int i = 0; i < 96; i++) {
      if (get_bit(src, i) != 0) {
        tmp += pow(2.0, i);
      }
    }
    int scale = power(src);
    tmp /= pow(10.0, scale);
    *dst = (float)tmp;

    if (sign(src) == NEGATIVE) {
      *dst *= -1;
    }
  }
  return success;
}
