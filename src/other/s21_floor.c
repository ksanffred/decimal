#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  if (!is_zero(value) && sign(value)) changing_sign(&value);

  s21_truncate(value, result);
  if (s21_is_equal(*result, value) == 0) {
    if ((sign(value) == NEGATIVE && value.bits[3] & 0x00FF0000) != 0) {
      s21_sub(*result, ((s21_decimal){{1, 0, 0, 0}}), result);
    }
  }
  return 0;
}
