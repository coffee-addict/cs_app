#include <stdio.h>
#include <assert.h>

int repeat10(int k) {
  return (-1)<<k;
}

int repeat010(int j, int k) {
  int w = sizeof(int)<<3;
  return (int)((((unsigned)(-1))>>(w-k))<<j);
}

int main() {
  int x = -1;
  assert(repeat10(0) == 0xFFFFFFFF);
  assert(repeat10(4) == 0xFFFFFFF0);
  assert(repeat010(4,8) == 0x00000FF0);
  return 0;
}
