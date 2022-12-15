#include "s21_math.h"

long double s21_pow(double base, double expp) {
  long double rezult = 1;
  int flag_s = 0;
  if (base < 0) {
    flag_s = 1;
  }
  if (base == -s21_INF && expp == s21_INF) {
    rezult = s21_INF;
  } else if (base == s21_INF && expp == s21_INF) {
    rezult = s21_INF;
  } else if (base == -s21_INF && expp == -s21_INF) {
    rezult = 0;
  } else if ((base == s21_NAN && expp == s21_NAN) ||
             (base == s21_NAN && expp != 0) || (base != 1 && expp == s21_NAN)) {
    rezult = s21_NAN;
  } else if ((base == 1 && expp == s21_NAN) || (base == s21_NAN && expp == 0)) {
    rezult = 1;
  } else if (base != s21_NAN && expp == 0) {
    rezult = 1;
  } else if (base != s21_NAN && expp == s21_NAN) {
    rezult = s21_INF;
  } else if ((base < 0) && ((expp > 0) && (expp < 1))) {
    rezult = s21_NAN;
  } else if ((base < 0) && ((int)expp % 2 != 0) && (expp - (int)expp == 0)) {
    base = -base;
    rezult = s21_exp(expp * s21_log(base));
    rezult = -rezult;
  } else if ((base < 0) && ((int)expp % 2 == 0)) {
    base = -base;
    rezult = s21_exp(expp * s21_log(base));
  } else {
    rezult = s21_exp(expp * s21_log(base));
  }
  if (flag_s == 1 && -rezult < -s21_MAX_double) {
    rezult = 0;
  }
  rezult = rezult == 1 ? rezult > s21_MAX_double ? 0 : 1. / rezult : rezult;
  return rezult = rezult > s21_MAX_double ? s21_INF : rezult;
}
