#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

unsigned f2u(float x) {
  return *(unsigned*)&x;
}

int float_le(float x, float y) {
  unsigned ux = f2u(x);
  unsigned uy = f2u(y);
  unsigned sx = ux>>31;
  unsigned sy = uy>>31;
  return (!sx && !sy && ux<=uy) ||
         (sx && sy && ux>=uy) ||
         (sx && !sy) ||
         (!(ux<<1) && !(uy<<1));
}

int main() {
  assert(float_le(-0, +0));
  assert(float_le(+0, -0));
  assert(float_le(0, 3));
  assert(float_le(-4, -0));
  assert(float_le(-4, 4));
  return 0;
}
