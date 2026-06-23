#pragma once

#include "Graph.h"
#include "Stack.h"
#include "Queue.h"
#include "Airport.h"
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

//destructor implimentaion
template <typename T>
Graph<T>::~Graph() {
    if (vertices) {
        delete[] vertices;
        vertices = nullptr;
    }
    if (edges) {
        for (int i = 0; i < vertexCapacity; i++)
            delete[] edges[i];
        delete[] edges;
        edges = nullptr;
    }
    if (vertexEdgeCounts) {
        delete[] vertexEdgeCounts;
        vertexEdgeCounts = nullptr;
    }
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

// Returns edges exiting from a given vertex
template <typename T>
int Graph<T>::getOutgoingEdgeCount(int vertex) const
{
    return vertexEdgeCounts[vertex];
}

// Returns edges ending at a given vertex
template <typename T>
int Graph<T>::getIncomingEdgeCount(int vertex) const
{
    int result = 0;
    // Iterate over every vertex
    for (int i = 0; i < vertexCount; i++)
        // Iterate over every edge of each vertex
        for (int j = 0; j < vertexEdgeCounts[i]; j++)
            // Check if vertex ends at desired
            if (edges[i][j].getEnd() == vertex)
                result++;
    
    return result;
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
void Graph<T>::printConnectionCounts() const {
    int* totalCounts = new int[vertexCount];
    int* order = new int[vertexCount];

    for (int i = 0; i < vertexCount; i++) {
        totalCounts[i] = getOutgoingEdgeCount(i) + getIncomingEdgeCount(i);
        order[i] = i;
    }

    // simple insertion sort, descending by totalCounts
    for (int i = 1; i < vertexCount; i++) {
        int key = order[i];
        int keyCount = totalCounts[key];
        int j = i - 1;

        while (j >= 0 && totalCounts[order[j]] < keyCount) {
            order[j + 1] = order[j];
            j--;
        }
        order[j + 1] = key;
    }

    std::cout << "Airport Connections" << std::endl;
    for (int i = 0; i < vertexCount; i++) {
        int vertexIndex = order[i];
        std::cout << vertices[vertexIndex] << " "
            << totalCounts[vertexIndex] << std::endl;
    }

    delete[] totalCounts;
    delete[] order;
}

template <typename T>
void Graph<T>::setUseDistance(bool useDistance) const{
    // Iterate over every vertex
    for (int i = 0; i < vertexCount; i++)
        // Iterate over every edge of each vertex
        for (int j = 0; j < vertexEdgeCounts[i]; j++)
            // Set them to the proper function
            if (useDistance)
                edges[i][j].minDistance();
            else
                edges[i][j].minCost();
            
}

template <typename T>
void Graph<T>::minDistance() const{
    setUseDistance(true);
}

template <typename T>
void Graph<T>::minCost() const{
    setUseDistance(false);
}


// Displays the entire graph
template <typename T>
void Graph<T>::print() const {
    std::cout << "Vertices:" << std::endl;
    for (int i = 0; i < vertexCount; i++)
        std::cout << vertices[i] << std::endl;
    
    std::cout << "\nEdges:" << std::endl;
    for (int i = 0; i < vertexCount; i++)
        for (int j = 0; j < vertexEdgeCounts[i]; j++) {
            const Edge& currentEdge = edges[i][j];
            std::cout << vertices[i] << " -> "
                << vertices[currentEdge.getEnd()]
                << std::endl;
        }
    std::cout << std::endl;
}


// Prints each element in a path seperated by a delimiter
template <typename T>
void Graph<T>::printPath(const std::vector<int>& path,
    std::string delimiter, bool newline) const {
    if (path.empty())
        return;
    
    std::cout << vertices[path[0]];
    for (int i = 1; i < (int)path.size(); i++)
        std::cout << delimiter << vertices[path[i]];
    if (newline)
        std::cout << std::endl;
}


// Converts directed graph to an undirected version
// Creates a two way edge if one or two edges existed
template <typename T>
Graph<T> Graph<T>::toUndirected() const {
    Graph<T> result(vertexCapacity, edgeCapacity);

    for (int i = 0; i < vertexCount; i++)
        result.pushVertex(vertices[i]);

    bool* pairDone = new bool[vertexCount * vertexCount]();

    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexEdgeCounts[i]; j++) {
            int otherVertex = edges[i][j].getEnd();

            if (pairDone[i * vertexCount + otherVertex] ||
                pairDone[otherVertex * vertexCount + i])
                continue;

            int costToUse = edges[i][j].getCost();

            for (int k = 0; k < vertexEdgeCounts[otherVertex]; k++) {
                if (edges[otherVertex][k].getEnd() == i) {
                    if (edges[otherVertex][k].getCost() < costToUse)
                        costToUse = edges[otherVertex][k].getCost();
                    break;
                }
            }

            result.pushEdge(i, otherVertex, 0, costToUse);
            result.pushEdge(otherVertex, i, 0, costToUse);

            pairDone[i * vertexCount + otherVertex] = true;
            pairDone[otherVertex * vertexCount + i] = true;
        }
    }

    delete[] pairDone;
    return result;
}

