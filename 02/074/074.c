#include <stdio.h>
#include <limits.h>
#include <assert.h>

int tsub_ok(int x, int y) {
  int s = x - y;
  int pof = !(x&INT_MIN) && (y&INT_MIN) && (s&INT_MIN);
  int nof = (x&INT_MIN) && !(y&INT_MIN) && !(s&INT_MIN);
  return (!pof)&&(!nof);
}

int main() {
  assert(tsub_ok(0, 1) == 1);
  assert(tsub_ok(INT_MIN, 1) == 0);
  assert(tsub_ok(INT_MAX, -1) == 0);
  return 0;
}
