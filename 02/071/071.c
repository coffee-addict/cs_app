#include <stdio.h>
#include <assert.h>

// A. The original function does not take negative sign into account.

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum) {
  // to keep the sign, shift to the left most byte, 
  int res = (int)(word<<((3-bytenum)<<3));
  // then shift to the right most byte as signed int
  return res>>24;
}

int main() {
  assert(xbyte(0x00000001,0) == 0x01);
  assert(xbyte(0x0000007F,0) == 0x7F);
  assert(xbyte(0x00007900,1) == 0x79);
  assert(xbyte(0x00009900,1) == 0xFFFFFF99);
  assert(xbyte(0x007FABCD,2) == 0x7F);
  assert(xbyte(0x00AFABCD,2) == 0xFFFFFFAF);
  assert(xbyte(0x3FABCD72,3) == 0x3F);
  assert(xbyte(0xEFABCD72,3) == 0xFFFFFFEF);
  return 0;
}

