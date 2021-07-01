#include <stdio.h>
#include <assert.h>
#include <limits.h>

int mul3ddiv4(int x) {
  x = (x<<1) + x;
  int is_negative = x & INT_MIN;
  is_negative && (x = x + (1<<2) - 1);
  return x>>2;
}

int main() {
  int x = 12;
  assert(mul3ddiv4(x) == x*3/4);
  x = INT_MIN; // negative overflow
  assert(mul3ddiv4(x) == x*3/4);
  return 0;
}
