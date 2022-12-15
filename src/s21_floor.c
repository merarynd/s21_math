#include "s21_math.h"

long double s21_floor(double x) {
  long double floor_x = (long long int)x;
  long double result = 0;
  if (x == x && x != s21_INF) {
    if (x != floor_x && x != 0) {
      if (s21_fabs(x - floor_x) > 0. && s21_fabs(x) > 0.)
        if (x < 0) floor_x = floor_x - 1;
      result = floor_x;
    }
  } else if (x != x) {
    result = s21_NAN;
  } else if (is_inf(x)) {
    result = x;
  }
  return result;
}
