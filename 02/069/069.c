#include <stdio.h>
#include <assert.h>

// assume 0 <= n < w = sizeof(int)
unsigned rotate_left(unsigned x, int n) {
  int w = sizeof(int)<<3;
  unsigned l = x<<n;
  unsigned r = (x>>(w-n))&(~((-1)<<n));
  return l|r;
}

int main() {
  assert(rotate_left(0x12345678,4) == 0x23456781);
  assert(rotate_left(0x12345678,20) == 0x67812345);
  return 0;
}

