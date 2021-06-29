#include <stdio.h>
#include <limits.h>
#include <assert.h>

// In section 6.5.7 below, '<< 32' could be undefined
// http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf
// Hence, the bit shift on the right operand should not go beyond 31 at once
int int_size_is_32() {
  int set_msb = 1<<31;
  int beyond_msb = set_msb<<1;
  return set_msb && !beyond_msb;
}

int int_size_is_32_for_16bit_or_greater(){
  int set_msb = 1<<15;
  set_msb <<= 15;
  set_msb <<= 1;
  int beyond_msb = set_msb<<1;
  return set_msb && !beyond_msb;
}

int main() {
  assert(int_size_is_32());
  assert(int_size_is_32_for_16bit_or_greater());
  return 0;
}
