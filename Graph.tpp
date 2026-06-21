#pragma once
#include "Graph.h"

template <typename T>
Graph<T>::Graph(int vertexCapacity, int edgeCapacity) :
    vertices(new T[vertexCapacity]),
    edges(new Edge[vertexCapacity][edgeCapacity]),
    vertexCount(0), edgeCount(0),
    vertexCapacity(vertexCapacity),
    edgeCapacity(edgeCapacity) { }


template <typename T>
void Graph<T>::pushVertex(T data) {
    if (vertexCount >= vertexCapacity) {
        std::cout << "Vertex Overflow" << std::endl;
        throw "Vertex Overflow";
    }
    vertices[size++] = data;
}

template <typename T>
void Graph<T>::pushEdge(int start, int end, int weight) {
    if (edgeCount >= edgeCapacity) {
        std::cout << "Edge Overflow" << std::endl;
        throw "Edge Overflow";
    }
    edges[start][edgeCount++] = Edge(start, end, weight);
}