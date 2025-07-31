#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int truncate = OK;
  if (!result) {
    truncate = ERROR;
  } else {
    *result = value;
    int scale = power(value);

    for (int i = 0; i < scale; i++) {
      div_ten_signed(result);
    }

    result->bits[3] &= 0x80000000;
  }
  return truncate;
}