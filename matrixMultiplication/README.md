# Matrix Multiplication Algorithms

This folder contains implementations of different matrix multiplication algorithms, from simple to advanced approaches.

## Simple Matrix Multiplication

### Algorithm Overview
The straightforward implementation of matrix multiplication using three nested loops.

### Implementation Details
- **File**: `simpleMethod.cpp`
- **Approach**: Iterative, direct implementation of the mathematical definition

### Time Complexity
- O(n³) where n is the dimension of the square matrices

### Space Complexity
- O(n²) for the result matrix

## Divide and Conquer Method

### Algorithm Overview
This approach divides each matrix into four submatrices, performs operations on these smaller matrices, and combines the results.

### Implementation Details
- **File**: `divideAndConquerMethod.cpp`
- **Approach**: Recursive divide and conquer
- **Process**:
  1. Divide each n×n matrix into four n/2×n/2 submatrices
  2. Recursively compute the necessary products of submatrices
  3. Combine the results by adding the appropriate submatrix products

### Time Complexity
- O(n³) - same as the simple method asymptotically
- Involves 8 recursive calls for n/2 sized matrices

### Space Complexity
- O(n²) for storing the matrices
- Additional overhead for recursive calls

## Strassen's Algorithm

### Algorithm Overview
Strassen's algorithm is an optimized divide and conquer approach that reduces the number of recursive calls from 8 to 7.

### Implementation Details
- **File**: `strassenMultiplication.cpp`
- **Approach**: Optimized recursive divide and conquer
- **Process**:
  1. Divide matrices into four submatrices
  2. Create 7 matrices P1 to P7 by specific combinations of submatrices
  3. Calculate result submatrices using these P matrices
  4. Fall back to standard multiplication for small matrices (optimization)

### Visualization

![Strassen's Algorithm Performance](../plot/strassens.png)

### Time Complexity
- **Overall**: O(n^log₂7) ≈ O(n^2.81)
- Significantly better than O(n³) for large matrices

### Space Complexity
- O(n²) for storing the matrices
- Additional overhead for temporary matrices during computation

## Usage Notes

- All implementations handle matrices of any size
- For non-power-of-2 sized matrices, padding is applied for divide and conquer methods
- A threshold is implemented in Strassen's algorithm to switch to simple multiplication for small matrices, optimizing performance

## Practical Considerations

- Strassen's algorithm, despite its better asymptotic complexity, often performs worse than optimized simple multiplication for smaller matrices due to:
  - Higher constant factors
  - Worse cache performance
  - More complex implementation

- The implementation includes a threshold (64 in this code) where it switches to the simpler algorithm for small matrices 