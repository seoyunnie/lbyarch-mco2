# Euclidean Distance Kernel in C and x86-64 Assembly

## Project Description

This project implements the Euclidean distance calculation using two kernel versions:

1. C
2. x86-64 NASM assembly

For every index `i`, the program calculates:

\[
Z[i] = \sqrt{(X_2[i] - X_1[i])^2 + (Y_2[i] - Y_1[i])^2}
\]

The program then initializes the four single-precision floating-point vectors, executes both kernels then measures their execution time, compares their outputs, and displays the first 10 results checking for correctness and timing the speed of the two kernel versions

## Members

