# Inversion Counter (Fast and Slow Algorithms)

This program reads a sequence of integers from standard input and computes the number of inversions in the sequence. An inversion is a pair of indices (i, j) such that i < j and array[i] > array[j]. The program supports both a slow O(n²) algorithm and a fast O(n log n) algorithm based on merge sort.

---

## Features
- Supports two inversion counting methods:
- Slow algorithm (Theta(n²)): simple double-loop approach
- Fast algorithm (Theta(n log n)): optimized merge sort-based approach
- Interactive input: enter a sequence of integers separated by spaces
- Provides error messages for invalid or empty input
- Allows selection of the slow method via command-line option

---

## Input Format
The program expects a sequence of integers entered via standard input, separated by spaces. Example:
3 1 2 4
