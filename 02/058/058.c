#include <stdio.h>

typedef unsigned char *byte_pointer;

void is_little_endian() {
  int n = 1;
  size_t len = sizeof(int);
  byte_pointer p = (byte_pointer)&n;
  fprintf(stdout, "This OS is ");
  fprintf(stdout, "%s", p[0] == 0x01 ? "little" : "big");
  puts(" endian.");
}

int main() {
  is_little_endian();
  return 0;
}
