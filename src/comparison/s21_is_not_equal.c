#include "../s21_decimal.h"

int s21_is_not_equal(s21_decimal leftOp, s21_decimal rightOp) {
  return !s21_is_equal(leftOp, rightOp);
}