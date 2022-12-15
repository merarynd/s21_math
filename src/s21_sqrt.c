#include "s21_math.h"

// long double s21_sqrt(double x) {
//   long double l = 0.0, rev = x, rezult;
//   rezult = (l + rev) / 2;
//   for (int i = 0; i < 60; i++) {
//     long double flag;
//     flag = rezult * rezult;
//     if (flag == x) {
//       break;
//     } else if (x < 0 || x != x) {
//       rezult = s21_NAN;
//     } else if (x == s21_INF) {
//       rezult = x;
//     } else if (flag > x) {
//       rev = rezult;
//       rezult = (l + rev) / 2;
//     } else {
//       l = rezult;
//       rezult = (l + rev) / 2;
//     }
//   }
//   return (x < 0) ? -s21_NAN : rezult;
// }
long double s21_sqrt(double x) { return s21_exp(0.5 * s21_log(x)); }