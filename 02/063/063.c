#include <stdio.h>
#include <assert.h>

unsigned srl(unsigned x, int k) {
  unsigned xsra = (int)x>>k;
  int w = sizeof(int)<<3; // '<<3' <=> '*8' for 1 word shift 
  int mask = ~(((int)(-1))<<(w-k));
  return xsra&mask;
}

int sra(int x, int k) {
  unsigned xsrl = (unsigned)x>>k;
  int w = sizeof(int)<<3;
  int y = !(x&(1<<(w-1))); // y = 1 if x >= 0, 0 if x < 0
  int mask = (y-1)<<(w-k); // mask = 0 if x >= 0, -1 if x < 0
  return mask|xsrl;
}

int main() {
  int s = 2;
  unsigned ux = 0x80000000;
  unsigned uy = 0xf0000000;
  unsigned uz = 0x70000000;
  assert(srl(ux,s) == ux>>s);
  assert(srl(uy,s) == uy>>s);
  assert(srl(uz,s) == uz>>s);
  int x = (int)ux;
  int y = (int)uy;
  int z = (int)uz;
  assert(sra(x,s) == x>>s);
  assert(sra(y,s) == y>>s);
  assert(sra(z,s) == z>>s);
  return 0;
}
