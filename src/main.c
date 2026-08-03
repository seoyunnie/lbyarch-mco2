#include <stdlib.h>

#include "process.h"
#include "stdio.h"

int main(void) {
  float x1[] = {1.5f, 4.0f, 3.5f, 2.0f};
  float x2[] = {3.0f, 2.5f, 2.5f, 1.0f};
  float y1[] = {4.0f, 3.0f, 3.5f, 3.0f};
  float y2[] = {2.0f, 2.5f, 1.0f, 1.5f};

  const size_t n = sizeof(x1) / sizeof(x1[0]);

  float* z = (float*)malloc(n * sizeof(*z));

  if (z == NULL) {
    fprintf(stderr, "Failed to allocate memory for Z\n");

    return EXIT_FAILURE;
  }

  distance(n, x1, x2, y1, y2, z);

  printf("Z -> ");

  for (size_t i = 0; i < n; i++) {
    printf("%.8f", z[i]);

    if (i + 1 < n) {
      printf(", ");
    }
  }

  printf("\n");

  return EXIT_SUCCESS;
}
