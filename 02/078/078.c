#include <stdio.h>
#include <assert.h>
#include <limits.h>

// Assume 0 <= k < w-1
int divide_power2(int x, int k) {
  int is_negative = x & INT_MIN; 
  (is_negative && (x = x + (1<<k) - 1));  // see 2.3.7
  return x>>k;
}


int main() {
  assert(divide_power2(5,2) == 5/4);
  assert(divide_power2(-5,1) == (-5)/2);
  return 0;
}
