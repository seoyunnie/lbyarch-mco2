#include "process.h"

#include <math.h>

void distance(size_t n, const float* x1, const float* x2, const float* y1, const float* y2, float* z) {
  for (size_t i = 0; i < n; i++) {
    const float dx = x2[i] - x1[i];
    const float dy = y2[i] - y1[i];

    z[i] = sqrtf(dx * dx + dy * dy);
  }
}
