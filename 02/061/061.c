#include <stdio.h>
#include <assert.h>

int is_any_bit_1(int x) {
  return x != 0;
  // alternative
  // return !~x;
}

int is_any_bit_0(int x) {
  return x == 0;
  // alternative
  // return !x;
}

int is_any_lsb_1(int x) {
  return (x&0xff) != 0;
  // alternative
  // !~(x|(~0xff));
}

int is_any_msb_0(int x) {
  // right shift (sizeof(int)-1) bytes
  int shift_val = (sizeof(int)-1)<<3;
  int xright = x>>shift_val;
  return !(xright&0xff);
}


int main() {
  assert(is_any_bit_1(3) == 1);
  assert(is_any_bit_1(0) == 0);
  assert(is_any_bit_0(0) == 1);
  assert(is_any_bit_0(-1) == 0);
  assert(is_any_lsb_1(2) == 1);
  assert(is_any_lsb_1(0x11111100) == 0);
  assert(is_any_msb_0(0x00111111) == 1);
  assert(is_any_msb_0(0x01000000) == 0);
  return 0;
}
