#include "../s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int ret;
  if (is_zero(value_1) == 0) value_1.bits[3] = 0;
  if (is_zero(value_2) == 0) value_2.bits[3] = 0;
  int min1 = sign(value_1);
  int min2 = sign(value_2);
  if (min1 == min2) {
    int norm = normalization(&value_1, &value_2);
    if (norm == 0) {
      int i = 2;
      while (i > 0 && value_1.bits[i] == value_2.bits[i]) {
        i--;
      }
      ret = (unsigned)value_1.bits[i] < (unsigned)value_2.bits[i];
      if (min1 == 1 && value_1.bits[i] != value_2.bits[i]) ret = !ret;
    } else
      ret = norm == 2;
  } else
    ret = min1 == 1;
  return ret;
}