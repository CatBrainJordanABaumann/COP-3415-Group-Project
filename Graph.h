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
    //stores the current counts and max capacity
    int vertexCount, edgeCount,
        vertexCapacity, edgeCapacity;

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

};

#include "Graph.tpp"