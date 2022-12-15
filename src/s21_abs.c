#include "s21_math.h"

int s21_abs(int x) {
  int result = 0, y = 0;
  if (x != s21_INF) {
    if (x < 0) {
      x = x * (-1);
    }
    y = x;
    result = y;
  }
  // } else if (x != y) {
  //   result = s21_NAN;
  // } else if (x == s21_INF) {
  //   result = s21_INF;
  // }
  return result;
}
