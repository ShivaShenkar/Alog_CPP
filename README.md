# Algo_CPP
fikhman2005@gmail.com
# Graph Algorithms Project

## Overview
This project implements various graph algorithms, including Depth-First Search (DFS), Breadth-First Search (BFS), Dijkstra's shortest path algorithm, Prim's Minimum Spanning Tree (MST) algorithm, and Kruskal's MST algorithm. The project is written in C++ and includes unit tests using the Doctest framework to ensure correctness and reliability.

## Features
### Graph Representation
- The graph is represented using an **adjacency list** data structure for efficient storage and traversal.
- The project includes classes for managing **edges**, **edge lists**, and the overall **graph structure**.

### Graph Algorithms
1. **Depth-First Search (DFS)**:
   - Explores as far as possible along each branch before backtracking.
   - Useful for connectivity checks and pathfinding in graphs.
   - Implemented using recursion or a stack-based approach.

2. **Breadth-First Search (BFS)**:
   - Explores all neighbors of a vertex before moving to the next level.
   - Ideal for finding the shortest path in an unweighted graph.
   - Implemented using a queue for level-order traversal.

3. **Dijkstra's Shortest Path Algorithm**:
   - Finds the shortest path from a source vertex to all other vertices in a weighted graph.
   - Uses a **priority queue (min-heap)** for efficient selection of the next vertex with the smallest distance.
   - Handles graphs with non-negative edge weights.

4. **Prim's Minimum Spanning Tree (MST)**:
   - Constructs an MST by greedily adding the smallest edge that connects a new vertex to the growing tree.
   - Uses a **priority queue** to efficiently select the next edge.
   - Suitable for dense graphs.

5. **Kruskal's Minimum Spanning Tree (MST)**:
   - Constructs an MST by sorting all edges and adding them to the tree in increasing order of weight, ensuring no cycles.
   - Uses the **Union-Find (Disjoint Set Union)** data structure for cycle detection.
   - Efficient for sparse graphs.

### Unit Testing
- The project includes comprehensive test cases for all algorithms using the **Doctest** framework.
- Test cases cover scenarios such as:
  - Basic connectivity.
  - Disconnected graphs.
  - Graphs with unreachable vertices.
  - Weighted graphs for Dijkstra's and MST algorithms.

## File Structure
