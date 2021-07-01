#include <stdio.h>
#include <assert.h>

int multiply(int n, int k) {
  int res = 0;
  switch (k) {
    case 17:
      res = (n<<4) + n;
      break;
    case -7:
      res = n - (n<<3);
      break;
    case 60:
      res = (n<<6) - (n<<2);
      break;
    case -112:
      res = (n<<4) - (n<<7);
      break;
    default:
      break;
  }
  return res;
}

int main() {
  int n = 3;
  assert(multiply(n, 17) == n*17);
  assert(multiply(n, -7) == n*(-7));
  assert(multiply(n, 60) == n*60);
  assert(multiply(n, -112) == n*(-112));
  return 0;
}
