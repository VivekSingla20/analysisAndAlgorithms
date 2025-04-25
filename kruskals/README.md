# Kruskal's Algorithm

This folder contains an implementation of Kruskal's algorithm, a greedy algorithm for finding a minimum spanning tree in a connected weighted graph.

## Problem Statement

Given a connected, undirected graph with weighted edges, find a subset of the edges that forms a tree that includes every vertex, where the total weight of all the edges in the tree is minimized.

## Implementation Details

- **File**: `kruskalsAlgo.cpp`
- **Approach**: Greedy algorithm with Disjoint Set Union (DSU)
- **Data Structures**:
  - Disjoint Set Union (DSU) for cycle detection
  - Priority Queue (Min Heap) for edge selection
  - Vectors for graph representation

## Algorithm Steps

1. Sort all edges in non-decreasing order of their weight
2. Initialize an empty MST and a disjoint set for all vertices
3. For each edge in sorted order:
   - If including this edge doesn't form a cycle (using DSU to check), add it to the MST
   - Otherwise, discard the edge
4. Repeat until n-1 edges are added (where n is the number of vertices)

## Time Complexity

- **Sorting edges**: O(E log E) where E is the number of edges
- **DSU operations**: O(E α(V)) where α is the inverse Ackermann function (nearly constant in practice)
- **Overall**: O(E log E) or O(E log V) since E can be at most V²

## Space Complexity

- O(E) for storing the edges
- O(V) for the disjoint set data structure
- **Overall**: O(E + V)

## Comparison with Prim's Algorithm

Both Kruskal's and Prim's algorithms find a minimum spanning tree, but they differ in approach:

| Feature | Kruskal's | Prim's |
|---------|-----------|--------|
| Approach | Processes edges in sorted order | Grows MST one vertex at a time |
| Edge Selection | Global minimum edge | Local minimum edge |
| Data Structures | Disjoint Set | Priority Queue or Min Heap |
| Time Complexity | O(E log E) | O(E log V) with binary heap |
| Better for | Sparse graphs | Dense graphs |

## Implementation Highlights

- **Disjoint Set**: Implemented with path compression and union by rank for efficient operations
- **Edge Representation**: Each edge is stored as a triplet (weight, from, to)
- **Priority Queue**: Used to efficiently extract edges in order of increasing weight

## Applications

Kruskal's algorithm is used in various applications including:
- Network design (telecommunications, electrical grids)
- Approximation algorithms for traveling salesman problem
- Cluster analysis in data mining
- Image segmentation in computer vision

## Example Output

The implementation outputs each selected edge along with its weight as the MST is constructed, and finally displays the total cost of the MST:

```
Picked edge: 0 - 1 (Cost: 2)
Picked edge: 1 - 2 (Cost: 3)
Picked edge: 1 - 4 (Cost: 5)
Picked edge: 0 - 3 (Cost: 6)
Total MST cost: 16
``` 