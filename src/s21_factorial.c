#include "s21_math.h"

long double s21_factorial(int N) {
  long double f = 0;
  if (N < 0) {
    f = 0;
  } else if (N == 0) {
    f = 1;
  } else {
    f = N * s21_factorial(N - 1);
  }
  return f;
}