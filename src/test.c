#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

double max_inf = 1.0 / 0.0;
double min_inf = -1.0 / 0.0;
double max_nan = 0.0 / 0.0;
double min_nan = -0.0 / 0.0;

double PI_6 = M_PI_2 / 3;
double PI_56 = M_PI_2 * 5;
double PI_3 = M_PI / 3;

// ######################### ventureb tests #########################

START_TEST(ceil_tests) {
  ck_assert_ldouble_infinite(s21_ceil(max_inf));
  ck_assert_ldouble_infinite(s21_ceil(min_inf));
  ck_assert_ldouble_nan(s21_ceil(max_nan));
  ck_assert_ldouble_nan(s21_ceil(min_nan));
  ck_assert_ldouble_eq(s21_ceil(max_inf), ceil(max_inf));
  ck_assert_ldouble_eq(s21_ceil(min_inf), ceil(min_inf));
  ck_assert_ldouble_eq(s21_ceil(0), ceil(0));
  ck_assert_ldouble_eq(s21_ceil(-0), ceil(-0));
  ck_assert_ldouble_eq(s21_ceil(4), ceil(4));
  ck_assert_ldouble_eq(s21_ceil(-4), ceil(-4));
  ck_assert_ldouble_eq(s21_ceil(-0.42), ceil(-0.42));
  ck_assert_ldouble_eq(s21_ceil(0.42), ceil(0.42));
  ck_assert_ldouble_eq(s21_ceil(0.5), ceil(0.5));
  ck_assert_ldouble_eq(s21_ceil(-0.5), ceil(-0.5));
  ck_assert_ldouble_eq(s21_ceil(-932104599.422199), ceil(-932104599.422199));
  ck_assert_ldouble_eq(s21_ceil(932104599.422199), ceil(932104599.422199));
  ck_assert_ldouble_eq(s21_ceil(-0.00000000000000045),
                       ceil(-0.00000000000000045));
}
END_TEST

START_TEST(floor_tests) {
  ck_assert_ldouble_infinite(s21_floor(max_inf));
  ck_assert_ldouble_infinite(s21_floor(min_inf));
  ck_assert_ldouble_nan(s21_floor(max_nan));
  ck_assert_ldouble_nan(s21_floor(min_nan));
  ck_assert_ldouble_eq(s21_floor(max_inf), floor(max_inf));
  ck_assert_ldouble_eq(s21_floor(min_inf), floor(min_inf));
  ck_assert_ldouble_eq(s21_ceil(0), ceil(0));
  ck_assert_ldouble_eq(s21_ceil(-0), ceil(-0));
  ck_assert_ldouble_eq(s21_ceil(4), ceil(4));
  ck_assert_ldouble_eq(s21_ceil(-4), ceil(-4));
  ck_assert_ldouble_eq(s21_ceil(-0.42), ceil(-0.42));
  ck_assert_ldouble_eq(s21_ceil(0.42), ceil(0.42));
  ck_assert_ldouble_eq(s21_ceil(0.5), ceil(0.5));
  ck_assert_ldouble_eq(s21_ceil(-0.5), ceil(-0.5));
  ck_assert_ldouble_eq(s21_floor(-932104599.422199), floor(-932104599.422199));
  ck_assert_ldouble_eq(s21_floor(932104599.422199), floor(932104599.422199));
  ck_assert_ldouble_eq(s21_floor(-0.0000000000000000000042),
                       floor(-0.0000000000000000000042));
}
END_TEST

