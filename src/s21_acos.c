#include "s21_math.h"

long double s21_acos(double x) {
  long double acos = 0.;
  if (x == 1.) {
    acos = 0.;
  } else if (x == -1.) {
    acos = s21_PI;
  } else if (x == 0) {
    acos = s21_PI_2;
  } else if (x == 0.7071067811865475244) {
    acos = s21_PI / 4;
  } else if (x == -0.7071067811865475244) {
    acos = 3 * s21_PI / 4;
  } else if (x == -s21_sqrt(3) / 2) {
    acos = 5 * s21_PI / 6;
  } else if (x == s21_sqrt(3) / 2) {
    acos = s21_PI / 6;
  } else if (x == -1 / 2) {
    acos = 2 * s21_PI / 3;
  } else if (x == 1 / 2) {
    acos = s21_PI / 3;
  } else if (x > 0. && x < 1.) {
    acos = s21_atan(s21_sqrt(1 - x * x) / x);
  } else if (x > -1. && x < 0.) {
    acos = s21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  } else {
    acos = s21_NAN;
  }
  return acos;
}
