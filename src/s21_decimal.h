#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

typedef struct {
  int bits[4];
} s21_decimal;

typedef struct {
  int bits[6];
} s21_BIG_decimal;

typedef enum s21_decimal_sign { POSITIVE = 0, NEGATIVE = 1 } s21_decimal_sign;

typedef enum s21_success { OK = 0, ERROR = 1 } s21_success;

typedef enum s21_bool { FALSE = 0, TRUE = 1 } s21_bool;

typedef union decimal_bit3 {
  int i;
  struct {
    uint32_t empty1 : 16;
    uint32_t scale : 8;
    uint32_t empty2 : 7;
    uint32_t sign : 1;
  } parts;
} decimal_bit3;

typedef union float_bit {
  int i;
  struct {
    uint32_t mantis : 23;
    uint32_t scale : 8;
    uint32_t sign : 1;
  } parts;
} float_bit;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal leftOp, s21_decimal rightOp);
int s21_is_greater(s21_decimal leftOp, s21_decimal rightOp);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal leftOp, s21_decimal rightOp);
int s21_is_not_equal(s21_decimal leftOp, s21_decimal rightOp);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

int get_bit(s21_decimal value, int index);
int get_BIG_bit(s21_BIG_decimal value, int index);
int power(s21_decimal value);
int changing_power(s21_decimal *value, int new_index);
int sign(s21_decimal value);
void changing_sign(s21_decimal *value);
int signB(s21_BIG_decimal value);
int normalization(s21_decimal *value_1, s21_decimal *value_2);
int anti_normalization(s21_decimal *value_1, s21_decimal *value_2);
int divten(s21_decimal *value);
int div_ten_signed(s21_decimal *value);
int multiten(s21_BIG_decimal *value);
s21_decimal s21_decimal_zero(void);

int s21_print_two(s21_decimal value);
void print_float_two(float src);
int divtwo(s21_decimal *value);
int two_minus_pow(int pow);
int is_devided_ten(s21_decimal value);
int is_zero(s21_decimal value);

void set_sign(s21_decimal *value, int sign);
void set_scale(s21_decimal *value, int scale);
void add_big_decimals(s21_BIG_decimal value_1, s21_BIG_decimal value_2,
                      s21_BIG_decimal *result);
void set_BIG_bit(s21_BIG_decimal *value, int index, int bit_value);
void shift_left_big(s21_BIG_decimal *value, int shift);
int is_something_in_extra_bits(const s21_BIG_decimal *ptr_big);
int big_to_decimal(s21_BIG_decimal big, s21_decimal *result,
                   int *ptr_result_scale, int result_sign);
void decimal_to_big(s21_decimal value, s21_BIG_decimal *big);
int get_BIG_bit(s21_BIG_decimal value, int index);
int power(s21_decimal value);
int sign(s21_decimal value);
int is_zero_big_decimal(const s21_BIG_decimal *ptr_big);
void div_ten_big(s21_BIG_decimal *ptr_big, s21_BIG_decimal *ptr_last_digit);
void mul_ten_n_times_big(s21_BIG_decimal *ptr_big, int n);
int compare_big_decimals(s21_BIG_decimal *ptr_big_1,
                         s21_BIG_decimal *ptr_big_2);
int is_even_big(s21_BIG_decimal big);
void set_scale_decimal(s21_decimal *ptr_decimal, int scale);
void set_sign_decimal(s21_decimal *ptr_decimal);
void set_bit_int(int *ptr_int, int index, int bit);
void bit_div(s21_BIG_decimal dividend, s21_BIG_decimal divisor,
             s21_BIG_decimal *big_result, s21_BIG_decimal *ptr_remainder);
void mul_ten_big(s21_BIG_decimal *ptr_big);
int get_index_of_highest_bit(s21_BIG_decimal *ptr_big);
void bit_subtraction(s21_BIG_decimal big_1, s21_BIG_decimal big_2,
                     s21_BIG_decimal *ptr_result);
s21_decimal s21_decimal_zero(void);
int divten(s21_decimal *value);
int multiten(s21_BIG_decimal *value);
int get_scale_decimal(s21_decimal decimal);
int division_with_remainder(s21_BIG_decimal dividend, int scale_dividend,
                            s21_BIG_decimal divisor,
                            s21_BIG_decimal *ptr_result);
void clear_sign_decimal(s21_decimal *ptr_decimal);
void zero_big_decimal(s21_BIG_decimal *ptr_big);
void set_bit_decimal(s21_decimal *ptr_decimal, int index, int bit);

#endif