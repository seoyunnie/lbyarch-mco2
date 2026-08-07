# Euclidean Distance Kernel in C and x86-64 Assembly

This project implements the Euclidean distance calculation using two kernel versions: C99 and x64 NASM assembly.

Euclidean distance formula for vectors in 2D space:

$Z[i] = \sqrt{(X_2[i] - X_1[i])^2 + (Y_2[i] - Y_1[i])^2}$

## Video Demonstration

## Analysis of Implementations

![Benchmark results screenshot](./docs/images/benchmarks.png)

The implementation in assembly was over 2x faster than the C implementation, making assembly far more efficient for
larger sets of vector pairs. Both implementations seem to scale similarly as the set size grows.

For cases where performance is critical, the assembly implementation is far more efficient and will cut a lot of time.
But, for other cases, the simplicity of implementing it in C may beat out assembly, especially for programmers who
aren't comfortable with it.

## Correctness Check

![Correctness check screenshot](./docs/images/correctness_check.png)

Correct answers per [Omni Calculator](https://www.omnicalculator.com/math/euclidean-distance):

| **$X_1$** | **$X_2$** | **$Y_1$** | **$Y_2$** | **$Z$**  |
| :-------: | :-------: | :-------: | :-------: | :------: |
|    1.5    |    3.0    |    4.0    |    2.0    |   2.5    |
|    4.0    |    2.5    |    3.0    |    2.5    | 1.58114  |
|    3.5    |    2.5    |    3.5    |    1.0    | 2.69258  |
|    2.0    |    1.0    |    3.0    |    1.5    | 1.802776 |

## Group Members

- Tiongco, Kyan Thomas
- Panaligan ,Louis Raphael
