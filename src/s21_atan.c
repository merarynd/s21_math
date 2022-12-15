#include "s21_math.h"

long double s21_atan(double x) {
  long double atan = 0.;
  if (x == 0) {
    atan = 0.;
  } else if (x == 1) {
    atan = s21_PI / 4;
  } else if (x == -1) {
    atan = -s21_PI / 4;
  } else if (x == s21_INF || x == -s21_INF) {
    atan = x < 0 ? -s21_PI / 2 : s21_PI / 2;
  } else if (x > -1. && x < 1.) {
    for (int i = 0; i < 40; i++) {
      atan += s21_pow(-1, i) * s21_pow(x, 1 + (2 * i)) / (1 + (2 * i));
    }
  } else if (x == s21_NAN) {
    atan = s21_NAN;
  } else {
    for (int i = 0; i < 40; i++) {
      atan += s21_pow(-1, i) * s21_pow(x, -1 - (2 * i)) / (1 + (2 * i));
    }
    atan = s21_PI * s21_sqrt(x * x) / (2 * x) - atan;
  }
  return atan;
}
