#include <stdio.h>
#include <assert.h>

int int_shifts_are_arithmetic() {
  int x = -1;
  int s = sizeof(int)<<3;
  return !((((-1)>>s)&0xff) == 0);
  // alternative
  // return !(x^(x>>1));
}

int main() {
  fprintf(stdout, "This machine is ");
  if (!int_shifts_are_arithmetic())
    fprintf(stdout, "%d", "non-");
  fprintf(stdout, "%s\n", "arithmetic right shift.");
  return 0;
}
