# Stage Analysis for Graphs

This folder contains implementations for analyzing and identifying stages in directed graphs.

## Problem Overview

In many graph problems, particularly for multistage graphs, it's essential to:
1. Determine the number of stages in the graph
2. Identify which vertices belong to each stage

These implementations help perform that analysis as a preprocessing step for multistage graph algorithms.

## Stages Count Implementation

### Algorithm Overview
This algorithm counts the total number of stages in a directed graph by assigning stage numbers to vertices.

### Implementation Details
- **File**: `StagesCount.cpp`
- **Approach**: Breadth-first traversal with stage propagation
- **Data Structures**:
  - Adjacency matrix for graph representation
  - Array to track the stage number of each vertex

### Algorithm Steps
1. Assign stage 1 to the source vertex (vertex 0)
2. For each vertex in order:
   - If the vertex has been assigned a stage:
     - For each adjacent vertex:
       - Assign stage number (current stage + 1) if the adjacent vertex is unassigned or would get a higher stage number

### Time Complexity
- O(V²) where V is the number of vertices
  - We consider each vertex once
  - For each vertex, we examine all possible edges

### Space Complexity
- O(V) for the stage array
- O(V²) for the adjacency matrix

## Stage Vertices Implementation

### Algorithm Overview
This implementation extends the stage counting functionality to also group vertices by their stages.

### Implementation Details
- **File**: `StageVertices.cpp`
- **Approach**: Similar to StagesCount, but with additional grouping
- **Data Structures**:
  - Similar to StagesCount
  - Additional vector of vectors to group vertices by stage

### Algorithm Steps
1. Count the stages as in the StagesCount implementation
2. Create a vector of vectors to store vertices by stage
3. Iterate through all vertices and add each to its corresponding stage group

### Time and Space Complexity
- Similar to StagesCount with additional O(V) space for storing the grouped vertices

## Usage

### StagesCount
The program prompts the user for:
1. Number of vertices
2. Adjacency matrix (use -1 for no edge)

It then outputs the total number of stages in the graph.

### StageVertices
The program uses a predefined graph example and outputs:
1. Total number of stages
2. List of vertices in each stage

## Applications

- Preprocessing for multistage graph problems
- Analysis of layered network structures
- Dependency resolution in directed acyclic graphs
- Scheduling and resource allocation problems 