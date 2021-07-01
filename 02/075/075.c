#include <stdio.h>
#include <assert.h>
#include <inttypes.h>

int signed_high_prod(int x, int y) {
  int64_t z = ((int64_t)x)*y;
  return z>>32;
}

unsigned unsigned_high_prod(unsigned x, unsigned y) {
  int sx = x>>31;
  int sy = y>>31;
  int sp = signed_high_prod(x,y);
  return sp + x*sy + y*sx;
}

unsigned model_unsigned_high_prod(unsigned x, unsigned y) {
  uint64_t z = ((uint64_t)x)*y;
  return z>>32;
}

int main() {
  unsigned x = 0xEFA12C83;
  unsigned y = 0xFFFF09BD;
  assert(unsigned_high_prod(x,y) == model_unsigned_high_prod(x,y));
  return 0;
}
