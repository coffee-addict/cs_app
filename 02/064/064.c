#include <stdio.h>
#include <limits.h>
#include <assert.h>

int any_odd_one(unsigned x) {
  int mask = 0xaaaaaaaa;
  // !(x) checks if any bit of x is zero
  // !!(x) checks if some bit of x is one
  return !!(x&mask);
}

int main() {
  int x = -1; // 11..1
  int y = 1; // 00...01
  int z = (int)((unsigned)(INT_MIN) >> 1); // 010...0
  assert(any_odd_one(x) == 1);
  assert(any_odd_one(y) == 0);
  assert(any_odd_one(z) == 0);
  return 0;
}
