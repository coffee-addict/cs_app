#include <stdio.h>

unsigned int replace_byte(unsigned int x, int i, unsigned char b) {
  int shift = i*8;
  return x&(~(0xff<<shift))|(b<<shift);
}

int main() {
  int x = 0x12345678;
  fprintf(stdout, "x = %.8x\n", replace_byte(x, 2, 0xAB));
  fprintf(stdout, "x = %.8x\n", replace_byte(x, 0, 0xAB));
  return 0;
}
