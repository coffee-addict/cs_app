#include <stdio.h>
#include <limits.h>
#include <assert.h>

// use xor to cancel out pairs of two 1's
// repeat such cancellations with the left and right halves
int odd_ones(unsigned x) {
  x ^= x>>16;
  x ^= x>>8;
  x ^= x>>4;
  x ^= x>>2;
  x ^= x>>1;
  x &= 1;
  return x;
}

int main() {
  assert(odd_ones(0x10101011));
  assert(odd_ones(0x10101011));
  assert(!odd_ones(0x11111111));
  assert(odd_ones(0x11111110));
  return 0;
}
