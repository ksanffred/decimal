#include "../s21_decimal.h"

int s21_is_less_or_equal(s21_decimal leftOp, s21_decimal rightOp) {
  return s21_is_less(leftOp, rightOp) || s21_is_equal(leftOp, rightOp);
}
