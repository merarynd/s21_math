#include "s21_math.h"

long double s21_log(double x) {
  long double flag = 1, pow = 0, count = 2, rezult, temp;
  if (x == s21_INF) {
    rezult = x;
  } else if (x != x || x == -s21_INF) {
    rezult = s21_NAN;
  } else if (x == 0) {
    rezult = -s21_INF;
  } else {
    if (x < 0) {
    x = x * -1;
    flag = flag * -1;
  } else {
    x = x * 1;
    flag = flag * 1;
  }
  while ((x >= 10) || (x < 1 && x > 0)) {
    if (x < 1 && x > 0) {
      x = x * 10;
      pow = pow - 1;
    } else {
      x = x * 0.1;
      pow = pow + 1;
    }
  }
  x = flag * x / 10;
  if (x < 0) {
    rezult = -s21_NAN;
  }  else {
    x--;
    rezult = x;
    temp = x;
    while (s21_fabs(rezult) > s21_EPS) {
      rezult = rezult * -x * (count - 1) / count;
      count = count + 1;
      temp = temp + rezult;
    }
    rezult = temp + (pow + 1) * S21_M_LN10;
  }
  }
  
  return (x == 1) ? 0 : rezult;
}