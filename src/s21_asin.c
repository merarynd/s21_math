#include "s21_math.h"

long double s21_asin(double x) {
  long double asin = 0.;
  if (x == 0) {
    asin = 0;
  } else if (x == 1.) {
    asin = s21_PI_2;
  } else if (x == -1.) {
    asin = -s21_PI_2;
  } else if (x == 0.7071067811865475244) {
    asin = s21_PI / 4;
  } else if (x == -0.7071067811865475244) {
    asin = -s21_PI / 4;
  } else if (x == s21_sqrt(3) / 2) {
    asin = s21_PI / 3;
  } else if (x == -s21_sqrt(3) / 2) {
    asin = -s21_PI / 3;
  } else if (x == 1 / 2) {
    asin = s21_PI / 6;
  } else if (x == -1 / 2) {
    asin = -s21_PI / 6;
  } else if (x > -1. && x < 1.) {
    asin = s21_atan(x / s21_sqrt(1 - x * x));
  } else {
    asin = s21_NAN;
  }
  return asin;
}
