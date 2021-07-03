#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

// A: false if x == INT_MIN (-x = x)
// but gcc compiler makes it true, I don't know why...
int a(int x, int y) {
  return (x<y) == (-x>-y);
}

// B: true
// bit operations correspond to appropriate multiplications
int b(int x, int y) {
  return ((x+y)<<4) + y-x == 17*y + 15*x;
}

// C: true
// can be proven using -x = ~x + 1 <=> ~x = -(x+1)
int c(int x, int y) {
  return ((~x)+(~y)+1) == ~(x+y);
}

// D: not sure; what type is -(unsigned)(y-x)?
int d(int x, int y) {
  unsigned ux = (unsigned) x;
  unsigned uy = (unsigned) y;
  return (ux - uy) == -(unsigned) (y - x);
}

// E: true
// ((x>>2)<<2) = x&~(0x3)
// more zero bits makes it have less value
int e(int x, int y) {
  return ((x>>2)<<2) <= x;
}

int main() {
  assert(!a(INT_MIN, 0));
  int x = rand();
  int y = rand();
  assert(b(x, y));
  assert(c(x, y));
  assert(d(x, y));
  assert(e(x, y));
  return 0;
}
