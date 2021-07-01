#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// A. (maxbytes - sizeof(val)) is evaluated as size_t = (unsigned int)
//    which is always non-negative

void copy_int(int val, void *buf, int maxbytes) {
  // add casting to int
  if (maxbytes - (int)sizeof(val) >= 0)
    memcpy(buf, (void*)&val, sizeof(val));
}

int main() {
  int maxbytes = sizeof(int);
  void *buf = malloc(maxbytes);
  int x = -1;
  copy_int(x, buf, maxbytes);
  assert((*(int*)buf) == x);

  copy_int(0, buf, maxbytes);
  copy_int(x, buf, 1);
  assert((*(int*)buf) != x);
  return 0;
}

