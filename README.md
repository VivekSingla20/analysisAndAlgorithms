# Analysis and Algorithms

This repository contains implementations of various classic algorithms and data structures, with a focus on analysis of their time and space complexity.

## Project Structure

The project is organized into the following folders, each containing specific algorithm implementations:

- **[peak](peak/)**: Peak finding algorithms in 1D and 2D arrays (divide and conquer)
- **[fractionalKnapsack](fractionalKnapsack/)**: Greedy algorithm for the fractional knapsack problem
- **[01knapsacking](01knapsacking/)**: Dynamic programming solution for 0/1 knapsack problem
- **[primsAlgo](primsAlgo/)**: Prim's algorithm for finding minimum spanning trees
- **[kruskals](kruskals/)**: Kruskal's algorithm with Union-Find data structure for minimum spanning trees
- **[sorts](sorts/)**: Sorting algorithms including iterative QuickSort
- **[convexPolygon](convexPolygon/)**: Computational geometry algorithms for convex hull and point-in-triangle detection
- **[matrixMultiplication](matrixMultiplication/)**: Matrix chain multiplication using dynamic programming
- **[multiStageGraphs](multiStageGraphs/)**: Dynamic programming approach for multistage graph problems
- **[Stages](Stages/)**: Algorithms for analyzing and identifying stages in directed graphs
- **[magicSquare](magicSquare/)**: Implementation of the Siamese method for generating magic squares
- **[cosineSimilarity](cosineSimilarity/)**: Text analysis algorithm for measuring document similarity
- **[allPairsShortest](allPairsShortest/)**: Floyd-Warshall algorithm for finding shortest paths between all vertex pairs
- **[activitySelection](activitySelection/)**: Greedy algorithm for selecting maximum non-overlapping activities
- **[sumOfSubsets](sumOfSubsets/)**: Backtracking solution for finding subsets with given sum
- **[findMaxMin](findMaxMin/)**: Divide and conquer approach for finding maximum and minimum elements
- **[graphColouring](graphColouring/)**: Backtracking solution for graph coloring problem
- **[nQueens](nQueens/)**: Backtracking solution for N-Queens problem
- **[plot](plot/)**: Performance analysis data and visualization resources

All implementations include detailed README files with algorithm explanations, complexity analysis, and visualizations of the algorithms' performance.

## Key Algorithm Paradigms

This collection demonstrates several important algorithm design techniques:

1. **Divide and Conquer**: Breaking problems into smaller subproblems (peak finding, findMaxMin)
2. **Greedy Algorithms**: Making locally optimal choices (fractional knapsack, Prim's algorithm, Kruskal's algorithm, activity selection)
3. **Dynamic Programming**: Solving problems by combining solutions to overlapping subproblems (0/1 knapsack, matrix chain multiplication, multistage graphs, all-pairs shortest paths)
4. **Backtracking**: Systematic search for solutions (sum of subsets, graph coloring, N-Queens)
5. **Graph Algorithms**: Working with vertex and edge structures (Prim's MST, Kruskal's MST, multistage graphs, Floyd-Warshall, graph coloring)
6. **Computational Geometry**: Solving spatial problems (convex hull, point in triangle)
7. **Text Analysis**: Measuring similarity between documents (cosine similarity)
8. **Data Structures**: Implementations of specialized data structures (Disjoint Set Union, Priority Queues)

## Algorithm Complexity Analysis

Each implementation includes a detailed analysis of:
- Time complexity (best, average, and worst cases)
- Space complexity
- Performance characteristics and trade-offs
- Visual representations of algorithm performance

## Visualizations

The `plot` folder contains performance graphs and algorithm visualizations for many of the implementations, including:
- Comparison of different matrix multiplication techniques
- Growth patterns of various sorting algorithms
- Time complexity analysis of peak finding algorithms
- Graphical representations of data structures and graph algorithms

These visualizations help in understanding the theoretical complexity analysis through practical performance measurements.

## Usage

Each algorithm is implemented as a standalone C++ program. To run any specific algorithm:

1. Navigate to the corresponding folder
2. Compile the C++ file with your preferred compiler, e.g.:
   ```
   g++ -o program_name file_name.cpp
   ```
3. Run the compiled executable:
   ```
   ./program_name
   ```

## Learning Resources

The implementations in this repository serve as practical examples for understanding:
- Algorithm design paradigms
- Time and space complexity analysis
- Implementation considerations and optimizations
- Trade-offs between different approaches to the same problem
- Advanced data structure usage and implementation

Refer to the README in each subfolder for detailed information about specific algorithms and their implementations. 