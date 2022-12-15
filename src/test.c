#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(s21_abs_test) {
  ck_assert_int_eq(abs(-1), s21_abs(-1));
  ck_assert_int_eq(abs(0), s21_abs(0));
  ck_assert_int_eq(abs(100), s21_abs(100));

  ck_assert_int_eq(abs((int)INFINITY), s21_abs((int)INFINITY));
  ck_assert_int_eq(abs((int)-INFINITY), s21_abs((int)-INFINITY));
  ck_assert_int_eq(abs((int)NAN), s21_abs((int)NAN));
}
END_TEST

START_TEST(s21_fabs_test) {
  ck_assert_int_eq(fabs(-8.55), s21_fabs(-8.55));
  ck_assert_int_eq(fabs(-0.33), s21_fabs(-0.33));
  ck_assert_int_eq(fabs(0), s21_fabs(0));
  ck_assert_int_eq(fabs(0.5), s21_fabs(0.5));
  ck_assert_int_eq(fabs(1.17394757593), s21_fabs(1.17394757593));
  ck_assert_int_eq(fabs(100.1), s21_fabs(100.1));
  ck_assert_int_eq(abs((int)INFINITY), s21_abs((int)INFINITY));
  ck_assert_int_eq(abs((int)-INFINITY), s21_abs((int)-INFINITY));
  ck_assert_int_eq(abs((int)NAN), s21_abs((int)NAN));
}
END_TEST

START_TEST(s21_ceil_test) {
  ck_assert_ldouble_eq(ceil(-100.97), s21_ceil(-100.97));
  ck_assert_ldouble_eq(ceil(-11.2), s21_ceil(-11.2));
  ck_assert_ldouble_eq(ceil(-0.1112), s21_ceil(-0.1112));
  ck_assert_ldouble_eq(ceil(0), s21_ceil(0));
  ck_assert_ldouble_eq(ceil(0.0), s21_ceil(0.0));
  ck_assert_ldouble_eq(ceil(0.00001), s21_ceil(0.00001));
  ck_assert_ldouble_eq(ceil(21.1567), s21_ceil(21.1567));
  ck_assert_ldouble_eq(ceil(34.999), s21_ceil(34.999));

  ck_assert_ldouble_infinite(ceil(INFINITY));
  ck_assert_ldouble_infinite(s21_ceil(INFINITY));
  ck_assert_ldouble_nan(s21_ceil(NAN));
  ck_assert_ldouble_nan(ceil(NAN));
}
END_TEST

START_TEST(s21_floor_test) {
  ck_assert_ldouble_eq(floor(-100.97), s21_floor(-100.97));
  ck_assert_ldouble_eq(floor(-11.2), s21_floor(-11.2));
  ck_assert_ldouble_eq(floor(-0.1112), s21_floor(-0.1112));
  ck_assert_ldouble_eq(floor(0), s21_floor(0));
  ck_assert_ldouble_eq(floor(0.0), s21_floor(0.0));
  ck_assert_ldouble_eq(floor(0.00001), s21_floor(0.00001));
  ck_assert_ldouble_eq(floor(21.1567), s21_floor(21.1567));
  ck_assert_ldouble_eq(floor(34.999), s21_floor(34.999));

  ck_assert_ldouble_infinite(floor(INFINITY));
  ck_assert_ldouble_infinite(s21_floor(INFINITY));
  ck_assert_ldouble_nan(s21_floor(NAN));
  ck_assert_ldouble_nan(floor(NAN));
}
END_TEST

