#pragma once
#include "Graph.h"
#include <iostream>

//Initializes graph storage of elements
template <typename T>
Graph<T>::Graph(int vertexCapacity, int edgeCapacity) :
    vertices(new T[vertexCapacity]),
    edges(new Edge*[vertexCapacity]),
    vertexEdgeCounts(new int[vertexCapacity]()),
    vertexCount(0), totalEdgeCount(0),
    vertexCapacity(vertexCapacity),
    edgeCapacity(edgeCapacity)
{   
    //allocates memory for edge storage
    for(int i = 0; i < vertexCapacity; i++)
        edges[i] = new Edge[edgeCapacity];
}

//adds a vertex to the graph
template <typename T>
void Graph<T>::pushVertex(T data) 
{
    //if vertex exist do not push it again
    if(getVertex(data) != -1)
        return;

    if (vertexCount >= vertexCapacity) {
        std::cout << "Vertex Overflow" << std::endl;
        throw "Vertex Overflow";
    }
    vertices[vertexCount++] = data;
}

//adds a weighted edge into the graph
template <typename T>
void Graph<T>::pushEdge(int start, int end, int distance, int cost)
{
    if (vertexEdgeCounts[start] >= edgeCapacity) {
        std::cout << "Edge Overflow" << std::endl;
        throw "Edge Overflow";
    }
    edges[start][vertexEdgeCounts[start]++] = Edge(start, end, distance, cost);
    totalEdgeCount++;
}

//returns the current # of vertex
template <typename T>
int Graph<T>::getVertexCount() const
{
    return vertexCount;
}

//returns the total current # of edges
template <typename T>
int Graph<T>::getEdgeCount() const
{
    return totalEdgeCount;
}

template <typename T>
int Graph<T>::getVertex(T data) const
{
    //for loop checks every availble index to see if that vertex already exist
    for(int i = 0; i < vertexCount; i++)
        if(vertices[i] == data)
            return i;
    
    //return -1 if vertex does not exist
    return -1;
}

template <typename T>
void Graph<T>::setUseDistance(bool useDistance) {
    // Iterate over every vertex
    for (int i = 0; i < vertexCount; i++)
        // Iterate over every edge of each vertex
        for (int j = 0; j < vertexEdgeCounts[i]; j++)
            // Set them to the proper function
            edges[i][j].useDistance(useDistance);
}

template <typename T>
void Graph<T>::minDistance() {
    setUseDistance(true);
}

template <typename T>
void Graph<T>::minCost() {
    setUseDistance(false);
}