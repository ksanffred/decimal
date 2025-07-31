#include "../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int ret = 0;
  int extr = 0;
  if (is_zero(value_1) == 0) value_1.bits[3] = 0;
  if (is_zero(value_2) == 0) value_2.bits[3] = 0;
  s21_BIG_decimal temp = {{0, 0, 0, 0, 0}};
  if (sign(value_1) != sign(value_2)) {
    changing_sign(&value_2);
    ret = s21_sub(value_1, value_2, result);
  } else {
    if (normalization(&value_1, &value_2) != 0) {
      anti_normalization(&value_1, &value_2);
    }
    for (int i = 0; i < 97; i++) {
      int res = get_bit(value_1, i) + get_bit(value_2, i) + extr;
      temp.bits[i / 32] |= (res & 1) << i % 32;
      extr = res >> 1;
    }
    if (temp.bits[3] == 0) {
      result->bits[3] = value_1.bits[3];
      for (int i = 0; i < 3; i++) {
        result->bits[i] = temp.bits[i];
      }
    } else
      ret = 1;
    if (sign(value_1) == 1 && ret == 1) ret = 2;
    if (is_zero(*result) == 0) result->bits[3] = 0;
  }
  return ret;
}
