#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void *my_calloc(size_t nmemb, size_t size) {
  if (nmemb==0 || size==0) return NULL;
  size_t buf_size = nmemb*size;
  if (nmemb != buf_size/size) return NULL; // overflow check
  void *p = malloc(buf_size);
  if (p) memset(p, 0, sizeof(p));
  return p;
}

int main() {
  void *p = my_calloc(2, 1);
  assert(p != NULL);
  free(p);
  p = my_calloc(SIZE_MAX, 2);
  assert(p == NULL);
  free(p);
  return 0;
}
