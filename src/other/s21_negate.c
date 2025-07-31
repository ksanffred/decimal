#include "./../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int ret = 0;
  if (!result)
    ret = ERROR;
  else {
    changing_sign(&value);
    *result = value;
  }
  return ret;
}