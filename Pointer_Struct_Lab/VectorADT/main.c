#include <stdio.h>
#include "vector.h"

int main(void) {
  int i;
  vector v;
  vector_create(&v, 4);

  *vector_at(&v, 0) = 27;
  *vector_at(&v, 1) = 44;
  *vector_at(&v, 2) = 9;
  *vector_at(&v, 3) = 17;

  vector_erase(&v, 1);
  vector_erase(&v, 0);
  vector_insert(&v, 0, 88);

  printf("Contents:\n");
  for (i = 0; i < vector_size(&v); ++i) {
     printf("%d\n", *vector_at(&v, i));
  }

  vector_destroy(&v);

  return 0;
}


