#include <stdlib.h>
#include <time.h>

#include "process.h"
#include "process_x64.h"
#include "stdio.h"

static void fill_vector(float* vec, size_t size) {
  for (size_t i = 0; i < size; i++) {
    vec[i] = (rand() % 1000) / 10.0f;
  }
}

static const int BENCHMARK_RUNS = 30;

static const size_t MAX_PRINTED_RESULTS = 10;

static void print_results(const float* z, size_t n) {
  n = (n < MAX_PRINTED_RESULTS) ? n : MAX_PRINTED_RESULTS;

  printf("z -> ");

  for (size_t i = 0; i < n; i++) {
    printf("%.8f", z[i]);

    if (i + 1 < n) {
      printf(", ");
    }
  }

  printf("\n");
}

int main(int argc, char* argv[]) {
  srand((unsigned)time(NULL));

  if (argc != 2) {
    fprintf(stderr, "Usage: %s {20,24,30}", argv[0]);

    return 1;
  }

  char* end;
  const int exponent = strtol(argv[1], &end, 10);

  if (*end != '\0' || (exponent != 20 && exponent != 24 && exponent != 30)) {
    fprintf(stderr, "Usage: %s {20,24,30}", argv[0]);

    return 1;
  }

  const size_t n = (size_t)1 << exponent;

  float* x1 = malloc(n * sizeof(*x1));
  float* x2 = malloc(n * sizeof(*x2));
  float* y1 = malloc(n * sizeof(*y1));
  float* y2 = malloc(n * sizeof(*y2));
  float* z = malloc(n * sizeof(*z));

  if (x1 == NULL || x2 == NULL || y1 == NULL || y2 == NULL || z == NULL) {
    fprintf(stderr, "Failed to allocate memory for the vectors\n");

    return EXIT_FAILURE;
  }

  fill_vector(x1, n);
  fill_vector(x2, n);
  fill_vector(y1, n);
  fill_vector(y2, n);
  fill_vector(z, n);

  printf("Benchmarking (C)...");
  fflush(stdout);

  double avg_ms = 0.0;

  for (int i = 0; i < BENCHMARK_RUNS; i++) {
    clock_t start = clock();

    distance(n, x1, x2, y1, y2, z);

    clock_t end = clock();

    double elapsed_ms = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    avg_ms += elapsed_ms;
  }

  printf("\r");

  print_results(z, n);
  printf("Average Time (C): %.3f ms\n", avg_ms / BENCHMARK_RUNS);

  printf("Benchmarking (ASM)...");
  fflush(stdout);

  avg_ms = 0.0;

  for (int i = 0; i < BENCHMARK_RUNS; i++) {
    clock_t start = clock();

    distance_x64(n, x1, x2, y1, y2, z);

    clock_t end = clock();

    double elapsed_ms = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    avg_ms += elapsed_ms;
  }

  printf("\r");

  print_results(z, n);
  printf("Average Time (ASM): %.3f ms\n", avg_ms / BENCHMARK_RUNS);

  free(z);
  free(y2);
  free(y1);
  free(x2);
  free(x1);

  return EXIT_SUCCESS;
}
