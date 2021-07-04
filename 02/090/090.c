#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <assert.h>

float fpwr2(int x) {
  unsigned e, m;
  unsigned u;
  if (x < -(1<<7)-23) {
    // less than or equal to -inf in float variable
    // too small. return 0.0
    e = 0;
    m = 0;
  } else if (x < -(1<<7)) {
    // less than the minimum normalized value => denormalized
    e = 0;
    m = (-(1<<7)-x)<<(23-7);
  } else if (x < (1<<7)) {
    // less than +inf => normalized
    e = (1<<7) - 1 + x;
    m = 0;
  } else {
    // greater than or equal to inf
    e = 0xff;
    m = 0;
  }
  u = (e<<23)|m;
  return (float)u;
}

int main() {
  int too_small = -(1<<7)-23 - 1;
  assert(fpwr2(too_small) == powf(2,too_small));
  int denom = -(1<<7) - 1;
  assert(fpwr2(denom) == powf(2,denom));
  return 0;
}
