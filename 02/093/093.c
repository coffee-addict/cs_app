#include <stdio.h>

typedef unsigned float_bits;

float_bits float_denorm_zero(float_bits f) {
  unsigned sign = f>>31;
  unsigned exp = (f>>23)&0xff;
  unsigned frac = f&(0x7FFFFF);
  if (exp == 0) frac = 0;
  return (sign<<31)|(exp<<23)|frac;
}

float_bits negate(float_bits f) {
  unsigned sign = ((f>>31)&1) ? 0 : 1;
  unsigned exp = (f>>23)&0xff;
  unsigned frac = f&(0x7FFFFF);
  if (exp == 0xff && frac) return f;
  return (sign<<31)|(exp<<23)|frac;
}

float_bits float_absval(float_bits f) {
  unsigned exp = (f>>23)&0xff;
  unsigned frac = f&(0x7FFFFF);
  if (exp == 0xff && frac) return f;
  return (exp<<23)|frac;
}

int main() {
  return 0;
}
