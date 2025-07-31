#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int success = OK;

  if (!dst) {
    success = ERROR;
  } else {
    *dst = s21_decimal_zero();  // set to NULL
    int sign = POSITIVE;
    if (src < 0) {
      sign = NEGATIVE;
      if (src != INT_MIN) {
        // except minimal int value to avoid overflow.
        // -2147483648 has no positive equivalent
        // because 2147483648 exceeds int's max (2147483647)
        src = -src;
      }
    }
    dst->bits[0] = src;
    dst->bits[3] |= sign << 31;
  }
  return success;
}
