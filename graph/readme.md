## Graph Terminology

- **Edges**: The connections between vertices in a graph.

- **Directed graph**: A graph where edges have a direction, going from one vertex to another.

- **Undirected graph**: A graph where edges have no direction and connect two vertices bidirectionally.

- **Bidirectional graph**: A graph where each edge has two directions, connecting two vertices in both directions (essentially an undirected graph).

- **Cycles**: A path in a graph that starts and ends at the same vertex without repeating edges.

- **Cyclic graph**: A graph that contains at least one cycle.

- **Acyclic graph**: A graph that does not contain any cycles.

- **Path**: A sequence of edges connecting vertices in a graph, where no node appears more than once, and there is a way to reach from one vertex to another.

- **Degree**: The number of edges connected to a vertex in a graph.
  Total degree of a graph = 2 x E

- For directed graphs,

  - **Indegree**: The number of edges coming into a vertex in a directed graph.
  - **Outdegree**: The number of edges going out from a vertex in a directed graph.

- **Edge weight**: A value assigned to an edge in a graph, representing the cost, distance, or other measure of the connection between two vertices; if not provided, the weight is assumed to be 1.

## Time and Space Complexities for Adjacency Matrix Representation

### Operation: Add Vertex

- **Time Complexity**: \( O(V^2) \)  
  Adding a vertex requires resizing the matrix to \( (V+1) \times (V+1) \), which involves creating a new matrix and copying all existing entries.
- **Space Complexity**: \( O(V^2) \)  
  The adjacency matrix always occupies \( O(V^2) \) space, as it must store entries for all potential edges.

### Operation: Add Edge

- **Time Complexity**: \( O(1) \)  
  Adding an edge involves updating a single entry in the matrix.
- **Space Complexity**: \( O(1) \)  
  No additional space is needed since the matrix size remains unchanged.

### Operation: Remove Vertex

- **Time Complexity**: \( O(V^2) \)  
  Removing a vertex requires deleting a row and a column, which involves copying data to reshape the matrix.
- **Space Complexity**: \( O(V^2) \)  
  The adjacency matrix still occupies \( O(V^2) \) space after resizing.

### Operation: Remove Edge

- **Time Complexity**: \( O(1) \)  
  Removing an edge involves clearing a single entry in the matrix.
- **Space Complexity**: \( O(1) \)  
  No additional space is needed for this operation.

### Operation: Check Edge Existence

- **Time Complexity**: \( O(1) \)  
  Checking for an edge involves accessing a single entry in the matrix.
- **Space Complexity**: \( O(1) \)  
  No additional space is required.

### Operation: Iterate Over All Neighbors of a Vertex

- **Time Complexity**: \( O(V) \)  
  Iterating over neighbors involves scanning an entire row of the matrix corresponding to the vertex.
- **Space Complexity**: \( O(1) \)  
  No additional space is required for this operation.

### Operation: Display the Graph

- **Time Complexity**: \( O(V^2) \)  
  Displaying the graph involves iterating through all \( V^2 \) entries in the matrix.
- **Space Complexity**: \( O(V^2) \)  
  The matrix itself requires \( O(V^2) \) space to store all edges.

### Summary Table

| **Operation**              | **Time Complexity** | **Space Complexity** |
| -------------------------- | ------------------- | -------------------- |
| Add Vertex                 | \( O(V^2) \)        | \( O(V^2) \)         |
| Add Edge                   | \( O(1) \)          | \( O(1) \)           |
| Remove Vertex              | \( O(V^2) \)        | \( O(V^2) \)         |
| Remove Edge                | \( O(1) \)          | \( O(1) \)           |
| Check Edge Existence       | \( O(1) \)          | \( O(1) \)           |
| Iterate Over All Neighbors | \( O(V) \)          | \( O(1) \)           |
| Display Graph              | \( O(V^2) \)        | \( O(V^2) \)         |
