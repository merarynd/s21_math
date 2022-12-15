#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdio.h>

#define s21_INF 1.0 / 0.0
#define s21_NAN 0.0 / 0.0
#define s21_PI 3.14159265358979323846
#define s21_E 2.7182818284590452
#define s21_EPS 1e-25
#define s21_MAX_double 1.79769313486231571e+308
#define S21_M_LN10 2.30258509299404568402
#define s21_PI_2 1.57079632679

#define is_fin(x) __builtin_isfinite(x)
#define is_nan(x) __builtin_isnan(x)
#define is_inf(x) __builtin_isinf(x)

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
long double s21_factorial(int N);

#endif  // SRC_S21_MATH_H_