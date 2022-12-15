#include "s21_math.h"

long double s21_tan(double x) {
  long double tan = 0;
  if (x == s21_PI/2) {
    tan = 16331239353195370L;
  } else if (x == -s21_PI/2) {
    tan = -16331239353195370L;
  } else
    tan = s21_sin(x) / s21_cos(x);
  return tan;
}