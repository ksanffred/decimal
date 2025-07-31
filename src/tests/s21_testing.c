#include <check.h>

#include "../s21_decimal.h"

// ADD

START_TEST(s21_add_zero_plus) {
  s21_decimal first = {{0, 0, 0, 0}};
  s21_decimal second = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};

  int res = s21_add(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_add_zero_minus_plus) {
  s21_decimal first = {{0, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal second = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};

  int res = s21_add(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_add_zero_minus) {
  s21_decimal first = {{0, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal second = {{0, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};

  int res = s21_add(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_add_normal1) {
  s21_decimal first = {{121, 0, 0, 0}};
  s21_decimal second = {{21, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{142, 0, 0, 0}};

  int res = s21_add(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_add_normal12) {
  s21_decimal first = {{1591992803, 546042, 0, 0}};
  s21_decimal second = {{1874919424, 2328306, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{-828055069, 2874348, 0, 0}};

  int res = s21_add(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_add_normal123) {
  s21_decimal first = {{-1593835520, 466537709, 54210, 0}};
  s21_decimal second = {{-1593835520, 466537709, 54210, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{1107296256, 933075419, 108420, 0}};

  int res = s21_add(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_add_normal123_minus1) {
  s21_decimal first = {{-1593835520, 466537709, 54210, 0}};
  s21_decimal second = {{-1593835520, 466537709, 54210, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.sign = 1;
  first.bits[3] = f.i;

  int res = s21_add(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_add_normal123_minus2) {
  s21_decimal first = {{-1593835520, 466537709, 54210, 0}};
  s21_decimal second = {{-1593835520, 466537709, 54210, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.sign = 1;
  second.bits[3] = f.i;

  int res = s21_add(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_add_normal123_minus12) {
  s21_decimal first = {{-1593835520, 466537709, 54210, 0}};
  s21_decimal second = {{-1593835520, 466537709, 54210, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{1107296256, 933075419, 108420, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.sign = 1;
  first.bits[3] = f.i;
  second.bits[3] = f.i;
  expected.bits[3] = f.i;

  int res = s21_add(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_add_normal123_minus_res) {
  s21_decimal first = {{0, 0, 0, 0}};
  s21_decimal second = {{-1593835520, 466537709, 54210, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{-1593835520, 466537709, 54210, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.sign = 1;
  second.bits[3] = f.i;
  expected.bits[3] = f.i;

  int res = s21_add(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_add_float) {
  s21_decimal first = {{1234, 0, 0, 0}};
  s21_decimal second = {{1266, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{2500, 0, 0, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.scale = 2;
  first.bits[3] = f.i;
  second.bits[3] = f.i;
  expected.bits[3] = f.i;

  int res = s21_add(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_add_float_dif) {
  s21_decimal first = {{1234, 0, 0, 0}};
  s21_decimal second = {{1266, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{13606, 0, 0, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.scale = 2;
  first.bits[3] = f.i;
  f.parts.scale = 3;
  second.bits[3] = f.i;
  expected.bits[3] = f.i;

  int res = s21_add(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_add_float_dif3) {
  s21_decimal first = {{1234, 0, 0, 0}};
  s21_decimal second = {{1266, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{13606, 0, 0, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.scale = 22;
  first.bits[3] = f.i;
  f.parts.scale = 23;
  second.bits[3] = f.i;
  expected.bits[3] = f.i;

  int res = s21_add(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_add_toobig) {
  s21_decimal first = {{0, 0, -1, 0}};
  s21_decimal second = {{0, 0, -1, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};

  int res = s21_add(first, second, &result);
  int exp = 1;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_add_toosmall) {
  s21_decimal first = {{0, 0, -1, 0}};
  s21_decimal second = {{0, 0, -1, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.sign = 1;
  first.bits[3] = f.i;
  second.bits[3] = f.i;

  int res = s21_add(first, second, &result);
  int exp = 2;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_add_max) {
  s21_decimal first = {{-1, -1, -1, 0}};
  s21_decimal second = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{-1, -1, -1, 0}};

  int res = s21_add(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_add_bank) {
  s21_decimal first = {{-1, -1, -1, 0}};
  s21_decimal second = {{6, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{-2, -1, -1, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.scale = 1;
  f.parts.sign = 1;
  second.bits[3] = f.i;

  int res = s21_add(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_add_mantis_bank) {
  s21_decimal first = {{-336, -1, -1, 0}};
  s21_decimal second = {{3346, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{-1, -1, -1, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.scale = 3;
  first.bits[3] = f.i;
  expected.bits[3] = f.i;
  f.parts.scale = 4;
  second.bits[3] = f.i;

  int res = s21_add(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_add_mantis_nobank) {
  s21_decimal first = {{-336, -1, -1, 0}};
  s21_decimal second = {{3345, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{-2, -1, -1, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.scale = 3;
  first.bits[3] = f.i;
  expected.bits[3] = f.i;
  f.parts.scale = 4;
  second.bits[3] = f.i;

  int res = s21_add(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// SUB

START_TEST(s21_sub_zero_plus) {
  s21_decimal first = {{0, 0, 0, 0}};
  s21_decimal second = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};

  int res = s21_sub(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_sub_zero_minus_plus) {
  s21_decimal first = {{0, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal second = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};

  int res = s21_sub(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_sub_zero_minus) {
  s21_decimal first = {{0, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal second = {{0, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};

  int res = s21_sub(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_sub_normal1) {
  s21_decimal first = {{121, 0, 0, 0}};
  s21_decimal second = {{21, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{100, 0, 0, 0}};

  int res = s21_sub(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_sub_normal12) {
  s21_decimal first = {{-828055069, 2874348, 0, 0}};
  s21_decimal second = {{1874919424, 2328306, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{1591992803, 546042, 0, 0}};

  int res = s21_sub(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_sub_normal123) {
  s21_decimal first = {{1107296256, 933075419, 108420, 0}};
  s21_decimal second = {{-1593835520, 466537709, 54210, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{-1593835520, 466537709, 54210, 0}};

  int res = s21_sub(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_sub_normal123_minus1) {
  s21_decimal first = {{-1593835520, 466537709, 54210, 0}};
  s21_decimal second = {{-1593835520, 466537709, 54210, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{1107296256, 933075419, 108420, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.sign = 1;
  first.bits[3] = f.i;
  expected.bits[3] = f.i;

  int res = s21_sub(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_sub_normal123_minus2) {
  s21_decimal first = {{-1593835520, 466537709, 54210, 0}};
  s21_decimal second = {{-1593835520, 466537709, 54210, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{1107296256, 933075419, 108420, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.sign = 1;
  second.bits[3] = f.i;

  int res = s21_sub(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_sub_normal123_minus12) {
  s21_decimal first = {{-1593835520, 466537709, 54210, 0}};
  s21_decimal second = {{-1593835520, 466537709, 54210, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.sign = 1;
  first.bits[3] = f.i;
  second.bits[3] = f.i;

  int res = s21_sub(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_sub_normal123_minus_res) {
  s21_decimal first = {{0, 0, 0, 0}};
  s21_decimal second = {{-1593835520, 466537709, 54210, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{-1593835520, 466537709, 54210, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.sign = 1;
  second.bits[3] = f.i;

  int res = s21_sub(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_sub_float) {
  s21_decimal first = {{1266, 0, 0, 0}};
  s21_decimal second = {{1211, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{55, 0, 0, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.scale = 2;
  first.bits[3] = f.i;
  second.bits[3] = f.i;
  expected.bits[3] = f.i;

  int res = s21_sub(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_sub_float_dif) {
  s21_decimal first = {{12345, 0, 0, 0}};
  s21_decimal second = {{1234, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{122216, 0, 0, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.scale = 2;
  first.bits[3] = f.i;
  f.parts.scale = 3;
  second.bits[3] = f.i;
  expected.bits[3] = f.i;

  int res = s21_sub(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_sub_float_dif3) {
  s21_decimal first = {{12345, 0, 0, 0}};
  s21_decimal second = {{1234, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{122216, 0, 0, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.scale = 22;
  first.bits[3] = f.i;
  f.parts.scale = 23;
  second.bits[3] = f.i;
  expected.bits[3] = f.i;

  int res = s21_sub(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_sub_toobig) {
  s21_decimal first = {{0, 0, -1, 0}};
  s21_decimal second = {{0, 0, -1, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.sign = 1;
  second.bits[3] = f.i;

  int res = s21_sub(first, second, &result);
  int exp = 1;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_sub_toosmall) {
  s21_decimal first = {{0, 0, -1, 0}};
  s21_decimal second = {{0, 0, -1, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.sign = 1;
  first.bits[3] = f.i;

  int res = s21_sub(first, second, &result);
  int exp = 2;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_sub_max) {
  s21_decimal first = {{-1, -1, -1, 0}};
  s21_decimal second = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{-1, -1, -1, 0}};

  int res = s21_sub(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_sub_bank) {
  s21_decimal first = {{-1, -1, -1, 0}};
  s21_decimal second = {{6, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{-2, -1, -1, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.scale = 1;
  second.bits[3] = f.i;

  int res = s21_sub(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_sub_mantis_bank) {
  s21_decimal first = {{-1, -1, -1, 0}};
  s21_decimal second = {{3346, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{-336, -1, -1, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.scale = 3;
  first.bits[3] = f.i;
  expected.bits[3] = f.i;
  f.parts.scale = 4;
  second.bits[3] = f.i;

  int res = s21_sub(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_sub_mantis_nobank) {
  s21_decimal first = {{-2, -1, -1, 0}};
  s21_decimal second = {{3345, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{-336, -1, -1, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.scale = 3;
  first.bits[3] = f.i;
  expected.bits[3] = f.i;
  f.parts.scale = 4;
  second.bits[3] = f.i;

  int res = s21_sub(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// IS LESS

START_TEST(s21_is_less_zero) {
  s21_decimal first = {{0, 0, 0, 0}};
  s21_decimal second = {{0, 0, 0, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.sign = 1;
  first.bits[3] = f.i;

  ck_assert_int_eq(s21_is_less(first, second), 0);
  second.bits[3] = f.i;
  ck_assert_int_eq(s21_is_less(first, second), 0);
  f.parts.sign = 0;
  first.bits[3] = f.i;
  ck_assert_int_eq(s21_is_less(first, second), 0);
}
END_TEST

START_TEST(s21_is_less_normal) {
  s21_decimal first = {{21, 0, 0, 0}};
  s21_decimal second = {{42, 0, 0, 0}};

  ck_assert_int_eq(s21_is_less(first, second), 1);
  ck_assert_int_eq(s21_is_less(second, first), 0);
}
END_TEST

START_TEST(s21_is_less_normal1) {
  s21_decimal first = {{21, 0, 0, 0}};
  s21_decimal second = {{42, 0, 0, 0}};

  ck_assert_int_eq(s21_is_less(first, second), 1);
  ck_assert_int_eq(s21_is_less(second, first), 0);
}
END_TEST

START_TEST(s21_is_less_normal12) {
  s21_decimal first = {{21, 21, 0, 0}};
  s21_decimal second = {{21, 42, 0, 0}};

  ck_assert_int_eq(s21_is_less(first, second), 1);
  ck_assert_int_eq(s21_is_less(second, first), 0);
}
END_TEST

START_TEST(s21_is_less_normal123) {
  s21_decimal first = {{21, 21, 21, 0}};
  s21_decimal second = {{21, 21, 42, 0}};

  ck_assert_int_eq(s21_is_less(first, second), 1);
  ck_assert_int_eq(s21_is_less(second, first), 0);
}
END_TEST

START_TEST(s21_is_less_sign) {
  s21_decimal first = {{21, 0, 0, 0}};
  s21_decimal second = {{21, 0, 0, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.sign = 1;
  first.bits[3] = f.i;

  ck_assert_int_eq(s21_is_less(first, second), 1);
  second.bits[3] = f.i;
  ck_assert_int_eq(s21_is_less(first, second), 0);
  f.parts.sign = 0;
  first.bits[3] = f.i;
  ck_assert_int_eq(s21_is_less(first, second), 0);
}
END_TEST

START_TEST(s21_is_less_float) {
  s21_decimal first = {{21, 0, 0, 0}};
  s21_decimal second = {{21, 0, 0, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.scale = 1;
  first.bits[3] = f.i;

  ck_assert_int_eq(s21_is_less(first, second), 1);
  second.bits[3] = f.i;
  ck_assert_int_eq(s21_is_less(first, second), 0);
  f.parts.scale = 2;
  first.bits[3] = f.i;
  ck_assert_int_eq(s21_is_less(first, second), 1);
}
END_TEST

START_TEST(s21_is_less_float123) {
  s21_decimal first = {{21, 21, 21, 0}};
  s21_decimal second = {{21, 21, 42, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.scale = 20;
  second.bits[3] = f.i;

  ck_assert_int_eq(s21_is_less(first, second), 0);
  first.bits[3] = f.i;
  ck_assert_int_eq(s21_is_less(first, second), 1);
}
END_TEST

// IS GREATER OR EQUEL

START_TEST(s21_is_greater_or_equal_zero) {
  s21_decimal first = {{0, 0, 0, 0}};
  s21_decimal second = {{0, 0, 0, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.sign = 1;
  first.bits[3] = f.i;

  ck_assert_int_eq(s21_is_greater_or_equal(first, second), 1);
  second.bits[3] = f.i;
  ck_assert_int_eq(s21_is_greater_or_equal(first, second), 1);
  f.parts.sign = 0;
  first.bits[3] = f.i;
  ck_assert_int_eq(s21_is_greater_or_equal(first, second), 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_normal) {
  s21_decimal first = {{21, 0, 0, 0}};
  s21_decimal second = {{42, 0, 0, 0}};

  ck_assert_int_eq(s21_is_greater_or_equal(first, second), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(second, first), 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_normal1) {
  s21_decimal first = {{21, 0, 0, 0}};
  s21_decimal second = {{42, 0, 0, 0}};

  ck_assert_int_eq(s21_is_greater_or_equal(first, second), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(second, first), 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_normal12) {
  s21_decimal first = {{21, 21, 0, 0}};
  s21_decimal second = {{21, 42, 0, 0}};

  ck_assert_int_eq(s21_is_greater_or_equal(first, second), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(second, first), 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_normal123) {
  s21_decimal first = {{21, 21, 21, 0}};
  s21_decimal second = {{21, 21, 42, 0}};

  ck_assert_int_eq(s21_is_greater_or_equal(first, second), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(second, first), 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_sign) {
  s21_decimal first = {{21, 0, 0, 0}};
  s21_decimal second = {{21, 0, 0, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.sign = 1;
  first.bits[3] = f.i;

  ck_assert_int_eq(s21_is_greater_or_equal(first, second), 0);
  second.bits[3] = f.i;
  ck_assert_int_eq(s21_is_greater_or_equal(first, second), 1);
  f.parts.sign = 0;
  first.bits[3] = f.i;
  ck_assert_int_eq(s21_is_greater_or_equal(first, second), 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_float) {
  s21_decimal first = {{21, 0, 0, 0}};
  s21_decimal second = {{21, 0, 0, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.scale = 1;
  first.bits[3] = f.i;

  ck_assert_int_eq(s21_is_greater_or_equal(first, second), 0);
  second.bits[3] = f.i;
  ck_assert_int_eq(s21_is_greater_or_equal(first, second), 1);
  f.parts.scale = 2;
  first.bits[3] = f.i;
  ck_assert_int_eq(s21_is_greater_or_equal(first, second), 0);
}
END_TEST

START_TEST(s21_is_greater_or_equal_float123) {
  s21_decimal first = {{21, 21, 21, 0}};
  s21_decimal second = {{21, 21, 42, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.scale = 20;
  second.bits[3] = f.i;

  ck_assert_int_eq(s21_is_greater_or_equal(first, second), 1);
  first.bits[3] = f.i;
  ck_assert_int_eq(s21_is_greater_or_equal(first, second), 0);
}
END_TEST

// FROM FLOAT TO DECIMAL

START_TEST(s21_from_float_to_decimal_normal1) {
  float num = 21.25;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{2125, 0, 0, 0}};
  decimal_bit3 bit3 = {0};
  bit3.parts.scale = 2;
  expected.bits[3] = bit3.i;

  int res = s21_from_float_to_decimal(num, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_from_float_to_decimal_normal12) {
  float num = 100000.0234375;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{-727145593, 232, 0, 0}};
  decimal_bit3 bit3 = {0};
  bit3.parts.scale = 7;
  expected.bits[3] = bit3.i;

  int res = s21_from_float_to_decimal(num, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_from_float_to_decimal_normal12_minus) {
  float num = -100000.0234375;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{-727145593, 232, 0, 0}};
  decimal_bit3 bit3 = {0};
  bit3.parts.scale = 7;
  bit3.parts.sign = 1;
  expected.bits[3] = bit3.i;

  int res = s21_from_float_to_decimal(num, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_from_float_to_decimal_zero) {
  float num = 0;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_from_float_to_decimal_after_only) {
  float num = 0.02;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{199999, 0, 0, 0}};
  decimal_bit3 bit3 = {0};
  bit3.parts.scale = 7;
  expected.bits[3] = bit3.i;

  int res = s21_from_float_to_decimal(num, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_from_float_to_decimal_before_only) {
  float num = 4221;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{4221, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_from_float_to_decimal_inf) {
  float_bit infi;
  infi.parts.mantis = 0;
  infi.parts.scale = 0b11111111;
  infi.parts.sign = 0;
  float num = *((float *)&infi.i);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &result);
  int exp = 1;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_from_float_to_decimal_infminus) {
  float_bit infi;
  infi.parts.mantis = 0;
  infi.parts.scale = 0b11111111;
  infi.parts.sign = 1;
  float num = *((float *)&infi.i);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &result);
  int exp = 1;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_from_float_to_decimal_nan) {
  float_bit infi;
  infi.parts.mantis = 21;
  infi.parts.scale = 0b11111111;
  infi.parts.sign = 1;
  float num = *((float *)&infi.i);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &result);
  int exp = 1;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_from_float_to_decimal_small) {
  float num = 0.0000034;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{34, 0, 0, 0}};
  decimal_bit3 bit3 = {0};
  bit3.parts.scale = 7;
  expected.bits[3] = bit3.i;

  int res = s21_from_float_to_decimal(num, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

START_TEST(s21_from_float_to_decimal_toosmall) {
  float num = 0.000000034;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &result);
  int exp = 1;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// NEGATE

START_TEST(negate_testing) {
  s21_decimal value1_src = {{1, 2, 3, 0}};
  s21_decimal value1_res = {{1, 2, 3, 0}};
  int sign_before_value1 = sign(value1_src);
  s21_negate(value1_src, &value1_res);
  int sign_after_value1 = sign(value1_res);
  ck_assert_int_ne(sign_before_value1, sign_after_value1);

  s21_decimal value2_src = {{1, 2, 3, (1 << 31)}};
  s21_decimal value2_res = {{1, 2, 3, (1 << 31)}};
  int sign_before_value2 = sign(value2_src);
  s21_negate(value2_src, &value2_res);
  int sign_after_value2 = sign(value2_res);
  ck_assert_int_ne(sign_before_value2, sign_after_value2);

  s21_decimal value3_src = {{5, 1, 2, 0}};
  s21_decimal value3_res = {{5, 1, 2, 0}};
  changing_power(&value3_src, 14);
  int sign_before_value3 = sign(value3_src);
  s21_negate(value3_src, &value3_res);
  int sign_after_value3 = sign(value3_res);
  ck_assert_int_ne(sign_before_value3, sign_after_value3);
  ck_assert_int_eq(14, power(value3_res));

  s21_decimal value4_src = {{11, 22, 33, (1 << 31)}};
  s21_decimal value4_res = {{11, 22, 33, (1 << 31)}};
  changing_power(&value4_src, 7);
  int sign_before_value4 = sign(value4_src);
  s21_negate(value4_src, &value4_res);
  int sign_after_value4 = sign(value4_res);
  ck_assert_int_ne(sign_before_value4, sign_after_value4);
  ck_assert_int_eq(7, power(value4_res));

  s21_decimal value5_src = {{0, 0, 0, 0}};
  s21_decimal value5_res = {{0, 0, 0, 0}};
  int sign_before_value5 = sign(value5_src);
  s21_negate(value5_src, &value5_res);
  int sign_after_value5 = sign(value5_res);
  ck_assert_int_ne(sign_before_value5, sign_after_value5);
}
END_TEST

// TRUNCATE

START_TEST(truncate_testing) {
  s21_decimal result;
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal corr1 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_truncate(value1, &result), OK);
  for (int i = 0; i <= 3; i++) {
    ck_assert_int_eq(result.bits[i], corr1.bits[i]);
  }

  s21_decimal value2 = {{123, 45678, 1, 0}};
  s21_decimal corr2 = {{123, 45678, 1, 0}};
  ck_assert_int_eq(s21_truncate(value2, &result), OK);
  for (int i = 0; i <= 3; i++) {
    ck_assert_int_eq(result.bits[i], corr2.bits[i]);
  }

  s21_decimal value3 = {{1230, 4567800, 100, 0}};
  changing_power(&value3, 2);
  s21_decimal corr3 = {{12, 45678, 1, 0}};
  changing_power(&corr3, 0);
  ck_assert_int_eq(s21_truncate(value3, &result), OK);
  for (int i = 0; i <= 3; i++) {
    ck_assert_int_eq(result.bits[i], corr3.bits[i]);
  }

  s21_decimal value4 = {{0, 0, 0, (1 << 31)}};
  s21_decimal corr4 = {{0, 0, 0, (1 << 31)}};
  changing_power(&value4, 28);
  changing_power(&corr4, 0);
  ck_assert_int_eq(s21_truncate(value4, &result), OK);
  for (int i = 0; i <= 3; i++) {
    ck_assert_int_eq(result.bits[i], corr4.bits[i]);
  }

  s21_decimal value5 = {{123, 45600, 100, (1 << 31)}};
  s21_decimal corr5 = {{1, 456, 1, (1 << 31)}};
  changing_power(&value5, 2);
  changing_power(&corr5, 0);
  ck_assert_int_eq(s21_truncate(value5, &result), OK);
  for (int i = 0; i <= 3; i++) {
    ck_assert_int_eq(result.bits[i], corr5.bits[i]);
  }

  s21_decimal value6 = {{12300, 4567800, 100, 0}};
  s21_decimal corr6 = {{1230, 456780, 10, 0}};
  changing_power(&value6, 1);
  changing_power(&corr6, 0);
  ck_assert_int_eq(s21_truncate(value6, &result), OK);
  for (int i = 0; i <= 3; i++) {
    ck_assert_int_eq(result.bits[i], corr6.bits[i]);
  }

  s21_decimal value7 = {{1, 0, 0, (1 << 31)}};
  s21_decimal corr7 = {{0, 0, 0, (1 << 31)}};
  changing_power(&value7, 28);
  changing_power(&corr7, 0);
  ck_assert_int_eq(s21_truncate(value7, &result), OK);
  for (int i = 0; i <= 3; i++) {
    ck_assert_int_eq(result.bits[i], corr7.bits[i]);
  }

  s21_decimal value8 = {{300000000, 0, 0, (1 << 31)}};
  s21_decimal corr8 = {{0, 0, 0, (1 << 31)}};
  changing_power(&value8, 11);
  changing_power(&corr8, 0);
  ck_assert_int_eq(s21_truncate(value8, &result), OK);
  for (int i = 0; i <= 3; i++) {
    ck_assert_int_eq(result.bits[i], corr8.bits[i]);
  }
}
END_TEST

// ROUND

START_TEST(round_testing) {
  s21_decimal result;
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal corr1 = {{0, 0, 0, 0}};
  changing_power(&value1, 0);
  changing_power(&corr1, 0);
  ck_assert_int_eq(s21_round(value1, &result), OK);
  for (int i = 0; i <= 3; i++) {
    ck_assert_int_eq(result.bits[i], corr1.bits[i]);
  }

  s21_decimal value2 = {{123, 45678, 1, 0}};
  s21_decimal corr2 = {{123, 45678, 1, 0}};
  changing_power(&value2, 0);
  changing_power(&corr2, 0);
  ck_assert_int_eq(s21_round(value2, &result), OK);
  for (int i = 0; i <= 3; i++) {
    ck_assert_int_eq(result.bits[i], corr2.bits[i]);
  }

  s21_decimal value3 = {{1230, 456780, 10, 0}};
  s21_decimal corr3 = {{123, 45678, 1, 0}};
  changing_power(&value3, 1);
  changing_power(&corr3, 0);
  ck_assert_int_eq(s21_round(value3, &result), OK);
  for (int i = 0; i <= 3; i++) {
    ck_assert_int_eq(result.bits[i], corr3.bits[i]);
  }

  s21_decimal value4 = {{0, 0, 0, (1 << 31)}};
  s21_decimal corr4 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_round(value4, &result), OK);
  ck_assert_int_eq(result.bits[0], corr4.bits[0]);
  ck_assert_int_eq(result.bits[1], corr4.bits[1]);
  ck_assert_int_eq(result.bits[2], corr4.bits[2]);
  ck_assert_int_eq(result.bits[3], corr4.bits[3]);

  s21_decimal value5 = {{123, 45678, 1, (1 << 31)}};
  s21_decimal corr5 = {{123, 45678, 1, (1 << 31)}};
  ck_assert_int_eq(s21_round(value5, &result), OK);
  for (int i = 0; i <= 3; i++) {
    ck_assert_int_eq(result.bits[i], corr5.bits[i]);
  }

  s21_decimal value6 = {{1230, 456780, 10, (1 << 31)}};
  s21_decimal corr6 = {{123, 45678, 1, (1 << 31)}};
  changing_power(&value6, 1);
  changing_power(&corr6, 0);
  ck_assert_int_eq(s21_round(value6, &result), OK);
  for (int i = 0; i <= 3; i++) {
    ck_assert_int_eq(result.bits[i], corr6.bits[i]);
  }

  s21_decimal value7 = {{1235, 456780, 10, 0}};
  s21_decimal corr7 = {{124, 45678, 1, 0}};
  changing_power(&value7, 1);
  changing_power(&corr7, 0);
  ck_assert_int_eq(s21_round(value7, &result), OK);
  for (int i = 0; i <= 3; i++) {
    ck_assert_int_eq(result.bits[i], corr7.bits[i]);
  }

  s21_decimal value8 = {{1235, 456780, 10, (1 << 31)}};
  s21_decimal corr8 = {{124, 45678, 1, (1 << 31)}};
  changing_power(&value8, 1);
  changing_power(&corr8, 0);
  ck_assert_int_eq(s21_round(value8, &result), OK);
  for (int i = 0; i <= 3; i++) {
    ck_assert_int_eq(result.bits[i], corr8.bits[i]);
  }

  s21_decimal value9 = {{1, 0, 0, (1 << 31)}};
  s21_decimal corr9 = {{0, 0, 0, (1 << 31)}};
  changing_power(&value9, 28);
  changing_power(&corr9, 0);
  ck_assert_int_eq(s21_round(value9, &result), OK);
  for (int i = 0; i <= 3; i++) {
    ck_assert_int_eq(result.bits[i], corr9.bits[i]);
  }

  s21_decimal value10 = {{300000000, 0, 0, (1 << 31)}};
  s21_decimal corr10 = {{30000, 0, 0, (1 << 31)}};
  changing_power(&value10, 4);
  changing_power(&corr10, 0);
  ck_assert_int_eq(s21_round(value10, &result), OK);
  for (int i = 0; i <= 3; i++) {
    ck_assert_int_eq(result.bits[i], corr10.bits[i]);
  }

  s21_decimal value11 = {{1234, 456780, 10, 0}};
  s21_decimal corr11 = {{123, 45678, 1, 0}};
  changing_power(&value11, 1);
  changing_power(&corr11, 0);
  ck_assert_int_eq(s21_round(value11, &result), OK);
  for (int i = 0; i <= 3; i++) {
    ck_assert_int_eq(result.bits[i], corr11.bits[i]);
  }

  s21_decimal value12 = {{1236, 456780, 10, 0}};
  s21_decimal corr12 = {{124, 45678, 1, 0}};
  changing_power(&value12, 1);
  changing_power(&corr12, 0);
  ck_assert_int_eq(s21_round(value12, &result), OK);
  for (int i = 0; i <= 3; i++) {
    ck_assert_int_eq(result.bits[i], corr12.bits[i]);
  }

  s21_decimal value13 = {{1234, 456780, 10, (1 << 31)}};
  s21_decimal corr13 = {{123, 45678, 1, (1 << 31)}};
  changing_power(&value13, 1);
  changing_power(&corr13, 0);
  ck_assert_int_eq(s21_round(value13, &result), OK);
  for (int i = 0; i <= 3; i++) {
    ck_assert_int_eq(result.bits[i], corr13.bits[i]);
  }

  s21_decimal value14 = {{1236, 456780, 10, (1 << 31)}};
  s21_decimal corr14 = {{124, 45678, 1, (1 << 31)}};
  changing_power(&value14, 1);
  changing_power(&corr14, 0);
  ck_assert_int_eq(s21_round(value14, &result), OK);
  for (int i = 0; i <= 3; i++) {
    ck_assert_int_eq(result.bits[i], corr14.bits[i]);
  }
}
END_TEST

// FLOOR

START_TEST(floor_testing) {
  s21_decimal result;
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal corr1 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_floor(value1, &result), OK);
  for (int i = 0; i <= 3; i++) {
    ck_assert_int_eq(result.bits[i], corr1.bits[i]);
  }

  s21_decimal value2 = {{123, 45678, 1, 0}};
  s21_decimal corr2 = {{123, 45678, 1, 0}};
  ck_assert_int_eq(s21_floor(value2, &result), OK);
  for (int i = 0; i <= 3; i++) {
    ck_assert_int_eq(result.bits[i], corr2.bits[i]);
  }

  s21_decimal value3 = {{1230, 456780, 10, 0}};
  changing_power(&value3, 1);
  s21_decimal corr3 = {{123, 45678, 1, 0}};
  changing_power(&corr3, 0);
  ck_assert_int_eq(s21_floor(value3, &result), OK);
  for (int i = 0; i <= 3; i++) {
    ck_assert_int_eq(result.bits[i], corr3.bits[i]);
  }

  s21_decimal value4 = {{0, 0, 0, (1 << 31)}};
  s21_decimal corr4 = {{0, 0, 0, 0}};
  changing_power(&value4, 0);
  changing_power(&corr4, 0);
  ck_assert_int_eq(s21_floor(value4, &result), OK);
  ck_assert_int_eq(result.bits[0], corr4.bits[0]);
  ck_assert_int_eq(result.bits[1], corr4.bits[1]);
  ck_assert_int_eq(result.bits[2], corr4.bits[2]);
  ck_assert_int_eq(result.bits[3], corr4.bits[3]);

  s21_decimal value5 = {{123, 45678, 1, (1 << 31)}};
  s21_decimal corr5 = {{123, 45678, 1, (1 << 31)}};
  changing_power(&value5, 0);
  changing_power(&corr5, 0);
  ck_assert_int_eq(s21_floor(value5, &result), OK);
  for (int i = 0; i <= 3; i++) {
    ck_assert_int_eq(result.bits[i], corr5.bits[i]);
  }

  // FAIL
  s21_decimal value6 = {{1230, 456780, 10, (1 << 31)}};
  changing_power(&value6, 1);
  s21_decimal corr6 = {{123, 45678, 1, (1 << 31)}};
  changing_power(&corr6, 0);
  ck_assert_int_eq(s21_floor(value6, &result), OK);
  for (int i = 0; i <= 3; i++) {
    ck_assert_int_eq(result.bits[i], corr6.bits[i]);
  }

  s21_decimal value7 = {{1235, 456780, 10, 0}};
  changing_power(&value7, 1);
  s21_decimal corr7 = {{123, 45678, 1, 0}};
  changing_power(&corr7, 0);
  ck_assert_int_eq(s21_floor(value7, &result), OK);
  for (int i = 0; i <= 3; i++) {
    ck_assert_int_eq(result.bits[i], corr7.bits[i]);
  }

  s21_decimal value8 = {{1235, 456780, 10, (1 << 31)}};
  changing_power(&value8, 1);
  s21_decimal corr8 = {{124, 45678, 1, (1 << 31)}};
  changing_power(&corr8, 0);
  ck_assert_int_eq(s21_floor(value8, &result), OK);
  for (int i = 0; i <= 3; i++) {
    ck_assert_int_eq(result.bits[i], corr8.bits[i]);
  }

  s21_decimal value9 = {{1, 0, 0, (1 << 31)}};
  changing_power(&value9, 28);
  s21_decimal corr9 = {{1, 0, 0, (1 << 31)}};
  changing_power(&corr9, 0);
  ck_assert_int_eq(s21_floor(value9, &result), OK);
  for (int i = 0; i <= 3; i++) {
    ck_assert_int_eq(result.bits[i], corr9.bits[i]);
  }

  // s21_decimal value11 = {{300000000, 0, 0, (1 << 31)}};
  // changing_power(&value11, 4);
  // s21_decimal corr11 = {{30000, 0, 0, (1 << 31)}};
  // changing_power(&corr11, 0);
  // ck_assert_int_eq(s21_floor(value11, &result), OK);
  // ck_assert_int_eq(result.bits[0], corr11.bits[0]);
  // ck_assert_int_eq(result.bits[1], corr11.bits[1]);
  // ck_assert_int_eq(result.bits[2], corr11.bits[2]);
  // ck_assert_int_eq(result.bits[3], corr11.bits[3]);

  // s21_decimal value11 = {{3000000000, 0, 0, (1 << 31)}};
  // changing_power(&value11, 35);
  // ck_assert_int_eq(s21_floor(value11, &result), ERROR);
}
END_TEST

// FROM_DECIMAL_TO_FLOAT

START_TEST(from_decimal_to_float_testing) {
  float result;
  s21_decimal value1 = {{0, 0, 0, 0}};
  changing_power(&value1, 0);
  ck_assert_int_eq(s21_from_decimal_to_float(value1, &result), OK);
  ck_assert_float_lt(fabs(result), 1e-7);

  s21_decimal value2 = {{25, 0, 0, 0}};
  changing_power(&value2, 0);
  ck_assert_int_eq(s21_from_decimal_to_float(value2, &result), OK);
  ck_assert_float_lt(fabs(result - 25), 1e-7);

  s21_decimal value3 = {{25, 0, 0, (1 << 31)}};
  changing_power(&value3, 0);
  ck_assert_int_eq(s21_from_decimal_to_float(value3, &result), OK);
  ck_assert_float_lt(fabs(result + 25), 1e-7);

  // работа с макс и мин значениями

  s21_decimal value4 = {{-1, -1, -1, 0}};
  changing_power(&value4, 0);
  ck_assert_int_eq(s21_from_decimal_to_float(value4, &result), OK);
  ck_assert_float_lt(fabs(result - 79228162514264337593543950335.0f), 1e+22);

  s21_decimal value5 = {{-1, -1, -1, (1 << 31)}};
  changing_power(&value5, 0);
  ck_assert_int_eq(s21_from_decimal_to_float(value5, &result), OK);
  ck_assert_float_lt(fabs(result + 79228162514264337593543950335.0f), 1e+22);

  s21_decimal value6 = {{1, 0, 0, 0}};
  changing_power(&value6, 28);
  ck_assert_int_eq(s21_from_decimal_to_float(value6, &result), OK);
  ck_assert_float_lt(fabs(result - 1e-28), 1e-33);

  s21_decimal value7 = {{0, 0, 0, (1 << 31)}};
  changing_power(&value7, 0);
  ck_assert_int_eq(s21_from_decimal_to_float(value7, &result), OK);
  ck_assert_float_lt(fabs(result), 1e-7);
}
END_TEST

START_TEST(from_int_to_decimal_testing) {
  int value1 = 123;
  s21_decimal result1 = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(value1, &result1);
  ck_assert_int_eq(123, result1.bits[0]);
  ck_assert_int_eq(0, result1.bits[3]);

  int value2 = -56723;
  s21_decimal result2 = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(value2, &result2);
  ck_assert_int_eq(56723, result2.bits[0]);
  ck_assert_int_eq((1 << 31), result2.bits[3]);

  int value3 = 0;
  s21_decimal result3 = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(value3, &result3);
  ck_assert_int_eq(0, result3.bits[0]);
  ck_assert_int_eq(0, result3.bits[3]);
}
END_TEST

// LESS OR EQUAL

START_TEST(less_or_equal_testing) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(1, s21_is_less_or_equal(value1, value2));

  s21_decimal value3 = {{0, 0, 0, (1 << 31)}};
  s21_decimal value4 = {{0, 0, 0, (1 << 31)}};
  ck_assert_int_eq(1, s21_is_less_or_equal(value3, value4));

  s21_decimal value5 = {{0, 0, 0, (1 << 31)}};
  s21_decimal value6 = {{0, 0, 0, 0}};
  ck_assert_int_eq(1, s21_is_less_or_equal(value5, value6));

  s21_decimal value7 = {{0, 0, 0, 0}};
  s21_decimal value8 = {{0, 0, 0, (1 << 31)}};
  ck_assert_int_eq(1, s21_is_less_or_equal(value7, value8));

  s21_decimal value9 = {{0, (1 << 30), 0, 0}};
  s21_decimal value10 = {{0, (1 << 30), 0, 0}};
  ck_assert_int_eq(1, s21_is_less_or_equal(value9, value10));

  s21_decimal value98 = {{1, 0, 0, 0}};
  s21_decimal value99 = {{0, 0, 0, 0}};
  ck_assert_int_eq(0, s21_is_less_or_equal(value98, value99));

  s21_decimal value21 = {{0, 0, 0, 0}};
  s21_decimal value22 = {{1, 0, 0, 0}};
  ck_assert_int_eq(1, s21_is_less_or_equal(value21, value22));

  s21_decimal value23 = {{100, 200, 0, 0}};
  s21_decimal value24 = {{0, 0, 1, 0}};
  ck_assert_int_eq(1, s21_is_less_or_equal(value23, value24));

  s21_decimal value25 = {{(1 << 30), 0, 0, 0}};
  s21_decimal value26 = {{(1 << 31), 0, 0, 0}};
  ck_assert_int_eq(1, s21_is_less_or_equal(value25, value26));

  s21_decimal value27 = {{0, 0, (1 << 30), 0}};
  s21_decimal value28 = {{0, 0, (1 << 31), 0}};
  ck_assert_int_eq(1, s21_is_less_or_equal(value27, value28));

  s21_decimal value29 = {{1, 0, 0, (1 << 31)}};
  s21_decimal value30 = {{0, 0, 0, (1 << 31)}};
  ck_assert_int_eq(1, s21_is_less_or_equal(value29, value30));

  s21_decimal value31 = {{0, 0, (1 << 31), (1 << 31)}};
  s21_decimal value32 = {{0, 0, (1 << 30), (1 << 31)}};
  ck_assert_int_eq(1, s21_is_less_or_equal(value31, value32));

  s21_decimal value33 = {{0, 0, 1, (1 << 31)}};
  s21_decimal value34 = {{0, (1 << 30), 0, (1 << 31)}};
  ck_assert_int_eq(1, s21_is_less_or_equal(value33, value34));

  s21_decimal value35 = {{0, 0, 0, (1 << 31)}};
  s21_decimal value36 = {{1, 0, 0, 0}};
  ck_assert_int_eq(1, s21_is_less_or_equal(value35, value36));

  s21_decimal value37 = {{0, 0, 0, 0}};
  s21_decimal value38 = {{0, 2, 0, (1 << 31)}};
  ck_assert_int_eq(0, s21_is_less_or_equal(value37, value38));

  s21_decimal value39 = {{1, 2, 3, 0}};
  s21_decimal value40 = {{2, 2, 3, 0}};
  changing_power(&value39, 13);
  changing_power(&value40, 10);
  ck_assert_int_eq(1, s21_is_less_or_equal(value39, value40));

  s21_decimal value41 = {{1, 2, 3, 0}};
  s21_decimal value42 = {{1, 2, 3, 0}};
  changing_power(&value41, 5);
  changing_power(&value42, 10);
  ck_assert_int_eq(0, s21_is_less_or_equal(value41, value42));

  s21_decimal value43 = {{1, 2, 3, 0}};
  s21_decimal value44 = {{1, 2, 3, 0}};
  changing_power(&value43, 28);
  changing_power(&value44, 10);
  ck_assert_int_eq(1, s21_is_less_or_equal(value43, value44));

  s21_decimal value45 = {{0, 0, (1 << 31), (1 << 31)}};
  s21_decimal value46 = {{1, 2, 3, 0}};
  changing_power(&value45, 5);
  changing_power(&value46, 2);
  ck_assert_int_eq(1, s21_is_less_or_equal(value45, value46));

  s21_decimal value47 = {{0, 0, (1 << 20), (1 << 31)}};
  s21_decimal value48 = {{0, 0, 0, (1 << 31)}};
  changing_power(&value47, 15);
  changing_power(&value48, 10);
  ck_assert_int_eq(1, s21_is_less_or_equal(value47, value48));

  s21_decimal value49 = {{0, 0, (1 << 20), (1 << 31)}};
  s21_decimal value50 = {{0, 0, 0, (1 << 31)}};
  changing_power(&value49, 10);
  changing_power(&value50, 10);
  ck_assert_int_eq(1, s21_is_less_or_equal(value49, value50));
}
END_TEST

// GREATER

START_TEST(greater_testing) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  ck_assert_int_eq(0, s21_is_greater(val1, val2));

  s21_decimal val3 = {0};
  s21_decimal val4 = {0};
  val3.bits[0] = 255;
  val4.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_greater(val3, val4));

  s21_decimal val5 = {0};
  s21_decimal val6 = {0};
  val5.bits[0] = 256;
  val6.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_greater(val5, val6));

  s21_decimal val7 = {0};
  s21_decimal val8 = {0};
  val7.bits[0] = 257;
  val8.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_greater(val7, val8));

  s21_decimal val9 = {0};
  s21_decimal val10 = {0};
  changing_power(&val1, 127);
  ck_assert_int_eq(0, s21_is_greater(val9, val10));

  s21_decimal value11 = {{0, 0, 0, 0}};
  s21_decimal value12 = {{0, 0, 0, (1 << 31)}};
  ck_assert_int_eq(1, s21_is_less_or_equal(value11, value12));

  s21_decimal value13 = {{0, 0, 0, (1 << 31)}};
  s21_decimal value14 = {{0, 0, 0, 0}};
  ck_assert_int_eq(1, s21_is_less_or_equal(value13, value14));
}
END_TEST

// EQUAL

START_TEST(equal_testing) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(1, s21_is_equal(value1, value2));

  s21_decimal value3 = {{0, 0, 0, (1 << 31)}};
  s21_decimal value4 = {{0, 0, 0, (1 << 31)}};
  ck_assert_int_eq(1, s21_is_equal(value3, value4));

  s21_decimal value5 = {{0, 0, 0, (1 << 31)}};
  s21_decimal value6 = {{0, 0, 0, 0}};
  ck_assert_int_eq(1, s21_is_equal(value5, value6));

  s21_decimal value7 = {{0, 0, 0, 0}};
  s21_decimal value8 = {{0, 0, 0, (1 << 31)}};
  ck_assert_int_eq(1, s21_is_equal(value7, value8));

  s21_decimal value9 = {{0, (1 << 30), 0, 0}};
  s21_decimal value10 = {{0, (1 << 30), 0, 0}};
  ck_assert_int_eq(1, s21_is_equal(value9, value10));

  s21_decimal value11 = {{0, 0, 0, 0}};
  s21_decimal value12 = {{1, 0, 0, 0}};
  ck_assert_int_eq(0, s21_is_equal(value11, value12));

  s21_decimal value13 = {{100, 200, 0, 0}};
  s21_decimal value14 = {{0, 0, 1, 0}};
  ck_assert_int_eq(0, s21_is_equal(value13, value14));

  s21_decimal value15 = {{(1 << 30), 0, 0, 0}};
  s21_decimal value16 = {{(1 << 31), 0, 0, 0}};
  ck_assert_int_eq(0, s21_is_equal(value15, value16));

  s21_decimal value17 = {{0, 0, (1 << 30), 0}};
  s21_decimal value18 = {{0, 0, (1 << 31), 0}};
  ck_assert_int_eq(0, s21_is_equal(value17, value18));

  s21_decimal value19 = {{1, 0, 0, (1 << 31)}};
  s21_decimal value20 = {{0, 0, 0, (1 << 31)}};
  ck_assert_int_eq(0, s21_is_equal(value19, value20));

  s21_decimal value21 = {{0, 0, (1 << 31), (1 << 31)}};
  s21_decimal value22 = {{0, 0, (1 << 30), (1 << 31)}};
  ck_assert_int_eq(0, s21_is_equal(value21, value22));

  s21_decimal value23 = {{0, 0, 1, (1 << 31)}};
  s21_decimal value24 = {{0, (1 << 30), 0, (1 << 31)}};
  ck_assert_int_eq(0, s21_is_equal(value23, value24));

  s21_decimal value25 = {{0, 0, 0, (1 << 31)}};
  s21_decimal value26 = {{1, 0, 0, 0}};
  ck_assert_int_eq(0, s21_is_equal(value25, value26));

  s21_decimal value27 = {{0, 0, 0, 0}};
  s21_decimal value28 = {{0, 2, 0, (1 << 31)}};
  ck_assert_int_eq(0, s21_is_equal(value27, value28));

  s21_decimal value29 = {{1, 2, 3, 0}};
  s21_decimal value30 = {{2, 2, 3, 0}};
  changing_power(&value29, 13);
  changing_power(&value30, 10);
  ck_assert_int_eq(0, s21_is_equal(value29, value30));

  s21_decimal value31 = {{1, 2, 3, (1 << 31)}};
  s21_decimal value32 = {{1, 2, 3, 0}};
  changing_power(&value31, 6);
  changing_power(&value32, 10);
  ck_assert_int_eq(0, s21_is_equal(value31, value32));

  s21_decimal value33 = {{1, 2, 3, 0}};
  s21_decimal value34 = {{1, 2, 31, 0}};
  changing_power(&value33, 10);
  changing_power(&value34, 12);
  ck_assert_int_eq(0, s21_is_equal(value33, value34));

  s21_decimal value35 = {{0, 0, (1 << 31), (1 << 31)}};
  s21_decimal value36 = {{1, 2, 3, 0}};
  changing_power(&value35, 5);
  changing_power(&value36, 2);
  ck_assert_int_eq(0, s21_is_equal(value35, value36));

  s21_decimal value37 = {{0, 0, (1 << 20), (1 << 31)}};
  s21_decimal value38 = {{0, 0, 0, (1 << 31)}};
  changing_power(&value37, 15);
  changing_power(&value38, 10);
  ck_assert_int_eq(0, s21_is_equal(value37, value38));

  s21_decimal value39 = {{0, 0, (1 << 20), (1 << 31)}};
  s21_decimal value40 = {{0, 0, 0, (1 << 31)}};
  changing_power(&value39, 10);
  changing_power(&value40, 10);
  ck_assert_int_eq(0, s21_is_equal(value39, value40));

  s21_decimal value41 = {{0, 0, 30, (1 << 31)}};
  s21_decimal value42 = {{0, 0, 3, (1 << 31)}};
  changing_power(&value41, 11);
  changing_power(&value42, 10);
  ck_assert_int_eq(1, s21_is_equal(value41, value42));
}
END_TEST

// NOT EQUAL

START_TEST(not_equal_testing) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(0, s21_is_not_equal(value1, value2));

  s21_decimal value3 = {{0, 0, 0, (1 << 31)}};
  s21_decimal value4 = {{0, 0, 0, (1 << 31)}};
  ck_assert_int_eq(0, s21_is_not_equal(value3, value4));

  s21_decimal value5 = {{0, 0, 0, (1 << 31)}};
  s21_decimal value6 = {{0, 0, 0, 0}};
  ck_assert_int_eq(0, s21_is_not_equal(value5, value6));

  s21_decimal value7 = {{0, 0, 0, 0}};
  s21_decimal value8 = {{0, 0, 0, (1 << 31)}};
  ck_assert_int_eq(0, s21_is_not_equal(value7, value8));

  s21_decimal value9 = {{0, (1 << 30), 0, 0}};
  s21_decimal value10 = {{0, (1 << 30), 0, 0}};
  ck_assert_int_eq(0, s21_is_not_equal(value9, value10));

  s21_decimal value21 = {{0, 0, 0, 0}};
  s21_decimal value22 = {{1, 0, 0, 0}};
  ck_assert_int_eq(1, s21_is_not_equal(value21, value22));

  s21_decimal value23 = {{100, 200, 0, 0}};
  s21_decimal value24 = {{0, 0, 1, 0}};
  ck_assert_int_eq(1, s21_is_not_equal(value23, value24));

  s21_decimal value25 = {{(1 << 30), 0, 0, 0}};
  s21_decimal value26 = {{(1 << 31), 0, 0, 0}};
  ck_assert_int_eq(1, s21_is_not_equal(value25, value26));

  s21_decimal value27 = {{0, 0, (1 << 30), 0}};
  s21_decimal value28 = {{0, 0, (1 << 31), 0}};
  ck_assert_int_eq(1, s21_is_not_equal(value27, value28));

  s21_decimal value29 = {{1, 0, 0, (1 << 31)}};
  s21_decimal value30 = {{0, 0, 0, (1 << 31)}};
  ck_assert_int_eq(1, s21_is_not_equal(value29, value30));

  s21_decimal value31 = {{0, 0, (1 << 31), (1 << 31)}};
  s21_decimal value32 = {{0, 0, (1 << 30), (1 << 31)}};
  ck_assert_int_eq(1, s21_is_not_equal(value31, value32));

  s21_decimal value33 = {{0, 0, 1, (1 << 31)}};
  s21_decimal value34 = {{0, (1 << 30), 0, (1 << 31)}};
  ck_assert_int_eq(1, s21_is_not_equal(value33, value34));

  s21_decimal value35 = {{0, 0, 0, (1 << 31)}};
  s21_decimal value36 = {{1, 0, 0, 0}};
  ck_assert_int_eq(1, s21_is_not_equal(value35, value36));

  s21_decimal value37 = {{0, 0, 0, 0}};
  s21_decimal value38 = {{0, 2, 0, (1 << 31)}};
  ck_assert_int_eq(1, s21_is_not_equal(value37, value38));

  s21_decimal value39 = {{1, 2, 3, 0}};
  s21_decimal value40 = {{2, 2, 3, 0}};
  changing_power(&value39, 13);
  changing_power(&value40, 10);
  ck_assert_int_eq(1, s21_is_not_equal(value39, value40));

  s21_decimal value41 = {{1, 2, 3, (1 << 31)}};
  s21_decimal value42 = {{1, 2, 3, 0}};
  changing_power(&value41, 6);
  changing_power(&value42, 10);
  ck_assert_int_eq(1, s21_is_not_equal(value41, value42));

  s21_decimal value43 = {{1, 2, 3, 0}};
  s21_decimal value44 = {{1, 2, 31, 0}};
  changing_power(&value43, 10);
  changing_power(&value44, 12);
  ck_assert_int_eq(1, s21_is_not_equal(value43, value44));

  s21_decimal value45 = {{0, 0, (1 << 31), (1 << 31)}};
  s21_decimal value46 = {{1, 2, 3, 0}};
  changing_power(&value45, 5);
  changing_power(&value46, 2);
  ck_assert_int_eq(1, s21_is_not_equal(value45, value46));

  s21_decimal value47 = {{0, 0, (1 << 20), (1 << 31)}};
  s21_decimal value48 = {{0, 0, 0, (1 << 31)}};
  changing_power(&value47, 15);
  changing_power(&value48, 10);
  ck_assert_int_eq(1, s21_is_not_equal(value47, value48));

  s21_decimal value49 = {{0, 0, (1 << 20), (1 << 31)}};
  s21_decimal value50 = {{0, 0, 0, (1 << 31)}};
  changing_power(&value49, 10);
  changing_power(&value50, 10);
  ck_assert_int_eq(1, s21_is_not_equal(value49, value50));

  s21_decimal value51 = {{0, 0, 30, (1 << 31)}};
  s21_decimal value52 = {{0, 0, 3, (1 << 31)}};
  changing_power(&value51, 11);
  changing_power(&value52, 10);
  ck_assert_int_eq(0, s21_is_not_equal(value51, value52));
}
END_TEST

START_TEST(from_decimal_to_int_testing) {
  int result;
  s21_decimal value1 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_from_decimal_to_int(value1, &result), OK);
  ck_assert_int_eq(result, 0);

  s21_decimal value2 = {{25, 0, 0, 0}};
  ck_assert_int_eq(s21_from_decimal_to_int(value2, &result), OK);
  ck_assert_int_eq(result, 25);

  s21_decimal value3 = {{25, 0, 0, (1 << 31)}};
  changing_power(&value3, 0);
  ck_assert_int_eq(s21_from_decimal_to_int(value3, &result), OK);
  ck_assert_int_eq(result, -25);

  s21_decimal value21 = {{29, 0, 0, 0}};
  changing_power(&value21, 1);
  ck_assert_int_eq(s21_from_decimal_to_int(value21, &result), OK);
  ck_assert_int_eq(result, 2);

  s21_decimal value31 = {{29, 0, 0, (1 << 31)}};
  changing_power(&value31, 1);
  ck_assert_int_eq(s21_from_decimal_to_int(value31, &result), OK);
  ck_assert_int_eq(result, -2);

  s21_decimal value4 = {{25, 1, 0, (1 << 31)}};
  changing_power(&value4, 0);
  ck_assert_int_eq(s21_from_decimal_to_int(value4, &result), ERROR);

  // округление вниз
  s21_decimal value5 = {{25, 0, 0, (1 << 31)}};
  changing_power(&value5, 1);
  ck_assert_int_eq(s21_from_decimal_to_int(value5, &result), OK);
  ck_assert_int_eq(result, -2);

  s21_decimal value6 = {{25, 0, 0, 0}};
  changing_power(&value6, 1);
  ck_assert_int_eq(s21_from_decimal_to_int(value6, &result), OK);
  ck_assert_int_eq(result, 2);

  s21_decimal value7 = {{0, 1, 0, 0}};
  changing_power(&value7, 9);
  ck_assert_int_eq(s21_from_decimal_to_int(value7, &result), OK);
  ck_assert_int_eq(result, 4);

  s21_decimal value8 = {{0, 0, 1, 0}};
  changing_power(&value8, 18);
  ck_assert_int_eq(s21_from_decimal_to_int(value8, &result), OK);
  ck_assert_int_eq(result, 18);
}
END_TEST

//  Mult pos numbers 12.34 * 56.78 = 700.6652
START_TEST(s21_mul_test_1) {
  s21_decimal first = {{1234, 0, 0, 0}};
  s21_decimal second = {{5678, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{7006652, 0, 0, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.scale = 2;
  first.bits[3] = f.i;
  second.bits[3] = f.i;
  f.parts.scale = 4;
  expected.bits[3] = f.i;

  int res = s21_mul(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// Mult negative numbers -12.34 * -56.78 = 700.6652
START_TEST(s21_mul_test_2) {
  s21_decimal first = {{1234, 0, 0, 0}};
  s21_decimal second = {{5678, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{7006652, 0, 0, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.sign = 1;
  f.parts.scale = 2;

  first.bits[3] = f.i;
  second.bits[3] = f.i;

  f.i = 0;
  f.parts.scale = 4;
  expected.bits[3] = f.i;

  int res = s21_mul(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// Mult negative & pos numbers -12.34 * 56.78 = -700.6652
START_TEST(s21_mul_test_3) {
  s21_decimal first = {{1234, 0, 0, 0}};
  s21_decimal second = {{5678, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{7006652, 0, 0, 0}};
  decimal_bit3 f;
  f.i = 0;

  f.parts.sign = 1;
  f.parts.scale = 2;
  first.bits[3] = f.i;

  f.parts.sign = 0;
  second.bits[3] = f.i;

  f.parts.scale = 4;
  f.parts.sign = 1;
  expected.bits[3] = f.i;

  int res = s21_mul(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// 123.45 * 0 = 0
START_TEST(s21_mul_test_4) {
  s21_decimal first = {{12345, 0, 0, 0}};
  s21_decimal second = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};
  decimal_bit3 f;
  f.i = 0;

  f.parts.scale = 2;
  first.bits[3] = f.i;

  expected.bits[3] = f.i;

  int res = s21_mul(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// 0 * 123.45 = 0;
START_TEST(s21_mul_test_5) {
  s21_decimal first = {{0, 0, 0, 0}};
  s21_decimal second = {{12345, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};
  decimal_bit3 f;
  f.i = 0;

  f.parts.scale = 2;
  second.bits[3] = f.i;

  expected.bits[3] = f.i;

  int res = s21_mul(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// 79,228,162,514,264,337,593,543,950,335 * 2)
START_TEST(s21_mul_test_6) {
  s21_decimal first = {{-1, -1, -1, 0}};
  s21_decimal second = {{2, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};

  int res = s21_mul(first, second, &result);
  int exp = 1;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);

  ck_assert_int_eq(res, exp);
}
END_TEST

//(1.2300 * 2.100 = 2.58300)
START_TEST(s21_mul_test_8) {
  s21_decimal first = {{12300, 0, 0, 0}};
  s21_decimal second = {{2100, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{25830000, 0, 0, 0}};
  decimal_bit3 f;
  f.i = 0;

  f.parts.scale = 4;
  first.bits[3] = f.i;
  f.parts.scale = 3;
  second.bits[3] = f.i;

  f.parts.scale = 7;
  expected.bits[3] = f.i;

  int res = s21_mul(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// 123.45 * 1 = 123.45
START_TEST(s21_mul_test_9) {
  s21_decimal first = {{12345, 0, 0, 0}};
  s21_decimal second = {{1, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{12345, 0, 0, 0}};
  decimal_bit3 f;
  f.i = 0;

  f.parts.scale = 2;
  first.bits[3] = f.i;

  expected.bits[3] = f.i;

  int res = s21_mul(first, second, &result);
  int exp = 0;
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// 18 446 744 073 709 551 615 * 2 = 36 893 488 147 419 103 230
START_TEST(s21_mul_test_10) {
  s21_decimal first = {{-1, -1, 0, 0}};
  s21_decimal second = {{2, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{-2, -1, 1, 0}};

  int res = s21_mul(first, second, &result);
  int exp = 0;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);

  ck_assert_int_eq(res, exp);
}
END_TEST

// 2 * 18 446 744 073 709 551 615 = 36 893 488 147 419 103 230
START_TEST(s21_mul_test_11) {
  s21_decimal first = {{2, 0, 0, 0}};
  s21_decimal second = {{-1, -1, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{-2, -1, 1, 0}};

  int res = s21_mul(first, second, &result);
  int exp = 0;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// 12345 * 433,791,696,895 = 5.355.158.498.168.775
START_TEST(s21_mul_test_12) {
  s21_decimal first = {{12345, 0, 0, 0}};
  s21_decimal second = {{4294967295, 100, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{-12345, 1246844, 0, 0}};

  int res = s21_mul(first, second, &result);
  int exp = 0;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);

  ck_assert_int_eq(res, exp);
}
END_TEST
// Overflow max * max
START_TEST(s21_mul_test_13) {
  s21_decimal first = {{-1, -1, -1, 0}};
  s21_decimal second = {{-1, -1, -1, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};

  int res = s21_mul(first, second, &result);
  int exp = 1;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);

  ck_assert_int_eq(res, exp);
}
END_TEST
// 79228162514264337593543950335 * 0,2 = 15845632502852867518708790067
START_TEST(s21_mul_test_14) {
  s21_decimal first = {{-1, -1, -1, 0}};
  s21_decimal second = {{2, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{858993459, 858993459, 858993459, 0}};

  decimal_bit3 f;
  f.i = 0;

  f.parts.scale = 1;
  second.bits[3] = f.i;
  f.i = 0;
  expected.bits[3] = f.i;

  int res = s21_mul(first, second, &result);
  int exp = 0;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// 50.000.000 * 0.12345 = 6.172.500,00000
START_TEST(s21_mul_test_15) {
  s21_decimal first = {{50000000, 0, 0, 0}};
  s21_decimal second = {{12345, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{-1225290624, 143, 0, 0}};  // разнос на 2 инта

  decimal_bit3 f;
  f.i = 0;

  f.parts.scale = 5;
  second.bits[3] = f.i;

  expected.bits[3] = f.i;

  int res = s21_mul(first, second, &result);
  int exp = 0;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);

  ck_assert_int_eq(res, exp);
}
END_TEST

// 200 * -300 = -60.000
START_TEST(s21_mul_test_16) {
  s21_decimal first = {{200, 0, 0, 0}};
  s21_decimal second = {{300, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{60000, 0, 0, 0}};

  decimal_bit3 f;
  f.i = 0;
  f.parts.sign = 1;
  second.bits[3] = f.i;
  expected.bits[3] = f.i;

  int res = s21_mul(first, second, &result);
  int exp = 0;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);

  ck_assert_int_eq(res, exp);
}
END_TEST

// -MAX * 2 = Error 2
START_TEST(s21_mul_test_17) {
  s21_decimal first = {{-1, -1, -1, 0}};
  s21_decimal second = {{2, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};

  decimal_bit3 f;
  f.i = 0;
  f.parts.sign = 1;
  first.bits[3] = f.i;

  int res = s21_mul(first, second, &result);
  int exp = 2;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);

  ck_assert_int_eq(res, exp);
}
END_TEST

// 5252376535442.31 * 21335534531.4435 =
// 112062260944072979356875.274485 = 112062260944072979356875.27448|5|
START_TEST(s21_mul_test_18) {
  s21_decimal first = {{1807949095, 122291, 0, 0}};
  s21_decimal second = {{-1450081661, 49675, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{207596568, -661394484, 607490733, 0}};

  decimal_bit3 f;
  f.i = 0;

  f.parts.scale = 4;
  second.bits[3] = f.i;

  f.parts.scale = 2;
  first.bits[3] = f.i;

  f.i = 0;
  f.parts.scale = 5;
  expected.bits[3] = f.i;

  int res = s21_mul(first, second, &result);
  int exp = 0;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);

  ck_assert_int_eq(res, exp);
}
END_TEST

// 5252376535442.21 * 21335534531.4435 =
// 112062260944070845803422.130135 = 112062260944070845803422.13014^|5|
START_TEST(s21_mul_test_18_2) {
  s21_decimal first = {{1807949085, 122291, 0, 0}};
  s21_decimal second = {{-1450081661, 49675, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{1657678230, -661444160, 607490733, 0}};

  decimal_bit3 f;
  f.i = 0;

  f.parts.scale = 4;
  second.bits[3] = f.i;

  f.parts.scale = 2;
  first.bits[3] = f.i;

  f.i = 0;
  f.parts.scale = 5;
  expected.bits[3] = f.i;

  int res = s21_mul(first, second, &result);
  int exp = 0;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);

  ck_assert_int_eq(res, exp);
}
END_TEST

// 525653442.225132546 * 2134531.452432365 =
// 1122023805508884.4348535062252|5_129 = 1122023805508884.4348535062253|5|
// 1122023805508884.4348535062252
START_TEST(s21_mul_test_19) {
  s21_decimal first = {{1254773762, 122388229, 0, 0}};
  s21_decimal second = {{1425797101, 496984, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{502775533, -1045425959, 608250323, 0}};
  //                       502775532, -1045425959, 608250323 |2|

  decimal_bit3 f;
  f.i = 0;

  f.parts.scale = 9;
  first.bits[3] = f.i;
  second.bits[3] = f.i;

  f.i = 0;
  f.parts.scale = 13;
  expected.bits[3] = f.i;

  int res = s21_mul(first, second, &result);
  int exp = 0;

  ck_assert_int_eq(res, exp);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
}
END_TEST

//  525614242.22412341 * 2134451.441436363 = 1121898076954761.8650159789735|5783
//  = 1121898076954761.86501597897355_783 = 1121898076954761.8650159789736^ |5|
START_TEST(s21_mul_test_19_2) {
  s21_decimal first = {{1001020981, 12237910, 0, 0}};
  s21_decimal second = {{-1275787573, 496965, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{-318032216, 733714525, 608182166, 0}};

  decimal_bit3 f;
  f.i = 0;

  f.parts.scale = 9;
  second.bits[3] = f.i;

  f.parts.scale = 8;
  first.bits[3] = f.i;

  f.i = 0;
  f.parts.scale = 13;
  expected.bits[3] = f.i;

  int res = s21_mul(first, second, &result);
  int exp = 0;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);

  ck_assert_int_eq(res, exp);
}
END_TEST

// 525653442.225132546 * 21334531.452432365 =
// 11214569896231429.31805350622525129 = 11214569896231429.318053506225|2|
START_TEST(s21_mul_test_20) {
  s21_decimal first = {{1254773762, 122388229, 0, 0}};
  s21_decimal second = {{-1330909203, 4967332, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{1389407409, 1070446229, 607943052, 0}};

  decimal_bit3 f;
  f.i = 0;

  f.parts.scale = 9;
  second.bits[3] = f.i;

  f.parts.scale = 9;
  first.bits[3] = f.i;

  f.i = 0;
  f.parts.scale = 12;
  expected.bits[3] = f.i;

  int res = s21_mul(first, second, &result);
  int exp = 0;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);

  ck_assert_int_eq(res, exp);
}
END_TEST

//  -5352352.5325151525 * 2134451.641436785134 =
//  11424337648575.301129120122741742935 = 11424337648575301129120122741|7| =
//  11424337648575.301129120122742^
START_TEST(s21_mul_test_20_2) {
  s21_decimal first = {{-635314907, 12461916, 0, 0}};
  s21_decimal second = {{-2045326866, 496965749, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{-1781135498, -473889346, 619314584, 0}};

  decimal_bit3 f;
  f.i = 0;

  f.parts.scale = 12;
  second.bits[3] = f.i;

  f.parts.sign = 1;
  f.parts.scale = 10;
  first.bits[3] = f.i;

  f.i = 0;
  f.parts.scale = 15;
  f.parts.sign = 1;
  expected.bits[3] = f.i;

  int res = s21_mul(first, second, &result);
  int exp = 0;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// 56123789731265187314523.566781 * -7123972461584724713987.3523562 =
// 399824332485304752015172774892752498860785752.9946483993922
START_TEST(s21_mul_test_21) {
  s21_decimal first = {{1506407101, -1125848118, -1252490559, 0}};
  s21_decimal second = {{1306298218, -908245321, -433054087, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};

  decimal_bit3 f;
  f.i = 0;

  f.parts.scale = 6;
  first.bits[3] = f.i;
  f.parts.scale = 7;
  f.parts.sign = 1;

  second.bits[3] = f.i;

  int res = s21_mul(first, second, &result);
  int exp = 2;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);

  ck_assert_int_eq(res, exp);
}
END_TEST

//-56123789731265187314523.566781 * -7123972461584724713987.3523562 =
// 399824332485304752015172774892752498860785752.9946483993922
START_TEST(s21_mul_test_22) {
  s21_decimal first = {{1506407101, -1125848118, -1252490559, 0}};
  s21_decimal second = {{1306298218, -908245321, -433054087, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};

  decimal_bit3 f;
  f.i = 0;
  f.parts.sign = 1;
  f.parts.scale = 6;
  first.bits[3] = f.i;

  f.parts.scale = 7;
  f.parts.sign = 1;
  second.bits[3] = f.i;

  int res = s21_mul(first, second, &result);
  int exp = 1;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);

  ck_assert_int_eq(res, exp);
}
END_TEST

// DIVISION

//  16 : 4 = 4 normal_simple_test_1
START_TEST(s21_div_normal_simple_test_1) {
  s21_decimal first = {{16, 0, 0, 0}};
  s21_decimal second = {{4, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{4, 0, 0, 0}};

  int res = s21_div(first, second, &result);
  int exp = 0;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// 1 / 3 = 0.3333333333333333333333333333
START_TEST(s21_error_div_test_2) {
  s21_decimal first = {{1, 0, 0, 0}};
  s21_decimal second = {{3, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{89478485, 347537611, 180700362, 0}};

  decimal_bit3 f;
  f.i = 0;

  f.parts.scale = 28;
  expected.bits[3] = f.i;

  int res = s21_div(first, second, &result);
  int exp = 0;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// 1 / 0 -> Error  3 //(Div_by_zero)
START_TEST(s21_div_by_zero_test_3) {
  s21_decimal first = {{1, 0, 0, 0}};
  s21_decimal second = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};

  int res = s21_div(first, second, &result);
  int exp = 3;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// MAX / 1 = MAX
START_TEST(s21_div_Max_by_1_test_4) {
  s21_decimal first = {{-1, -1, -1, 0}};
  s21_decimal second = {{1, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{-1, -1, -1, 0}};

  int res = s21_div(first, second, &result);
  int exp = 0;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// MAX / 0.5 = Error 1 //Overflow
START_TEST(s21_div_Max_0_5_test_5) {
  s21_decimal first = {{-1, -1, -1, 0}};
  s21_decimal second = {{5, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};
  decimal_bit3 f;
  f.i = 0;

  f.parts.scale = 1;
  second.bits[3] = f.i;

  f.i = 0;
  expected.bits[3] = f.i;

  int res = s21_div(first, second, &result);
  int exp = 1;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// -MAX / 0.5 = Error 2 // Minus Overflow
START_TEST(s21_div_minus_Max_test_6) {
  s21_decimal first = {{-1, -1, -1, 0}};
  s21_decimal second = {{5, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};
  decimal_bit3 f;
  f.i = 0;
  f.parts.sign = 1;
  first.bits[3] = f.i;
  f.parts.sign = 0;
  f.parts.scale = 1;
  second.bits[3] = f.i;

  int res = s21_div(first, second, &result);
  int exp = 2;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// -MAX / 1 = -MAX
START_TEST(s21_div_minus_Max_1_test_7) {
  s21_decimal first = {{-1, -1, -1, 0}};
  s21_decimal second = {{1, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{-1, -1, -1, 0}};

  decimal_bit3 f;
  f.i = 0;

  f.parts.sign = 1;
  first.bits[3] = f.i;

  expected.bits[3] = f.i;

  int res = s21_div(first, second, &result);
  int exp = 0;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// 10000000000000000000000000000 / 3 = 3333333333333333333333333333.3
START_TEST(s21_error_div_test_8) {
  s21_decimal first = {{268435456, 1042612833, 542101086, 0}};
  s21_decimal second = {{3, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{894784853, -819591186, 1807003620, 0}};

  decimal_bit3 f;
  f.i = 0;

  f.parts.scale = 1;
  expected.bits[3] = f.i;

  int res = s21_div(first, second, &result);
  int exp = 0;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// 10 / 0 = Error 3 // Div by zero
START_TEST(s21_div_test_9) {
  s21_decimal first = {{10, 0, 0, 0}};
  s21_decimal second = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};

  int res = s21_div(first, second, &result);
  int exp = 3;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// 79228162514264337593543950335 / 0.1 = 792281625142643375935439503350 Error 1
// (Overflow)
START_TEST(s21_div_test_10) {
  s21_decimal first = {{-1, -1, -1, 0}};
  s21_decimal second = {{1, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};

  decimal_bit3 f;
  f.i = 0;

  f.parts.scale = 1;
  second.bits[3] = f.i;

  f.i = 0;
  expected.bits[3] = f.i;

  int res = s21_div(first, second, &result);
  int exp = 1;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// 79228162514264337593543950335 / -0.1 = 792281625142643375935439503350 Error 2
// (Minus Overflow)
START_TEST(s21_div_minus_overflow_test_11) {
  s21_decimal first = {{-1, -1, -1, 0}};
  s21_decimal second = {{1, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};

  decimal_bit3 f;
  f.i = 0;

  f.parts.sign = 1;
  f.parts.scale = 1;
  second.bits[3] = f.i;

  f.i = 0;
  expected.bits[3] = f.i;

  int res = s21_div(first, second, &result);
  int exp = 2;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// 987654321.123456789987654321 / 123456.000000000000123456 =
// 8000.051201427689128110419906^

START_TEST(s21_div_test_12) {
  s21_decimal first = {{1014430385, 134593083, 53540848, 0}};
  s21_decimal second = {{553771584, -1876169196, 6692, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{45445058, -1592752032, 433683644, 0}};

  decimal_bit3 f;
  f.i = 0;
  f.parts.scale = 18;
  first.bits[3] = f.i;
  f.parts.scale = 18;
  second.bits[3] = f.i;

  f.parts.scale = 24;
  expected.bits[3] = f.i;

  int res = s21_div(first, second, &result);
  int exp = 0;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// -987654321.123456789987654321 / 123456.000000000000123456 =
// 8000.051201427689128110419906^
START_TEST(s21_div_test_13) {
  s21_decimal first = {{1014430385, 134593083, 53540848, 0}};
  s21_decimal second = {{553771584, -1876169196, 6692, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{45445058, -1592752032, 433683644, 0}};

  decimal_bit3 f;
  f.i = 0;
  f.parts.scale = 18;
  f.parts.sign = 1;
  first.bits[3] = f.i;
  f.parts.scale = 18;
  f.parts.sign = 0;
  second.bits[3] = f.i;
  f.i = 0;
  f.parts.sign = 1;
  f.parts.scale = 24;
  expected.bits[3] = f.i;

  int res = s21_div(first, second, &result);
  int exp = 0;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// 79228162514264337593543950.335 / 792281625142643375935.43950335 =
// 100000|.00000000000000000000000
START_TEST(s21_div_test_14) {
  s21_decimal first = {{-1, -1, -1, 0}};
  s21_decimal second = {{-1, -1, -1, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{100000, 0, 0, 0}};

  decimal_bit3 f;
  f.i = 0;
  f.parts.scale = 3;
  first.bits[3] = f.i;
  f.parts.scale = 8;
  second.bits[3] = f.i;

  int res = s21_div(first, second, &result);
  int exp = 0;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// 79228162514264337593543950.335 / -792281625142643375935.43950335 =
// 100000.00000000000000000000000
START_TEST(s21_div_test_15) {
  s21_decimal first = {{-1, -1, -1, 0}};
  s21_decimal second = {{-1, -1, -1, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{100000, 0, 0, 0}};

  decimal_bit3 f;
  f.i = 0;

  f.parts.scale = 3;
  first.bits[3] = f.i;

  f.parts.scale = 8;
  f.parts.sign = 1;
  second.bits[3] = f.i;

  f.i = 0;
  f.parts.sign = 1;
  expected.bits[3] = f.i;

  int res = s21_div(first, second, &result);
  int exp = 0;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// 79228162514264337593543950.335 / 7922816251426433759354395033.5 = 0.01
START_TEST(s21_div_test_16) {
  s21_decimal first = {{-1, -1, -1, 0}};
  s21_decimal second = {{-1, -1, -1, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{1, 0, 0, 0}};

  decimal_bit3 f;
  f.i = 0;
  f.parts.scale = 3;
  first.bits[3] = f.i;
  f.parts.scale = 1;
  second.bits[3] = f.i;
  f.parts.scale = 2;
  expected.bits[3] = f.i;

  int res = s21_div(first, second, &result);
  int exp = 0;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

//  69228162514264337593543950.345 / 2.4 =
//  28845067714276807330643312.643 ^|7|5 = 28845067714276807330643312.644
START_TEST(s21_div_test_17) {
  s21_decimal first = {{-268435447, -1042612834, -542101087, 0}};
  s21_decimal second = {{24, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{-469762044, 281405868, 1563694254, 0}};

  decimal_bit3 f;
  f.i = 0;
  f.parts.scale = 3;
  first.bits[3] = f.i;
  f.parts.scale = 1;
  second.bits[3] = f.i;
  f.parts.scale = 3;
  expected.bits[3] = f.i;

  int res = s21_div(first, second, &result);
  int exp = 0;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

//  692281625142643375935439503.45  / 4 =
//  173070406285660843983859875.86 |2|5 = 173070406285660843983859875.86
START_TEST(s21_div_test_18) {
  s21_decimal first = {{-268435447, -1042612834, -542101087, 0}};
  s21_decimal second = {{4, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{-1140850686, 1886830439, 938216552, 0}};

  decimal_bit3 f;
  f.i = 0;
  f.parts.scale = 2;
  first.bits[3] = f.i;

  expected.bits[3] = f.i;

  int res = s21_div(first, second, &result);
  int exp = 0;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

//  792281625142643375935439503.35 / 2 =
//  396140812571321687967719751.67^|5|  = 396140812571321687967719751.68 //После
//  5 ничего нет, число нечетное
START_TEST(s21_div_test_19) {
  s21_decimal first = {{-1, -1, -1, 0}};
  s21_decimal second = {{2, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, -2147483648, 0}};

  decimal_bit3 f;
  f.i = 0;
  f.parts.scale = 2;
  first.bits[3] = f.i;

  expected.bits[3] = f.i;

  int res = s21_div(first, second, &result);
  int exp = 0;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// 69228162514264337593543950.345 / 2.56 = 27042250982134506872478105.603^
// |5|15625 = 27042250982134506872478105.604
START_TEST(s21_div_test_20) {
  s21_decimal first = {{-268435447, -1042612834, -542101087, 0}};
  s21_decimal second = {{256, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{364904452, 800688914, 1465963363, 0}};

  decimal_bit3 f;
  f.i = 0;
  f.parts.scale = 3;
  first.bits[3] = f.i;
  f.parts.scale = 2;
  second.bits[3] = f.i;

  f.parts.scale = 3;
  expected.bits[3] = f.i;

  int res = s21_div(first, second, &result);
  int exp = 0;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// 69228162514264337593543950.345 / 2 =
//  34614081257132168796771975.172 |5| = 34614081257132168796771975.172
START_TEST(s21_div_test_21) {
  s21_decimal first = {{-268435447, -1042612834, -542101087, 0}};
  s21_decimal second = {{2, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{2013265924, -521306417, 1876433104, 0}};

  decimal_bit3 f;
  f.i = 0;
  f.parts.scale = 3;
  first.bits[3] = f.i;

  f.parts.scale = 3;
  expected.bits[3] = f.i;

  int res = s21_div(first, second, &result);
  int exp = 0;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// 69228162514264337593543950.345 / 0.0008 = 86535203142830421991929937931.25
START_TEST(s21_div_test_22) {
  s21_decimal first = {{-268435447, -1042612834, -542101087, 0}};
  s21_decimal second = {{8, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};

  decimal_bit3 f;
  f.i = 0;
  f.parts.scale = 3;
  first.bits[3] = f.i;

  f.parts.scale = 4;
  second.bits[3] = f.i;

  int res = s21_div(first, second, &result);
  int exp = 1;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

// 4 / 16 = 0.25
START_TEST(s21_div_test_23) {
  s21_decimal first = {{4, 0, 0, 0}};
  s21_decimal second = {{16, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal expected = {{25, 0, 0, 0}};

  decimal_bit3 f;
  f.i = 0;
  f.parts.scale = 2;
  expected.bits[3] = f.i;

  int res = s21_div(first, second, &result);
  int exp = 0;

  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  ck_assert_int_eq(res, exp);
}
END_TEST

Suite *root_suite(void) {
  Suite *d = suite_create("decimal");

  TCase *add, *sub, *less, *greater_or_equal, *from_float_to_decimal, *negate,
      *truncate, *round, *floor, *from_decimal_to_float, *from_int_to_decimal,
      *equal, *not_equal, *less_or_equal, *greater, *from_decimal_to_int, *mul,
      *div;

  add = tcase_create("add_TCase");
  tcase_add_test(add, s21_add_zero_plus);
  tcase_add_test(add, s21_add_zero_minus_plus);
  tcase_add_test(add, s21_add_zero_minus);
  tcase_add_test(add, s21_add_normal1);
  tcase_add_test(add, s21_add_normal12);
  tcase_add_test(add, s21_add_normal123);
  tcase_add_test(add, s21_add_normal123_minus1);
  tcase_add_test(add, s21_add_normal123_minus2);
  tcase_add_test(add, s21_add_normal123_minus12);
  tcase_add_test(add, s21_add_normal123_minus_res);
  tcase_add_test(add, s21_add_float);
  tcase_add_test(add, s21_add_float_dif);
  tcase_add_test(add, s21_add_float_dif3);
  tcase_add_test(add, s21_add_toobig);
  tcase_add_test(add, s21_add_toosmall);
  tcase_add_test(add, s21_add_max);
  tcase_add_test(add, s21_add_bank);
  tcase_add_test(add, s21_add_mantis_bank);
  tcase_add_test(add, s21_add_mantis_nobank);

  sub = tcase_create("sub_TCase");
  tcase_add_test(sub, s21_sub_zero_plus);
  tcase_add_test(sub, s21_sub_zero_minus_plus);
  tcase_add_test(sub, s21_sub_zero_minus);
  tcase_add_test(sub, s21_sub_normal1);
  tcase_add_test(sub, s21_sub_normal12);
  tcase_add_test(sub, s21_sub_normal123);
  tcase_add_test(sub, s21_sub_normal123_minus1);
  tcase_add_test(sub, s21_sub_normal123_minus2);
  tcase_add_test(sub, s21_sub_normal123_minus12);
  tcase_add_test(sub, s21_sub_normal123_minus_res);
  tcase_add_test(sub, s21_sub_float);
  tcase_add_test(sub, s21_sub_float_dif);
  tcase_add_test(sub, s21_sub_float_dif3);
  tcase_add_test(sub, s21_sub_toobig);
  tcase_add_test(sub, s21_sub_toosmall);
  tcase_add_test(sub, s21_sub_max);
  tcase_add_test(sub, s21_sub_bank);
  tcase_add_test(sub, s21_sub_mantis_bank);
  tcase_add_test(sub, s21_sub_mantis_nobank);

  less = tcase_create("less_TCase");
  tcase_add_test(less, s21_is_less_zero);
  tcase_add_test(less, s21_is_less_normal);
  tcase_add_test(less, s21_is_less_normal1);
  tcase_add_test(less, s21_is_less_normal12);
  tcase_add_test(less, s21_is_less_normal123);
  tcase_add_test(less, s21_is_less_sign);
  tcase_add_test(less, s21_is_less_float);
  tcase_add_test(less, s21_is_less_float123);

  greater_or_equal = tcase_create("greater_or_equal_TCase");
  tcase_add_test(greater_or_equal, s21_is_greater_or_equal_zero);
  tcase_add_test(greater_or_equal, s21_is_greater_or_equal_normal);
  tcase_add_test(greater_or_equal, s21_is_greater_or_equal_normal1);
  tcase_add_test(greater_or_equal, s21_is_greater_or_equal_normal12);
  tcase_add_test(greater_or_equal, s21_is_greater_or_equal_normal123);
  tcase_add_test(greater_or_equal, s21_is_greater_or_equal_sign);
  tcase_add_test(greater_or_equal, s21_is_greater_or_equal_float);
  tcase_add_test(greater_or_equal, s21_is_greater_or_equal_float123);

  from_float_to_decimal = tcase_create("from_float_to_decimal_TCase");
  tcase_add_test(from_float_to_decimal, s21_from_float_to_decimal_normal1);
  tcase_add_test(from_float_to_decimal, s21_from_float_to_decimal_normal12);
  tcase_add_test(from_float_to_decimal,
                 s21_from_float_to_decimal_normal12_minus);
  tcase_add_test(from_float_to_decimal, s21_from_float_to_decimal_zero);
  tcase_add_test(from_float_to_decimal, s21_from_float_to_decimal_after_only);
  tcase_add_test(from_float_to_decimal, s21_from_float_to_decimal_before_only);
  tcase_add_test(from_float_to_decimal, s21_from_float_to_decimal_inf);
  tcase_add_test(from_float_to_decimal, s21_from_float_to_decimal_infminus);
  tcase_add_test(from_float_to_decimal, s21_from_float_to_decimal_nan);
  tcase_add_test(from_float_to_decimal, s21_from_float_to_decimal_small);
  tcase_add_test(from_float_to_decimal, s21_from_float_to_decimal_toosmall);

  mul = tcase_create("mul_Tcase");
  tcase_add_test(mul, s21_mul_test_1);
  tcase_add_test(mul, s21_mul_test_2);
  tcase_add_test(mul, s21_mul_test_3);
  tcase_add_test(mul, s21_mul_test_4);
  tcase_add_test(mul, s21_mul_test_5);
  tcase_add_test(mul, s21_mul_test_6);
  tcase_add_test(mul, s21_mul_test_8);
  tcase_add_test(mul, s21_mul_test_9);
  tcase_add_test(mul, s21_mul_test_10);
  tcase_add_test(mul, s21_mul_test_11);
  tcase_add_test(mul, s21_mul_test_12);
  tcase_add_test(mul, s21_mul_test_13);
  tcase_add_test(mul, s21_mul_test_14);
  tcase_add_test(mul, s21_mul_test_15);
  tcase_add_test(mul, s21_mul_test_16);
  tcase_add_test(mul, s21_mul_test_17);
  tcase_add_test(mul, s21_mul_test_18);
  tcase_add_test(mul, s21_mul_test_18_2);
  tcase_add_test(mul, s21_mul_test_19);
  tcase_add_test(mul, s21_mul_test_19_2);
  tcase_add_test(mul, s21_mul_test_20);
  tcase_add_test(mul, s21_mul_test_20_2);
  tcase_add_test(mul, s21_mul_test_21);
  tcase_add_test(mul, s21_mul_test_22);

  div = tcase_create("div_Tcase");
  tcase_add_test(div, s21_div_normal_simple_test_1);
  tcase_add_test(div, s21_error_div_test_2);
  tcase_add_test(div, s21_div_by_zero_test_3);
  tcase_add_test(div, s21_div_Max_by_1_test_4);
  tcase_add_test(div, s21_div_Max_0_5_test_5);
  tcase_add_test(div, s21_div_minus_Max_test_6);
  tcase_add_test(div, s21_div_minus_Max_1_test_7);
  tcase_add_test(div, s21_error_div_test_8);
  tcase_add_test(div, s21_div_test_9);
  tcase_add_test(div, s21_div_test_10);
  tcase_add_test(div, s21_div_minus_overflow_test_11);
  tcase_add_test(div, s21_div_test_12);
  tcase_add_test(div, s21_div_test_13);
  tcase_add_test(div, s21_div_test_14);
  tcase_add_test(div, s21_div_test_15);
  tcase_add_test(div, s21_div_test_16);
  tcase_add_test(div, s21_div_test_17);
  tcase_add_test(div, s21_div_test_18);
  tcase_add_test(div, s21_div_test_19);
  tcase_add_test(div, s21_div_test_20);
  tcase_add_test(div, s21_div_test_21);
  tcase_add_test(div, s21_div_test_22);
  tcase_add_test(div, s21_div_test_23);

  negate = tcase_create("negate_TCase");
  tcase_add_test(negate, negate_testing);

  truncate = tcase_create("truncate_TCase");
  tcase_add_test(truncate, truncate_testing);

  round = tcase_create("round_TCase");
  tcase_add_test(round, round_testing);

  floor = tcase_create("floor_TCase");
  tcase_add_test(floor, floor_testing);

  from_decimal_to_float = tcase_create("from_decimal_to_float_TCase");
  tcase_add_test(from_decimal_to_float, from_decimal_to_float_testing);

  from_int_to_decimal = tcase_create("from_decimal_to_float_TCase");
  tcase_add_test(from_int_to_decimal, from_int_to_decimal_testing);

  greater = tcase_create("greater_TCase");
  tcase_add_test(greater, greater_testing);

  equal = tcase_create("equal_TCase");
  tcase_add_test(equal, equal_testing);

  not_equal = tcase_create("not_equal_TCase");
  tcase_add_test(not_equal, not_equal_testing);

  less_or_equal = tcase_create("less_or_equal_TCase");
  tcase_add_test(less_or_equal, less_or_equal_testing);

  from_decimal_to_int = tcase_create("from_decimal_to_int_TCase");
  tcase_add_test(less_or_equal, from_decimal_to_int_testing);

  suite_add_tcase(d, add);
  suite_add_tcase(d, sub);
  suite_add_tcase(d, less);
  suite_add_tcase(d, greater_or_equal);
  suite_add_tcase(d, from_float_to_decimal);
  suite_add_tcase(d, negate);
  suite_add_tcase(d, truncate);
  suite_add_tcase(d, round);
  suite_add_tcase(d, floor);
  suite_add_tcase(d, from_decimal_to_float);
  suite_add_tcase(d, from_int_to_decimal);
  suite_add_tcase(d, equal);
  suite_add_tcase(d, not_equal);
  suite_add_tcase(d, less_or_equal);
  suite_add_tcase(d, greater);
  suite_add_tcase(d, from_decimal_to_int);
  suite_add_tcase(d, mul);
  suite_add_tcase(d, div);
  return d;
}

int main(void) {
  int failed = 0;
  Suite *s = root_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (failed == 0) ? 0 : -1;
}