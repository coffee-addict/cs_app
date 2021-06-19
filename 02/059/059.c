#include <stdio.h>

int replace_least_byte(int x, int y) {
  return ((y>>8)<<8)|(x&0xff);
//  // alternative
//  return (x&0xff)|(y&(~0xff));
}


int main() {
  int x = 0x89ABCDEF, y = 0x76543210;
  fprintf(stdout, "x = %.8x\n", x);
  fprintf(stdout, "y = %.8x\n", y);
  fprintf(stdout, "result = %.8x\n", replace_least_byte(x, y));
  return 0;
}
