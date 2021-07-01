#include <stdio.h>
#include <assert.h>
#include <limits.h>

int threeforths(int x) {
  int h = x&(~3); // high part of larger than 3
  int l = x&3;    // low part of less than or equal to 3
  // high part: /4 then *3
  int hd4 = h>>2;
  int hd4m3 = (hd4<<1) + hd4;
  // low part: consider 2.3.7 for rounding toward zero
  int is_negative = x & INT_MIN;
  int lm3 = (l<<1) + l; // *3
  is_negative && (lm3 += (1<<2) - 1);
  int lm3d4 = lm3>>2;
  return hd4m3 + lm3d4;
}

int main() {
  assert(threeforths(8) == 6);
  assert(threeforths(9) == 6);
  assert(threeforths(10) == 7);
  assert(threeforths(11) == 8);
  assert(threeforths(12) == 9);
  assert(threeforths(-8) == -6);
  assert(threeforths(-9) == -6);
  assert(threeforths(-10) == -7);
  assert(threeforths(-11) == -8);
  assert(threeforths(-12) == -9);
  return 0;
}
