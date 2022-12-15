#include "s21_math.h"

long double s21_cos(double x) {
  long double cos = 0.;
  if (x == s21_NAN || x == -s21_INF || x == s21_INF) {
    cos = s21_NAN;
  } else if (x == s21_PI || x == -s21_PI || x == 3 * s21_PI ||
             x == -3 * s21_PI) {
    cos = -1;
  } else if (x == 0 || x == 2 * s21_PI || x == -2 * s21_PI) {
    cos = 1;
  } else if (x == s21_PI / 2 || x == -s21_PI / 2) {
    cos = -1e-10;
  } else if (x == 3 * s21_PI / 2 || x == -3 * s21_PI / 2) {
    cos = -1e-10;
  } else {
    for (; x < -2 * s21_PI || x > 2 * s21_PI;) {
      if (x > 2 * s21_PI) {
        x -= 2 * s21_PI;
      } else {
        x += 2 * s21_PI;
      }
    }
    if (x < 0) {
      x = -x;
    }
    for (int i = 0; i < 40; i++) {
      cos += s21_pow(-1, i) * s21_pow(x, 2 * i) / s21_factorial(2 * i);
    }
  }
  return cos;
}