// Creates a copy of the graph found using BFS
template <typename T>
Graph<T> Graph<T>::toBFS() const {
    Graph<T> result(vertexCapacity, edgeCapacity);

    if (vertexCount <= 0)
        return result;

    for (int i = 0; i < vertexCount; i++)
        result.pushVertex(vertices[i]);

    int totalVisited = 0;
    bool* visited = new bool[vertexCount]();
    visited[0] = true;

    Queue<int> toVisit;
    toVisit.enqueue(0);
    
    while (!toVisit.isEmpty() && totalVisited < vertexCount - 1) {
        int current = toVisit.peek();
        toVisit.dequeue();

        for (int i = 0; i < vertexEdgeCounts[current]; i++) {
            int currentEnd = edges[current][i].getEnd();
            if (visited[currentEnd])
                continue;
        
            visited[currentEnd] = true;
            toVisit.enqueue(currentEnd);
            totalVisited++;
            result.pushEdge(current, currentEnd,
                edges[current][i].getDistance(), edges[current][i].getCost());
        }
    }

    delete[] visited;
    return result;
}

// Creates a copy of the graph found using DFS
template <typename T>
Graph<T> Graph<T>::toDFS() const {
    Graph<T> result(vertexCapacity, edgeCapacity);

    if (vertexCount <= 0)
        return result;

    for (int i = 0; i < vertexCount; i++)
        result.pushVertex(vertices[i]);

    int totalVisited = 0;
    bool* visited = new bool[vertexCount]();
    visited[0] = true;

    Stack<int> toVisit;
    toVisit.push(0);

    while (!toVisit.isEmpty() && totalVisited < vertexCount - 1) {
        int current = toVisit.peek();
        toVisit.pop();

        for (int i = 0; i < vertexEdgeCounts[current]; i++) {
            int currentEnd = edges[current][i].getEnd();
            if (visited[currentEnd])
                continue;
        
            visited[currentEnd] = true;
            toVisit.push(currentEnd);
            totalVisited++;
            result.pushEdge(current, currentEnd,
                edges[current][i].getDistance(), edges[current][i].getCost());
        }
    }

    delete[] visited;
    return result;
}


// Only implemented for Graph<Airport>
template <typename T>
void Graph<T>::setPrintCode(bool useCode) { }

// Sets if each airport vertex should print its code or state
template <>
inline void Graph<Airport>::setPrintCode(bool useCode) {
    for (int i = 0; i < vertexCount; i++)
        vertices[i].useCode = useCode;
}

template <typename T>
int Graph<T>::getPathDistance(const std::vector<int>& path) const {
    int total = 0;
    for (int i = 0; i + 1 < (int)path.size(); i++) {
        int from = path[i];
        int to = path[i + 1];
        for (int j = 0; j < vertexEdgeCounts[from]; j++) {
            if (edges[from][j].getEnd() == to) {
                total += edges[from][j].getDistance();
                break;
            }
        }
    }
    return total;
}

template <typename T>
int Graph<T>::getPathCost(const std::vector<int>& path) const {
    int total = 0;
    for (int i = 0; i + 1 < (int)path.size(); i++) {
        int from = path[i];
        int to = path[i + 1];
        for (int j = 0; j < vertexEdgeCounts[from]; j++) {
            if (edges[from][j].getEnd() == to) {
                total += edges[from][j].getCost();
                break;
            }
        }
    }
    return total;
}

template <typename T>
void Graph<T>::shortestPathsToState(int startIndex, const std::string& destState) const {
    bool foundAny = false;

    std::cout << "Shortest paths from " << vertices[startIndex]
        << " to " << destState << " state airports are:" << std::endl;
    std::cout << "Path Length Cost" << std::endl;

    for (int i = 0; i < vertexCount; i++) {
        if (i == startIndex)
            continue;
        if (vertices[i].state != destState)
            continue;

        std::vector<int> path = djikstraMinPath(startIndex, i);
        if (path.empty())
            continue;

        foundAny = true;

        printPath(path, "->", false);
        std::cout << " " << getPathDistance(path)
            << " " << getPathCost(path) << std::endl;
    }

    if (!foundAny) {
        std::cout << "No paths found to " << destState << " state airports." << std::endl;
    }
}