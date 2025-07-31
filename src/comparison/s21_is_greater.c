#include "../s21_decimal.h"

int s21_is_greater(s21_decimal leftOp, s21_decimal rightOp) {
  return s21_is_less(rightOp, leftOp);
}
