#include "s21_math.h"

long double s21_fabs(double x) {
  long double result = 0;
  if (x == x && x != s21_INF) {
    if (x < 0) {
      x = x * (-1);
    }
    result = x;
  } else if (x != x) {
    result = s21_NAN;
  } else if (x == s21_NAN) {
    result = s21_INF;
  }
  return result;
}