# Graph Coloring

This implementation solves the graph coloring problem using backtracking.

## Problem Description
Given an undirected graph and a number m, determine if the graph can be colored with at most m colors such that no two adjacent vertices have the same color.

## Algorithm Details
- Uses backtracking approach
- Time Complexity: O(m^n) where n is number of vertices and m is number of colors
- Space Complexity: O(n) for recursion stack

## How to Use
1. Compile the program:
   ```
   g++ -o graphColoring graphColouring.cpp
   ```
2. Run the executable:
   ```
   ./graphColoring
   ```
3. Enter the number of vertices
4. Enter the adjacency matrix (1 if vertices are connected, 0 otherwise)
5. Enter the number of colors
6. The program will display the coloring solution if it exists

## Example
Input:
```
Number of vertices: 4
Adjacency matrix:
0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0
Number of colors: 3
```

Output:
```
Solution exists: Following are the assigned colors:
Vertex 0 ---> Color 1
Vertex 1 ---> Color 2
Vertex 2 ---> Color 3
Vertex 3 ---> Color 2
``` 