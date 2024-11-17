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

### Creating an Adjacency Matrix

- **Time Complexity**: \( O(V^2) \)  
  An adjacency matrix requires creating a \( V \times V \) matrix, where \( V \) is the number of vertices. This involves allocating memory for \( V^2 \) entries, even if there are no edges yet.
- **Space Complexity**: \( O(V^2) \)  
  The adjacency matrix takes up \( O(V^2) \) space, as it needs to store a boolean or integer for every pair of vertices, whether or not an edge exists.

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

## Time and Space Complexities for Adjacency List Representation

### Creating an Adjacency List

- **Time Complexity**: \( O(V) \)  
  An adjacency list requires creating a list for each vertex. For each vertex, a linked list or dynamic array is allocated to store the edges. The creation of these lists takes linear time relative to the number of vertices.
- **Space Complexity**: \( O(V + E) \)  
  The space complexity is proportional to \( V + E \), where \( V \) is the number of vertices and \( E \) is the number of edges. Each vertex has a list, and each edge is represented in a list for the source and target vertex.

### Operation: Add Vertex

- **Time Complexity**: \( O(1) \)  
  Adding a vertex involves appending an empty list for the new vertex to the adjacency list.
- **Space Complexity**: \( O(1) \)  
  Each new vertex requires storage for a pointer to its adjacency list, but no immediate storage for edges.

### Operation: Add Edge

- **Time Complexity**: \( O(1) \)  
  Adding an edge involves appending a node to the adjacency list of the corresponding vertex.
- **Space Complexity**: \( O(1) \)  
  Each edge adds a single entry in the adjacency list.

### Operation: Remove Vertex

- **Time Complexity**: \( O(V + E) \)  
  Removing a vertex requires iterating through all adjacency lists to remove references to the vertex and deleting its own list.
- **Space Complexity**: \( O(V + E) \)  
  The adjacency list representation must adjust to store edges for the remaining vertices.

### Operation: Remove Edge

- **Time Complexity**: \( O(V) \)  
  Removing an edge involves searching for the edge in the adjacency list, which may require iterating through a list of size \( O(V) \) in the worst case.
- **Space Complexity**: \( O(1) \)  
  No additional space is needed.

### Operation: Check Edge Existence

- **Time Complexity**: \( O(V) \)  
  Checking for an edge involves searching through the adjacency list of the source vertex, which may take \( O(V) \) in the worst case.
- **Space Complexity**: \( O(1) \)  
  No extra space is needed for this operation.

### Operation: Iterate Over All Neighbors of a Vertex

- **Time Complexity**: \( O(\text{Degree of Vertex}) \)  
  Iterating over neighbors involves traversing the adjacency list of the vertex, which has a size equal to its degree.
- **Space Complexity**: \( O(1) \)  
  No additional space is required.

### Operation: Display the Graph

- **Time Complexity**: \( O(V + E) \)  
  Displaying the graph involves iterating through all vertices and their adjacency lists.
- **Space Complexity**: \( O(V + E) \)  
  The adjacency list representation stores edges explicitly for all vertices.
