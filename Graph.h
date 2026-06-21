#pragma once

#include "Edge.h"
#include <vector>

constexpr int DEFAULT_MAX_GRAPH_VERTEX_CAPACITY = 1000;
constexpr int DEFAULT_MAX_GRAPH_EDGE_CAPACITY = 1000;

template <typename T>
class Graph
{
private:
    T* vertices;
    Edge** edges;
    int vertexCount, edgeCount,
        vertexCapacity, edgeCapacity;

public:
    Graph(int vertexCapacity = DEFAULT_MAX_GRAPH_VERTEX_CAPACITY,
        int edgeCapacity = DEFAULT_MAX_GRAPH_EDGE_CAPACITY);

    void pushVertex(T data);
    void pushEdge(int index1, int index2, int weight);


};

#include "Graph.tpp"