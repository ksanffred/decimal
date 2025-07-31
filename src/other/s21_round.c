#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  if (!is_zero(value) && sign(value)) changing_sign(&value);

  if ((value.bits[3] & 0x00FF0000) != 0) {
    if (sign(value))
      s21_sub(value, ((s21_decimal){{5, 0, 0, 65536}}), &value);
    else
      s21_add(value, ((s21_decimal){{5, 0, 0, 65536}}), &value);
    s21_truncate(value, result);
  } else {
    *result = value;
  }
  return 0;
}