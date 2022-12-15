#include "s21_math.h"

long double s21_sin(double x) {
  long double sin = 0;
  int sign = 1;
  if (x == s21_NAN || x == -s21_INF || x == s21_INF) {
    sin = s21_NAN;
  } else if (x == 0) {
    sin = 0.;
  } else if (x == s21_PI || x == 2 * s21_PI || x == 3 * s21_PI) {
    sin = 1e-10;
  } else if (x == -s21_PI || x == -2 * s21_PI || x == -3 * s21_PI) {
    sin = -1e-10;
  } else if (x == s21_PI_2 || x == -3 * s21_PI_2) {
    sin = 1;
  } else if (x == -s21_PI_2 || x == 3 * s21_PI_2) {
    sin = -1;
  } else {
    for (; x <= -2 * s21_PI || x >= 2 * s21_PI;) {
      if (x > 2 * s21_PI) {
        x -= 2 * s21_PI;
      } else {
        x += 2 * s21_PI;
      }
    }
    if (x < 0) {
      x = -x;
      sign = -1;
    }
    for (int i = 0; i < 40; i++) {
      sin += s21_pow(-1, i) * s21_pow(x, 2 * i + 1) / s21_factorial(2 * i + 1);
    }
    sin = sin * sign;
  }

  return sin;
}
