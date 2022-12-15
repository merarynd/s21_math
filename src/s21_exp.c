#include "s21_math.h"

long double s21_exp(double x) {
  long double dev = 1, rezult = 1;
  long double i = 1;
  int flag = 0;
  if (x < 0) {
    x *= -1;
    flag = 1;
  }
  while (s21_fabs(dev) > s21_EPS) {
    dev *= x / i;
    i++;
    rezult += dev;
    if (rezult > s21_MAX_double) {
      rezult = s21_INF;
      break;
    }
  }
  rezult = flag == 1 ? rezult > s21_MAX_double ? 0 : 1. / rezult : rezult;
  return rezult = rezult > s21_MAX_double ? s21_INF : rezult;
}
