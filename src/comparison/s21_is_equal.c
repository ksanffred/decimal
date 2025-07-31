#include "../s21_decimal.h"

int s21_is_equal(s21_decimal leftOp, s21_decimal rightOp) {
  int isEqual = TRUE;

  int leftIsZero =
      (leftOp.bits[0] == 0 && leftOp.bits[1] == 0 && leftOp.bits[2] == 0);
  int rightIsZero =
      (rightOp.bits[0] == 0 && rightOp.bits[1] == 0 && rightOp.bits[2] == 0);

  if (leftIsZero && rightIsZero) {
    isEqual = TRUE;
  } else {
    normalization(&leftOp, &rightOp);
    for (int bitsIndex = 0; bitsIndex < 4; bitsIndex++) {
      if (leftOp.bits[bitsIndex] != rightOp.bits[bitsIndex]) {
        isEqual = FALSE;
      }
    }
  }
  return isEqual;
}
