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
  if (f == 0 || f == -0) return f; // \pm 0
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

float_bits float_half(float_bits f) {
  if (f == 0 || f == -0) return f; // \pm 0
  unsigned sign = f>>31;
  unsigned exp = (f>>23)&0xff;
  unsigned frac = f&(0x7FFFFF);
  if (exp == 0xff && frac == 0) return f;
  if (exp == 0xff && frac) return f;
  // need to be careful about last 2 bits of frac for rounding
  if (exp == 0) { /* denormalized */
    frac >>= 1;
    if ((frac&0x3) == 0x3) frac++;
  } else if (exp == 1) { /* case of changing normalized to denormalized */
    unsigned r = f&0x7FFFFFFF;
    if ((r&0x3) == 0x3) r++;
    exp = (r>>23)&0xff;
    frac = r&0x7FFFFF;
  } else {
    exp--;
  }
  return (sign<<31)|(exp<<23)|frac;
}

int f2i(float_bits f) {
  if (f == 0 || f == -0) return f; // \pm 0
  unsigned sign = f>>31;
  unsigned exp = (f>>23)&0xff;
  unsigned frac = f&(0x7FFFFF);
  unsigned bias = 0x7f;

  int res = 0;
  if (0 <= exp && exp < bias) { /* f is less than 1 */
    res = 0;
  } else if (bias + 31) {/* case of overflow */
    res = 0x80000000;
    if (sign) res *= -1;
  } else {
    int e = exp - bias;
    int m = frac | 0x80000000;
    if (e > 23) { /* case of integer */
      res = m<<(e-23);
    } else { /* with fraction */
      // use only 23-3 bits rounding to 0
      res = m>>(23-e);
    }
  }
  return res;
}

int main() {
  return 0;
}