START_TEST(s21_log_test) {
  ck_assert_ldouble_eq_tol(log(123.895304), s21_log(123.895304), 1e-6);
  ck_assert_ldouble_eq_tol(log(0.003), s21_log(0.003), 1e-6);
  ck_assert_ldouble_eq_tol(log(0.5), s21_log(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(log(0.783645), s21_log(0.783645), 1e-6);
  ck_assert_ldouble_eq_tol(log(1), s21_log(1), 1e-6);
  ck_assert_ldouble_eq_tol(log(1.0), s21_log(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(log(M_E), s21_log(M_E), 1e-6);
  ck_assert_ldouble_eq_tol(log(200), s21_log(200), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(DBL_MAX), log(DBL_MAX), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(9.5463728645e6), log(9.5463728645e6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(5637385895.018274), log(5637385895.018274),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_log(1.1e-10), log(1.1e-10), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(1.1e-55), log(1.1e-55), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(1.1e-70), log(1.1e-70), 1e-6);

  ck_assert_ldouble_infinite(log(0));
  ck_assert_ldouble_infinite(s21_log(0));
  ck_assert_ldouble_infinite(log(INFINITY));
  ck_assert_ldouble_nan(log(-INFINITY));
  ck_assert_ldouble_infinite(s21_log(INFINITY));
  ck_assert_ldouble_nan(s21_log(-INFINITY));
  ck_assert_ldouble_nan(log(NAN));
  ck_assert_ldouble_nan(s21_log(NAN));
}
END_TEST

START_TEST(s21_sqrt_test) {
  ck_assert_ldouble_eq_tol(sqrt(0.0), s21_sqrt(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(sqrt(1.0), s21_sqrt(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(sqrt(16), s21_sqrt(16), 1e-6);
  ck_assert_ldouble_eq_tol(sqrt(625), s21_sqrt(625), 1e-6);
  ck_assert_ldouble_eq_tol(sqrt(40), s21_sqrt(40), 1e-6);
  ck_assert_ldouble_eq_tol(sqrt(3749614273.945187), s21_sqrt(3749614273.945187),
                           1e-6);
  ck_assert_ldouble_eq_tol(sqrt(-0.0), s21_sqrt(-0.0), 1e-6);

  ck_assert_ldouble_eq_tol(sqrt(M_PI), s21_sqrt(M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(sqrt(2), s21_sqrt(2), 1e-6);
  ck_assert_ldouble_nan(s21_sqrt(-2));
  ck_assert_ldouble_eq_tol(sqrt(3), s21_sqrt(3), 1e-6);
  ck_assert_ldouble_nan(s21_sqrt(-3));

  ck_assert_ldouble_infinite(sqrt(INFINITY));
  ck_assert_ldouble_infinite(s21_sqrt(INFINITY));
  ck_assert_ldouble_nan(sqrt(NAN));
  ck_assert_ldouble_nan(s21_sqrt(NAN));
  ck_assert_ldouble_nan(sqrt(-454675.2346));
  ck_assert_ldouble_nan(s21_sqrt(-454675.2346));
}
END_TEST

START_TEST(s21_exp_test) {
  ck_assert_ldouble_eq_tol(exp(-21.2), s21_exp(-21.2), 1e-6);
  ck_assert_ldouble_eq_tol(exp(-10), s21_exp(-10), 1e-6);
  ck_assert_ldouble_eq_tol(exp(0), s21_exp(0), 1e-6);
  ck_assert_ldouble_eq_tol(exp(1), s21_exp(1), 1e-6);
  ck_assert_ldouble_eq_tol(exp(5), s21_exp(5), 1e-6);
}
END_TEST

START_TEST(s21_fmod_test) {
  ck_assert_ldouble_eq(fmod(-100400, -8), s21_fmod(-100400, -8));
  ck_assert_ldouble_eq(fmod(-100.97, -100), s21_fmod(-100.97, -100));
  ck_assert_ldouble_eq(fmod(-21, -12.3), s21_fmod(-21, -12.3));
  ck_assert_ldouble_eq(fmod(-1.5, -1), s21_fmod(-1.5, -1));
  ck_assert_ldouble_eq(fmod(0, 0.1), s21_fmod(0, 0.1));
  ck_assert_ldouble_eq(fmod(1.11, 1.0), s21_fmod(1.11, 1.0));
  ck_assert_ldouble_eq(fmod(5, 5), s21_fmod(5, 5));
  ck_assert_ldouble_eq(fmod(444, 444.0006), s21_fmod(444, 444.0006));
  ck_assert_ldouble_eq(fmod(800400, 8), s21_fmod(800400, 8));
}
END_TEST

START_TEST(s21_atan_test) {
  ck_assert_ldouble_eq_tol(atan(-sqrt(3)), s21_atan(-sqrt(3)), 1e-6);
  ck_assert_ldouble_eq_tol(atan(-1.0), s21_atan(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(atan(-0.5), s21_atan(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(atan(-0.1), s21_atan(-0.1), 1e-6);
  ck_assert_ldouble_eq_tol(atan(-sqrt(3) / 3), s21_atan(-sqrt(3) / 3), 1e-6);
  ck_assert_ldouble_eq_tol(atan(-sqrt(3) / 2), s21_atan(-sqrt(3) / 2), 1e-6);
  ck_assert_ldouble_eq_tol(atan(-sqrt(2) / 2), s21_atan(-sqrt(2) / 2), 1e-6);
  ck_assert_ldouble_eq_tol(atan(0.0), s21_atan(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(atan(0.1), s21_atan(0.1), 1e-6);
  ck_assert_ldouble_eq_tol(atan(0.5), s21_atan(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(atan(sqrt(3) / 3), s21_atan(sqrt(3) / 3), 1e-6);
  ck_assert_ldouble_eq_tol(atan(sqrt(3) / 2), s21_atan(sqrt(3) / 2), 1e-6);
  ck_assert_ldouble_eq_tol(atan(sqrt(2) / 2), s21_atan(sqrt(2) / 2), 1e-6);
  ck_assert_ldouble_eq_tol(atan(1.0), s21_atan(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(atan(sqrt(3)), s21_atan(sqrt(3)), 1e-6);
  ck_assert_ldouble_eq_tol(atan(4.2658365), s21_atan(4.2658365), 1e-6);
  ck_assert_ldouble_eq_tol(atan(-4.2658365), s21_atan(-4.2658365), 1e-6);
  ck_assert_ldouble_eq_tol(atan(4.2658365e-9), s21_atan(4.2658365e-9), 1e-6);
  ck_assert_ldouble_eq_tol(atan(-4.2658365e-9), s21_atan(-4.2658365e-9), 1e-6);
  ck_assert_ldouble_eq_tol(atan(M_PI), s21_atan(M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(atan(2 * M_PI), s21_atan(2 * M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(atan(M_PI / 2), s21_atan(M_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(atan(M_PI / -2), s21_atan(M_PI / -2), 1e-6);
  ck_assert_ldouble_eq_tol(atan(INFINITY), s21_atan(INFINITY), 1e-6);
  ck_assert_ldouble_eq_tol(M_PI / 2.0, s21_atan(INFINITY), 1e-6);
  ck_assert_ldouble_eq_tol(atan(-INFINITY), s21_atan(-INFINITY), 1e-6);
  ck_assert_ldouble_eq_tol(M_PI / -2.0, s21_atan(-INFINITY), 1e-6);
  ck_assert_ldouble_nan(s21_atan(NAN));
  ck_assert_ldouble_nan(atan(NAN));
}
END_TEST

START_TEST(s21_asin_test) {
  ck_assert_ldouble_eq_tol(asin(-1.0), s21_asin(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(asin(-0.5), s21_asin(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(asin(-0.1), s21_asin(-0.1), 1e-6);
  ck_assert_ldouble_eq_tol(asin(-sqrt(3) / 3), s21_asin(-sqrt(3) / 3), 1e-6);
  ck_assert_ldouble_eq_tol(asin(-sqrt(3) / 2), s21_asin(-sqrt(3) / 2), 1e-6);
  ck_assert_ldouble_eq_tol(asin(-sqrt(2) / 2), s21_asin(-sqrt(2) / 2), 1e-6);
  ck_assert_ldouble_eq_tol(asin(0.0), s21_asin(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(asin(0.1), s21_asin(0.1), 1e-6);
  ck_assert_ldouble_eq_tol(asin(0.5), s21_asin(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(asin(sqrt(3) / 3), s21_asin(sqrt(3) / 3), 1e-6);
  ck_assert_ldouble_eq_tol(asin(sqrt(3) / 2), s21_asin(sqrt(3) / 2), 1e-6);
  ck_assert_ldouble_eq_tol(asin(sqrt(2) / 2), s21_asin(sqrt(2) / 2), 1e-6);
  ck_assert_ldouble_eq_tol(asin(1.0), s21_asin(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(asin(4.2658365e-9), s21_asin(4.2658365e-9), 1e-6);
  ck_assert_ldouble_eq_tol(asin(M_PI / 4), s21_asin(M_PI / 4), 1e-6);
  ck_assert_ldouble_nan(asin(M_PI));
  ck_assert_ldouble_nan(s21_asin(M_PI));
  ck_assert_ldouble_nan(asin(sqrt(3)));
  ck_assert_ldouble_nan(s21_asin(sqrt(3)));
  ck_assert_ldouble_nan(asin(-5));
  ck_assert_ldouble_nan(s21_asin(-5));
  ck_assert_ldouble_nan(asin(5));
  ck_assert_ldouble_nan(s21_asin(5));
  ck_assert_ldouble_nan(asin(INFINITY));
  ck_assert_ldouble_nan(s21_asin(INFINITY));
  ck_assert_ldouble_nan(asin(-INFINITY));
  ck_assert_ldouble_nan(s21_asin(-INFINITY));
  ck_assert_ldouble_nan(asin(NAN));
  ck_assert_ldouble_nan(s21_asin(NAN));
}
END_TEST

START_TEST(s21_acos_test) {
  ck_assert_ldouble_eq_tol(acos(-1.0), s21_acos(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(acos(-0.5), s21_acos(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(acos(-0.1), s21_acos(-0.1), 1e-6);
  ck_assert_ldouble_eq_tol(acos(-sqrt(3) / 3), s21_acos(-sqrt(3) / 3), 1e-6);
  ck_assert_ldouble_eq_tol(acos(-sqrt(3) / 2), s21_acos(-sqrt(3) / 2), 1e-6);
  ck_assert_ldouble_eq_tol(acos(-sqrt(2) / 2), s21_acos(-sqrt(2) / 2), 1e-6);
  ck_assert_ldouble_eq_tol(acos(0.0), s21_acos(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(acos(0.1), s21_acos(0.1), 1e-6);
  ck_assert_ldouble_eq_tol(acos(0.5), s21_acos(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(acos(sqrt(3) / 3), s21_acos(sqrt(3) / 3), 1e-6);
  ck_assert_ldouble_eq_tol(acos(sqrt(3) / 2), s21_acos(sqrt(3) / 2), 1e-6);
  ck_assert_ldouble_eq_tol(acos(sqrt(2) / 2), s21_acos(sqrt(2) / 2), 1e-6);
  ck_assert_ldouble_eq_tol(acos(1.0), s21_acos(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(acos(4.2658365e-9), s21_acos(4.2658365e-9), 1e-6);
  ck_assert_ldouble_eq_tol(acos(M_PI / 4), s21_acos(M_PI / 4), 1e-6);
  ck_assert_ldouble_nan(acos(M_PI));
  ck_assert_ldouble_nan(s21_acos(M_PI));
  ck_assert_ldouble_nan(acos(sqrt(3)));
  ck_assert_ldouble_nan(s21_acos(sqrt(3)));
  ck_assert_ldouble_nan(acos(-5));
  ck_assert_ldouble_nan(s21_acos(-5));
  ck_assert_ldouble_nan(acos(5));
  ck_assert_ldouble_nan(s21_acos(5));
  ck_assert_ldouble_nan(acos(INFINITY));
  ck_assert_ldouble_nan(s21_acos(INFINITY));
  ck_assert_ldouble_nan(acos(-INFINITY));
  ck_assert_ldouble_nan(s21_acos(-INFINITY));
  ck_assert_ldouble_nan(acos(NAN));
  ck_assert_ldouble_nan(s21_acos(NAN));
}
END_TEST

START_TEST(s21_sin_test) {
  ck_assert_ldouble_eq_tol(sin(-1.0), s21_sin(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(sin(-0.5), s21_sin(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(sin(-0.1), s21_sin(-0.1), 1e-6);
  ck_assert_ldouble_eq_tol(sin(-2 * M_PI), s21_sin(-2 * M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(sin(-3 * M_PI / 2), s21_sin(-3 * M_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(sin(-M_PI / 6), s21_sin(-M_PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(sin(-M_PI / 4), s21_sin(-M_PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(sin(-M_PI / 3), s21_sin(-M_PI / 3), 1e-6);
  ck_assert_ldouble_eq_tol(sin(-M_PI / 2), s21_sin(-M_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(sin(-M_PI), s21_sin(-M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(sin(0.0), s21_sin(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(sin(0.1), s21_sin(0.1), 1e-6);
  ck_assert_ldouble_eq_tol(sin(0.5), s21_sin(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(sin(M_PI), s21_sin(M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(sin(2 * M_PI), s21_sin(2 * M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(sin(-2 * M_PI), s21_sin(-2 * M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(sin(3 * M_PI), s21_sin(3 * M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(sin(-3 * M_PI), s21_sin(-3 * M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(sin(M_PI / 2), s21_sin(M_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(sin(-M_PI / 3), s21_sin(-M_PI / 3), 1e-6);
  ck_assert_ldouble_eq_tol(sin(-M_PI / 4), s21_sin(-M_PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(sin(-M_PI / 6), s21_sin(-M_PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(sin(3 * M_PI / 2), s21_sin(3 * M_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(sin(1.0), s21_sin(1.0), 1e-6);

  ck_assert_ldouble_nan(sin(INFINITY));
  ck_assert_ldouble_nan(s21_sin(INFINITY));
  ck_assert_ldouble_nan(sin(-INFINITY));
  ck_assert_ldouble_nan(s21_sin(-INFINITY));
  ck_assert_ldouble_nan(s21_sin(NAN));
  ck_assert_ldouble_nan(sin(NAN));
}
END_TEST

START_TEST(s21_cos_test) {
  ck_assert_ldouble_eq_tol(cos(-1.0), s21_cos(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(cos(-0.5), s21_cos(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(cos(-0.1), s21_cos(-0.1), 1e-6);
  ck_assert_ldouble_eq_tol(cos(-2 * M_PI), s21_cos(-2 * M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(cos(-3 * M_PI / 2), s21_cos(-3 * M_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(cos(-M_PI / 6), s21_cos(-M_PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(cos(-M_PI / 4), s21_cos(-M_PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(cos(-M_PI / 3), s21_cos(-M_PI / 3), 1e-6);
  ck_assert_ldouble_eq_tol(cos(-M_PI / 2), s21_cos(-M_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(cos(-M_PI), s21_cos(-M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(cos(0.0), s21_cos(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(cos(0.1), s21_cos(0.1), 1e-6);
  ck_assert_ldouble_eq_tol(cos(0.5), s21_cos(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(cos(M_PI), s21_cos(M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(cos(2 * M_PI), s21_cos(2 * M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(cos(3 * M_PI), s21_cos(3 * M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(cos(-3 * M_PI), s21_cos(-3 * M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(cos(M_PI / 2), s21_cos(M_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(cos(M_PI / 3), s21_cos(M_PI / 3), 1e-6);
  ck_assert_ldouble_eq_tol(cos(M_PI / 4), s21_cos(M_PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(cos(M_PI / 6), s21_cos(M_PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(cos(3 * M_PI / 2), s21_cos(3 * M_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(cos(1.0), s21_cos(1.0), 1e-6);

  ck_assert_ldouble_nan(cos(INFINITY));
  ck_assert_ldouble_nan(s21_cos(INFINITY));
  ck_assert_ldouble_nan(cos(-INFINITY));
  ck_assert_ldouble_nan(s21_cos(-INFINITY));
  ck_assert_ldouble_nan(s21_cos(NAN));
  ck_assert_ldouble_nan(cos(NAN));
}
END_TEST

START_TEST(s21_tan_test) {
  ck_assert_ldouble_eq_tol(tan(-1.0), s21_tan(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(tan(-0.5), s21_tan(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(tan(-0.1), s21_tan(-0.1), 1e-6);
  ck_assert_ldouble_eq_tol(tan(-2 * M_PI), s21_tan(-2 * M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(tan(-2 * M_PI / 2), s21_tan(-2 * M_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(tan(-3 * M_PI / 3), s21_tan(-3 * M_PI / 3), 1e-6);
  ck_assert_ldouble_eq_tol(tan(-M_PI / 6), s21_tan(-M_PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(tan(-M_PI / 4), s21_tan(-M_PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(tan(-M_PI / 3), s21_tan(-M_PI / 3), 1e-6);
  ck_assert_ldouble_eq_tol(tan(-M_PI), s21_tan(-M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(tan(0.0), s21_tan(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(tan(0.1), s21_tan(0.1), 1e-6);
  ck_assert_ldouble_eq_tol(tan(0.5), s21_tan(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(tan(M_PI), s21_tan(M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(tan(2 * M_PI), s21_tan(2 * M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(tan(-2 * M_PI), s21_tan(-2 * M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(tan(3 * M_PI), s21_tan(3 * M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(tan(-3 * M_PI), s21_tan(-3 * M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(tan(M_PI / 2), s21_tan(M_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(tan(-M_PI / 2), s21_tan(-M_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(tan(M_PI / 3), s21_tan(M_PI / 3), 1e-6);
  ck_assert_ldouble_eq_tol(tan(M_PI / 4), s21_tan(M_PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(tan(M_PI / 6), s21_tan(M_PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(tan(3 * M_PI / 3), s21_tan(3 * M_PI / 3), 1e-6);
  ck_assert_ldouble_eq_tol(tan(2 * M_PI), s21_tan(2 * M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(tan(1.0), s21_tan(1.0), 1e-6);

  ck_assert_ldouble_nan(tan(INFINITY));
  ck_assert_ldouble_nan(s21_tan(INFINITY));
  ck_assert_ldouble_nan(tan(-INFINITY));
  ck_assert_ldouble_nan(s21_tan(-INFINITY));
  ck_assert_ldouble_nan(s21_tan(NAN));
  ck_assert_ldouble_nan(tan(NAN));
}
END_TEST

START_TEST(s21_pow_test) {
  ck_assert_ldouble_eq_tol(pow(13.21313, 2.5), s21_pow(13.21313, 2.5), 1e-6);
  ck_assert_ldouble_eq_tol(pow(1, 0), s21_pow(1, 0), 1e-6);
  ck_assert_ldouble_eq_tol(pow(-19858, 2), s21_pow(-19858, 2), 1e-6);
  ck_assert_ldouble_eq_tol(pow(2, 10), s21_pow(2, 10), 1e-6);
  ck_assert_ldouble_eq_tol(pow(0, 2.5), s21_pow(0, 2.5), 1e-6);
  ck_assert_ldouble_eq_tol(pow(123, -2), s21_pow(123, -2), 1e-6);

  ck_assert_ldouble_infinite(pow(INFINITY, INFINITY));
  ck_assert_ldouble_infinite(s21_pow(INFINITY, INFINITY));
  ck_assert_ldouble_eq_tol(pow(-INFINITY, -INFINITY),
                           s21_pow(-INFINITY, -INFINITY), 1e-6);
  ck_assert_ldouble_nan(s21_pow(NAN, NAN));

  ck_assert_ldouble_nan(pow(6, NAN));
  ck_assert_ldouble_nan(s21_pow(6, NAN));
  ck_assert_ldouble_nan(pow(NAN, 6));
  ck_assert_ldouble_nan(s21_pow(NAN, 6));
}
END_TEST

int main() {
  int failed = 0;
  Suite *s = suite_create("Core");
  TCase *tc = tcase_create("Core");
  SRunner *runner = srunner_create(s);

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_abs_test);
  tcase_add_test(tc, s21_fabs_test);
  tcase_add_test(tc, s21_ceil_test);
  tcase_add_test(tc, s21_floor_test);
  tcase_add_test(tc, s21_log_test);
  tcase_add_test(tc, s21_sqrt_test);
  tcase_add_test(tc, s21_exp_test);
  tcase_add_test(tc, s21_fmod_test);
  tcase_add_test(tc, s21_atan_test);
  tcase_add_test(tc, s21_asin_test);
  tcase_add_test(tc, s21_acos_test);
  tcase_add_test(tc, s21_sin_test);
  tcase_add_test(tc, s21_cos_test);
  tcase_add_test(tc, s21_tan_test);
  tcase_add_test(tc, s21_pow_test);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? 0 : 1;
}
