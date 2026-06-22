#pragma once

#include "Edge.h"
#include <vector>

//graph capacity - default
constexpr int DEFAULT_MAX_GRAPH_VERTEX_CAPACITY = 1000;
constexpr int DEFAULT_MAX_GRAPH_EDGE_CAPACITY = 1000;

template <typename T>
class Graph
{
private:
    //Stores the vertices for the airport
    T* vertices;
    //Stores the Flight connections
    Edge** edges;
    // Stores the current vertex and edge counts
    int vertexCount, totalEdgeCount;
    // Stores the amount of edges each vertex has
    int* vertexEdgeCounts;
    // Stores the capacities of this object
    int vertexCapacity, edgeCapacity;

    // Sets edge comparison mode. True is distance false is cost
    void setUseDistance(bool useDistance);

public:
    //graph function declarations
    Graph(int vertexCapacity = DEFAULT_MAX_GRAPH_VERTEX_CAPACITY,
        int edgeCapacity = DEFAULT_MAX_GRAPH_EDGE_CAPACITY);

    //adds a new airport vertex
    void pushVertex(T data);

    //adds a flight connection with distance and cost set as weights
    void pushEdge(int index1, int index2, int distance, int cost);

    //returns the count of vertex
    int getVertexCount() const;
    
    //returns the count of Edge
    int getEdgeCount() const;

    //returns vertex index, and -1 if the vertex DNE
    int getVertex(T data) const;

    
    // Sets edge comparison to use distance
    void minDistance();
    // Sets edge comparison to use cost
    void minCost();
};

#include "Graph.tpp"