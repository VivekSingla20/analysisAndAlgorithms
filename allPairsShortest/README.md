# All-Pairs Shortest Path Algorithm

This folder contains an implementation of the Floyd-Warshall algorithm, a dynamic programming approach for finding shortest paths between all pairs of vertices in a weighted graph.

## Problem Statement

Given a weighted directed graph, find the shortest path distances between every pair of vertices. The graph may contain negative edge weights, but no negative cycles (cycles whose edges sum to a negative value).

## Implementation Details

- **File**: `allPairsShortestDP.cpp`
- **Approach**: Dynamic Programming (Floyd-Warshall Algorithm)
- **Data Structure**: 2D matrix (adjacency matrix) for graph representation

## Algorithm Steps

1. Initialize the distance matrix with the given graph's adjacency matrix
   - Direct edges are represented by their weights
   - Non-existent edges are represented by -1 (indicating infinity)
   - Self-loops have a weight of 0
2. For each vertex k (as an intermediate vertex):
   - For each pair of vertices (i,j):
     - If going through vertex k results in a shorter path than the current direct path, update the distance

## Mathematical Formulation

dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

This recurrence relation forms the core of the Floyd-Warshall algorithm.

## Time Complexity

- O(V³) where V is the number of vertices
  - Three nested loops, each iterating over all vertices

## Space Complexity

- O(V²) for the distance matrix storing shortest paths between all pairs

## Applications

The Floyd-Warshall algorithm is used in various applications, including:
- Network routing protocols
- Finding transitive closure of a graph
- Road network navigation systems
- Airline route planning
- Critical path analysis in project management

## Features and Limitations

### Features
- Works for both directed and undirected graphs
- Can handle negative edge weights (but not negative cycles)
- Computes all shortest paths in a single execution

### Limitations
- Not efficient for sparse graphs compared to running Dijkstra's algorithm for each vertex
- Cannot detect negative cycles (though the algorithm can be modified to do so)
- High space complexity for large graphs

## Usage

The implementation includes a sample graph with 4 vertices. The program outputs the shortest path distances between all pairs of vertices after running the Floyd-Warshall algorithm. 