START_TEST(fmod_tests) {
  ck_assert_ldouble_nan(s21_fmod(max_inf, max_inf));
  ck_assert_ldouble_nan(s21_fmod(max_inf, min_inf));
  ck_assert_ldouble_nan(s21_fmod(max_inf, max_nan));
  ck_assert_ldouble_nan(s21_fmod(max_inf, min_nan));
  ck_assert_ldouble_nan(s21_fmod(min_inf, max_inf));
  ck_assert_ldouble_nan(s21_fmod(min_inf, min_inf));
  ck_assert_ldouble_nan(s21_fmod(min_inf, max_nan));
  ck_assert_ldouble_nan(s21_fmod(min_inf, min_nan));
  ck_assert_ldouble_nan(s21_fmod(max_nan, max_inf));
  ck_assert_ldouble_nan(s21_fmod(max_nan, min_inf));
  ck_assert_ldouble_nan(s21_fmod(max_nan, max_nan));
  ck_assert_ldouble_nan(s21_fmod(max_nan, min_nan));
  ck_assert_ldouble_nan(s21_fmod(min_nan, max_inf));
  ck_assert_ldouble_nan(s21_fmod(min_nan, min_inf));
  ck_assert_ldouble_nan(s21_fmod(min_nan, max_nan));
  ck_assert_ldouble_nan(s21_fmod(min_nan, min_nan));
  ck_assert_ldouble_nan(s21_fmod(max_inf, 2.1));
  ck_assert_ldouble_nan(s21_fmod(min_inf, 2.1));
  ck_assert_ldouble_nan(s21_fmod(max_nan, 2.1));
  ck_assert_ldouble_nan(s21_fmod(min_nan, 2.1));
  ck_assert_ldouble_nan(s21_fmod(max_inf, -2.1));
  ck_assert_ldouble_nan(s21_fmod(min_inf, -2.1));
  ck_assert_ldouble_nan(s21_fmod(max_nan, -2.1));
  ck_assert_ldouble_nan(s21_fmod(min_nan, -2.1));
  ck_assert_ldouble_nan(s21_fmod(max_inf, 0));
  ck_assert_ldouble_nan(s21_fmod(min_inf, -0));
  ck_assert_ldouble_nan(s21_fmod(max_nan, 0));
  ck_assert_ldouble_nan(s21_fmod(min_nan, -0));
  ck_assert_ldouble_nan(s21_fmod(2.1, max_nan));
  ck_assert_ldouble_nan(s21_fmod(2.1, min_nan));
  ck_assert_ldouble_nan(s21_fmod(2.1, 0));
  ck_assert_ldouble_nan(s21_fmod(2.1, -0));
  ck_assert_ldouble_eq_tol(s21_fmod(2.1, max_inf), fmod(2.1, max_inf), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(2.1, min_inf), fmod(2.1, min_inf), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(0, 2.1), fmod(0, 2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(-0, 2.1), fmod(-0, 2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(2.1, 0.5), fmod(2.1, 0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(2.1, -0.5), fmod(2.1, -0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(-2.1, 0.5), fmod(-2.1, 0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(-2.1, -0.5), fmod(-2.1, -0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(666666.4, 1.5), fmod(666666.4, 1.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(666666.4, -1.5), fmod(666666.4, -1.5),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(4.2, 21.2), fmod(4.2, 21.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(4.2, -21.2), fmod(4.2, -21.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(-4.2, -21.2), fmod(-4.2, -21.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(0.0000000004482, 21.2),
                           fmod(0.0000000004482, 21.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(0.0000000004482, 0.0000042),
                           fmod(0.0000000004482, 0.0000042), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(2000421.21, 0.0000042),
                           fmod(2000421.21, 0.0000042), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(42219878.03, 0.021),
                           fmod(42219878.03, 0.021), 1e-6);
}
END_TEST

START_TEST(sqrt_tests) {
  ck_assert_ldouble_infinite(s21_sqrt(max_inf));
  ck_assert_ldouble_nan(s21_sqrt(min_inf));
  ck_assert_ldouble_nan(s21_sqrt(max_nan));
  ck_assert_ldouble_nan(s21_sqrt(min_nan));
  ck_assert_ldouble_nan(s21_sqrt(-100));
  ck_assert_ldouble_nan(s21_sqrt(-2.1));
  ck_assert_ldouble_nan(s21_sqrt(-0.5));
  ck_assert_ldouble_eq_tol(s21_sqrt(5.0), sqrt(5.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(-0), sqrt(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(0.5), sqrt(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(1), sqrt(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(4), sqrt(4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(2.1), sqrt(2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(5.123456789123), sqrt(5.123456789123),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(0.00000004221996), sqrt(0.00000004221996),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(210000000000042.12),
                           sqrt(210000000000042.12), 1e-6);
}
END_TEST

START_TEST(exp_tests) {
  ck_assert_ldouble_nan(s21_exp(max_nan));
  ck_assert_ldouble_nan(s21_exp(min_nan));
  ck_assert_ldouble_infinite(s21_exp(max_inf));
  ck_assert_ldouble_eq_tol(s21_exp(min_inf), exp(min_inf), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(0), exp(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-0), exp(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(0.5), exp(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-0.5), exp(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-1), exp(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(1), exp(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(2.1), exp(2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-2.1), exp(-2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(5.0), exp(5.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-5.0), exp(-5.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(21.0), exp(21.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-21.0), exp(-21.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(5.123456789123), exp(5.123456789123), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-5.123456789123), exp(-5.123456789123),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(0.00000004221996), exp(0.00000004221996),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-0.00000004221996), exp(-0.00000004221996),
                           1e-6);
}
END_TEST

// ######################### grangerc tests #########################

START_TEST(asin_tests) {
  ck_assert_ldouble_nan(s21_asin(max_inf));
  ck_assert_ldouble_nan(s21_asin(min_inf));
  ck_assert_ldouble_nan(s21_asin(max_nan));
  ck_assert_ldouble_nan(s21_asin(min_nan));
  ck_assert_ldouble_nan(s21_asin(1.1));
  ck_assert_ldouble_nan(s21_asin(-1.1));
  ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-0), asin(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0.5), asin(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-0.5), asin(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0.00000004221996), asin(0.00000004221996),
                           1e-6);
}
END_TEST

START_TEST(acos_tests) {
  ck_assert_ldouble_nan(s21_acos(max_inf));
  ck_assert_ldouble_nan(s21_acos(min_inf));
  ck_assert_ldouble_nan(s21_acos(max_nan));
  ck_assert_ldouble_nan(s21_acos(min_nan));
  ck_assert_ldouble_nan(s21_acos(1.1));
  ck_assert_ldouble_nan(s21_acos(-1.1));
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-0), acos(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0.5), acos(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-0.5), acos(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0.00000004221996), acos(0.00000004221996),
                           1e-6);
}
END_TEST

START_TEST(atan_tests) {
  ck_assert_ldouble_nan(s21_atan(max_nan));
  ck_assert_ldouble_nan(s21_atan(min_nan));
  ck_assert_ldouble_eq_tol(s21_atan(max_inf), atan(max_inf), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(min_inf), atan(min_inf), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-0), atan(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0.5), atan(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-0.5), atan(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(2.1), atan(2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-2.1), atan(-2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(5.123456789123), atan(5.123456789123),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0.00000004221996), atan(0.00000004221996),
                           1e-6);
}
END_TEST

START_TEST(log_tests) {
  ck_assert_ldouble_nan(s21_log(min_inf));
  ck_assert_ldouble_nan(s21_log(max_nan));
  ck_assert_ldouble_nan(s21_log(min_nan));
  ck_assert_ldouble_nan(s21_log(-0.5));
  ck_assert_ldouble_infinite(s21_log(max_inf));
  ck_assert_ldouble_infinite(s21_log(0));
  ck_assert_ldouble_infinite(s21_log(-0));
  ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(1), log(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(1.1), log(1.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(5.123456789123), log(5.123456789123), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(0.00000004221996), log(0.00000004221996),
                           1e-6);
}
END_TEST

START_TEST(pow_tests) {
  ck_assert_ldouble_nan(s21_pow(max_inf, max_nan));
  ck_assert_ldouble_nan(s21_pow(max_inf, min_nan));
  ck_assert_ldouble_nan(s21_pow(min_inf, max_nan));
  ck_assert_ldouble_nan(s21_pow(min_inf, min_nan));
  ck_assert_ldouble_nan(s21_pow(max_nan, max_inf));
  ck_assert_ldouble_nan(s21_pow(max_nan, min_inf));
  ck_assert_ldouble_nan(s21_pow(max_nan, max_nan));
  ck_assert_ldouble_nan(s21_pow(max_nan, min_nan));
  ck_assert_ldouble_nan(s21_pow(min_nan, max_inf));
  ck_assert_ldouble_nan(s21_pow(min_nan, min_inf));
  ck_assert_ldouble_nan(s21_pow(min_nan, max_nan));
  ck_assert_ldouble_nan(s21_pow(min_nan, min_nan));
  ck_assert_ldouble_nan(s21_pow(max_nan, 2.1));
  ck_assert_ldouble_nan(s21_pow(min_nan, 2.1));
  ck_assert_ldouble_nan(s21_pow(2.1, max_nan));
  ck_assert_ldouble_nan(s21_pow(2.1, min_nan));
  ck_assert_ldouble_nan(s21_pow(0, max_nan));
  ck_assert_ldouble_nan(s21_pow(0, min_nan));
  ck_assert_ldouble_infinite(s21_pow(0, min_inf));
  ck_assert_ldouble_infinite(s21_pow(max_inf, max_inf));
  ck_assert_ldouble_infinite(s21_pow(min_inf, max_inf));
  ck_assert_ldouble_infinite(s21_pow(max_inf, 2.1));
  ck_assert_ldouble_infinite(s21_pow(min_inf, 2.1));
  ck_assert_ldouble_infinite(s21_pow(2.1, max_inf));
  ck_assert_ldouble_infinite(s21_pow(-2.1, max_inf));
  ck_assert_ldouble_eq_tol(s21_pow(0, max_inf), pow(0, max_inf), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(2.1, min_inf), pow(2.1, min_inf), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-2.1, min_inf), pow(-2.1, min_inf), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(max_inf, -2.1), pow(max_inf, -2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(min_inf, -2.1), pow(min_inf, -2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(max_inf, min_inf), pow(max_inf, min_inf),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(min_inf, min_inf), pow(min_inf, min_inf),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, 0), pow(0, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-0, -0), pow(-0, -0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-0, 2.1), pow(-0, 2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, 2.1), pow(0, 2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-0, 2.1), pow(-0, 2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(2.1, 0), pow(2.1, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(2.1, -0), pow(2.1, -0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(2.1, 0.5), pow(2.1, 0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(2.1, -0.5), pow(2.1, -0.5), 1e-6);
  ck_assert_ldouble_nan(s21_pow(-2.1, 0.5));
  ck_assert_ldouble_nan(s21_pow(-2.1, -0.5));
  ck_assert_ldouble_nan(s21_pow(-2.1, 2.1));
  ck_assert_ldouble_nan(s21_pow(-2.1, -2.1));
  ck_assert_ldouble_eq_tol(s21_pow(-2.1, 2), pow(-2.1, 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(2.1, 2), pow(2.1, 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-2.1, -1), pow(-2.1, -1), 1e-6);
  ck_assert_ldouble_nan(s21_pow(-2.1, -1.2));
  ck_assert_ldouble_nan(s21_pow(-2.1, -0.4));
  ck_assert_ldouble_eq_tol(s21_pow(2.1, 1), pow(2.1, 1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(2.1, 3), pow(2.1, 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(2.1, -3), pow(2.1, -3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(666666.4, -1.5), pow(666666.4, -1.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(3.3, 13.2), pow(3.3, 13.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(3.3, -24.2), pow(3.3, -24.2), 1e-6);
  ck_assert_ldouble_nan(s21_pow(-3.3, -24.2));
}
END_TEST

// ######################### migdalia tests #########################

START_TEST(sin_tests) {
  ck_assert_ldouble_nan(s21_sin(max_inf));
  ck_assert_ldouble_nan(s21_sin(min_inf));
  ck_assert_ldouble_nan(s21_sin(max_nan));
  ck_assert_ldouble_nan(s21_sin(min_nan));
  ck_assert_ldouble_eq_tol(s21_sin(M_PI_2), sin(M_PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-M_PI_2), sin(-M_PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(PI_3), sin(PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-PI_3), sin(-PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(PI_6), sin(PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-PI_6), sin(-PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(PI_56), sin(PI_56), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-PI_56), sin(-PI_56), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-0), sin(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0.5), sin(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-0.5), sin(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-1), sin(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(1), sin(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(1.1), sin(1.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-2.1), sin(-2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(5.123456789123), sin(5.123456789123), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-5.123456789123), cos(-5.123456789123),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0.00000004221996), sin(0.00000004221996),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-0.00000004221996), cos(-0.00000004221996),
                           1e-6);
}
END_TEST

START_TEST(cos_tests) {
  ck_assert_ldouble_nan(s21_cos(max_inf));
  ck_assert_ldouble_nan(s21_cos(min_inf));
  ck_assert_ldouble_nan(s21_cos(max_nan));
  ck_assert_ldouble_nan(s21_cos(min_nan));
  ck_assert_ldouble_eq_tol(s21_cos(M_PI_2), cos(M_PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-M_PI_2), cos(-M_PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(PI_3), cos(PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-PI_3), cos(-PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(PI_6), cos(PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-PI_6), cos(-PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(PI_56), cos(PI_56), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-PI_56), cos(-PI_56), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-0), cos(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0.5), cos(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-0.5), cos(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(1), cos(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-1), cos(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(2.1), cos(2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-2.1), cos(-2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(5.123456789123), cos(5.123456789123), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-5.123456789123), cos(-5.123456789123),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0.00000004221996), cos(0.00000004221996),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-0.00000004221996), cos(-0.00000004221996),
                           1e-6);
}
END_TEST

START_TEST(tan_tests) {
  ck_assert_ldouble_nan(s21_tan(max_inf));
  ck_assert_ldouble_nan(s21_tan(min_inf));
  ck_assert_ldouble_nan(s21_tan(max_nan));
  ck_assert_ldouble_nan(s21_tan(min_nan));
  ck_assert_ldouble_eq_tol(s21_tan(PI_3), tan(PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-PI_3), tan(-PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(PI_6), tan(PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-PI_6), tan(-PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-0), tan(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(0.5), tan(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-0.5), tan(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(1), tan(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-1), tan(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(2.1), tan(2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-2.1), tan(-2.1), 1e-8);
  ck_assert_ldouble_eq_tol(s21_tan(5.123456789123), tan(5.123456789123), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-5.123456789123), tan(-5.123456789123),
                           1e-6);
}
END_TEST

START_TEST(abs_tests) {
  ck_assert_int_eq(s21_abs((int)min_inf), abs((int)min_inf));
  ck_assert_int_eq(s21_abs((int)max_inf), abs((int)max_inf));
  ck_assert_int_eq(s21_abs((int)max_nan), abs((int)max_nan));
  ck_assert_int_eq(s21_abs((int)min_nan), abs((int)min_nan));
  ck_assert_int_eq(s21_abs(-21), abs(-21));
  ck_assert_int_eq(s21_abs(-0), abs(-0));
  ck_assert_int_eq(s21_abs(0), abs(0));
  ck_assert_int_eq(s21_abs(21), abs(21));
}
END_TEST

START_TEST(fabs_tests) {
  ck_assert_ldouble_infinite(s21_fabs(min_inf));
  ck_assert_ldouble_infinite(s21_fabs(max_inf));
  ck_assert_ldouble_nan(s21_fabs(max_nan));
  ck_assert_ldouble_nan(s21_fabs(min_nan));
  ck_assert_ldouble_eq_tol(s21_fabs(0.0), fabs(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(-0.0), fabs(-0.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(0.5), fabs(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(-0.5), fabs(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(1.0), fabs(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(-1.0), fabs(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(2.1), fabs(2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(-2.1), fabs(-2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(5.123456789123), fabs(5.123456789123),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(-5.123456789123), fabs(-5.123456789123),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(0.00000004221996), fabs(0.00000004221996),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(-0.00000004221996), fabs(-0.00000004221996),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(170000000000000.1), fabs(170000000000000.1),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(-170000000000000.1),
                           fabs(-170000000000000.1), 1e-6);
}
END_TEST

// ######################### test suite #########################

Suite *test_suite(void) {
  Suite *s = suite_create("Test Suite");
  TCase *tc_ventureb = tcase_create("Test Case: ventureb");
  TCase *tc_grangerc = tcase_create("Test Case: grangerc");
  TCase *tc_migdalia = tcase_create("Test Case: migdalia");

  tcase_add_test(tc_ventureb, ceil_tests);
  tcase_add_test(tc_ventureb, floor_tests);
  tcase_add_test(tc_ventureb, fmod_tests);
  tcase_add_test(tc_ventureb, sqrt_tests);
  tcase_add_test(tc_ventureb, exp_tests);

  tcase_add_test(tc_grangerc, pow_tests);
  tcase_add_test(tc_grangerc, asin_tests);
  tcase_add_test(tc_grangerc, acos_tests);
  tcase_add_test(tc_grangerc, atan_tests);
  tcase_add_test(tc_grangerc, log_tests);

  tcase_add_test(tc_migdalia, abs_tests);
  tcase_add_test(tc_migdalia, fabs_tests);
  tcase_add_test(tc_migdalia, sin_tests);
  tcase_add_test(tc_migdalia, cos_tests);
  tcase_add_test(tc_migdalia, tan_tests);

  suite_add_tcase(s, tc_ventureb);
  suite_add_tcase(s, tc_grangerc);
  suite_add_tcase(s, tc_migdalia);
  return s;
}

// ######################### execution #########################

int main() {
  Suite *s = test_suite();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  // if (number_failed == 0) printf("Congratulations! ");
  // printf("%d tests failed", number_failed);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
