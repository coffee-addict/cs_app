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

float_bits float_twice(float_bits f) {
  if (f == 0) return f; // 0
  unsigned sign = f>>31;
  unsigned exp = (f>>23)&0xff;
  unsigned frac = f&(0x7FFFFF);
  if (exp == 0xff && frac == 0) return f; // inf
  if (exp == 0xff && frac) return f; // NaN
  if (exp == 0) { /* denormalized case */
    frac <<= 1;
  } else if (exp == 0xff-1) { /* normalized and 2*f == \pm inf */
    exp = 0xff;
    frac = 0;
  } else {
    exp++;
  }
  return (sign<<31)|(exp<<23)|frac;
}

int main() {
  return 0;
}
