#pragma once
#include "Graph.h"

//Initializes graph storage of elements
template <typename T>
Graph<T>::Graph(int vertexCapacity, int edgeCapacity) :
    vertices(new T[vertexCapacity]),
    edges(new Edge*[vertexCapacity]),
    vertexCount(0), edgeCount(0),
    vertexCapacity(vertexCapacity),
    edgeCapacity(edgeCapacity) 
    
    {
    
    //allocates memory for edge storage
    for(int i = 0; i < vertexCapacity; i++){
        edges[i] = new Edge[edgeCapacity];
    }

    }

//adds a vertex to the graph
template <typename T>
void Graph<T>::pushVertex(T data) 
{
    //if vertex exist do not push it again
    if(getVertex(data) != -1)
    {
        return;
    }

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
    if (edgeCount >= edgeCapacity) {
        std::cout << "Edge Overflow" << std::endl;
        throw "Edge Overflow";
    }
    edges[start][edgeCount++] = Edge(start, end, distance, cost);
}
//returns the current # of vertex
template <typename T>
int Graph<T>::getVertexCount() const
{
    return vertexCount;
}
//returns the current # of edges
template <typename T>
int Graph<T>::getEdgeCount() const
{
    return edgeCount;
}

template <typename T>
int Graph<T>::getVertex(T data) const
{
    //for loop checks every availble index to see if that vertex already exist
    for(int i = 0; i < vertexCount; i++)
    {
        if(vertices[i] == data)
        {
            return i;
        }
    }
    //return -1 if vertex does not exist
    return -1;
}