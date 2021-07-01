#include <stdio.h>
#include <limits.h>
#include <assert.h>

int saturating_add(int x, int y) {
  // overflow, underflow
  int s = x + y;
  int pof = !(x&INT_MIN) && !(y&INT_MIN) && (s&INT_MIN);
  int nof = (x&INT_MIN) && (y&INT_MIN) && !(s&INT_MIN);
  (pof && (s = INT_MAX)) || (nof && (s = INT_MIN));
  return s;
}

int main() {
  assert(saturating_add(INT_MAX, 1) == INT_MAX);
  assert(saturating_add(INT_MIN, -1) == INT_MIN);
  return 0;
}
