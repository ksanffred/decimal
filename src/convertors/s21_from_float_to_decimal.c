#include "../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int ret = 0;
  float_bit fbsrc = {*((int *)&src)};
  decimal_bit3 dst3 = {0};
  if (fbsrc.parts.scale != 255) {
    long number = 0;
    if (src < 0) dst3.parts.sign = 1;
    int index = fbsrc.parts.scale - 127;
    int full = fbsrc.parts.mantis | (1 << 23);
    long before = 0;
    long power = 1;
    for (int i = 23 - index; i <= 24; i++) {
      int pos = i >= 0 ? (full >> i) & 1 : 0;
      before += pos * power;
      power *= 2;
    }
    number = before * 100000000;
    int k = 1;
    for (int i = 22 - index; i >= 0; i--) {
      int pos = i < 24 ? (full >> i) & 1 : 0;
      if (pos) number += two_minus_pow(k);
      k++;
    }
    if (number % 10 > 5) number += 10;
    for (int i = 0; i < 8; i++) {
      number /= 10;
      if (number % 10 != 0) {
        dst3.parts.scale = 7 - i;
        break;
      }
    }
    for (int i = 0; i < 64; i++) {
      dst->bits[i / 32] |= ((number >> i) & 1) << i % 32;
    }
    dst->bits[3] = dst3.i;
    if (src != 0 && is_zero(*dst) == 0) ret = 1;
  } else
    ret = 1;
  return ret;
}
