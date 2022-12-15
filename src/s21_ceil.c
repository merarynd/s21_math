#include "s21_math.h"

long double s21_ceil(double x) {
  long double ceil_x = (long long int)x;
  long double result = 0;
  if (x == x && x != s21_INF) {
    if (x != ceil_x && s21_fabs(x) > 0.) {
      if (x > 0.) ceil_x = ceil_x + 1;
    }
    result = ceil_x;
  } else if (x != x) {
    result = s21_NAN;
  } else if (x == s21_INF) {
    result = x;
  }
  return result;
}
