#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <assert.h>

// always true
int a(int x, double dx) {
  return (float)x == (float)dx;
}

// false if y == INT_MIN
int b(int x, int y, double dx, double dy) {
  return dx-dy == (double)(x-y);
}

// always true
int c(double dx, double dy, double dz) {
  return (dx+dy)+dz == dx+(dy+dz);
}

// false because multiplication is not associative
int d(double dx, double dy, double dz) {
  return (dx*dy)*dz == dx*(dy*dz);
}

// false if x != 0 && z == 0
int e(double dx, double dz) {
  return dx/dx == dz/dz;
}

int main() {
  srand(time(0));
  int x = (int)(rand()*(rand()&1));
  int y = (int)(rand()*(rand()&1));
  int z = (int)(rand()*(rand()&1));
  double dx = (double)x;
  double dy = (double)y;
  double dz = (double)z;
  assert(a(x,dx));
  assert(!b(0,INT_MIN,0,(double)INT_MIN));
  assert(c(dx,dy,dz));
  assert(!e(dx,(double)0));
  return 0;
}
