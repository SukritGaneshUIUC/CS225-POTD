#include "epoch.h"
/* Your code here! */

int hours(time_t elapsedTime) {
  return elapsedTime / 3600;
}

int days(time_t elapsedTime) {
  return elapsedTime / (24 * 3600);
}

int years(time_t elapsedTime) {
  return elapsedTime / (24 * 3600 * 365);
}
