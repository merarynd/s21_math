#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double rezult = x;
  int flag = 0;
  if (rezult < 0) {
    flag = 1;
    rezult = s21_fabs(rezult);
  }
  if (y == 0) {
    rezult = s21_INF;
  } else {
    if (rezult != y) {
      while (s21_fabs(rezult) >= s21_fabs(y))
        rezult = s21_fabs(rezult) - s21_fabs(y);
    } else {
      rezult = 0.0;
    }
  }
  return (flag) ? -rezult : rezult;
}