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
    // Stores the vertices for the airport
    T* vertices;
    // Stores the Flight connections
    Edge** edges;
    // Stores the current vertex and edge counts
    int vertexCount, totalEdgeCount;
    // Stores the amount of edges each vertex has
    int* vertexEdgeCounts;
    // Stores the capacities of this object
    int vertexCapacity, edgeCapacity;

    // Sets edge comparison mode. True is distance false is cost
    void setUseDistance(bool useDistance) const;

public:
    // Graph function declarations
    Graph(int vertexCapacity = DEFAULT_MAX_GRAPH_VERTEX_CAPACITY,
        int edgeCapacity = DEFAULT_MAX_GRAPH_EDGE_CAPACITY);
    
    ~Graph();

    // Adds a new airport vertex
    void pushVertex(T data);

    // Adds a flight connection with distance and cost set as weights
    void pushEdge(int index1, int index2, int distance, int cost);

    // Returns the count of vertex
    int getVertexCount() const;
    
    // Returns the count of Edge
    int getEdgeCount() const;

    // Returns edges exiting from a given vertex
    int getOutgoingEdgeCount(int vertex) const;

    // Returns edges ending at a given vertex
    int getIncomingEdgeCount(int vertex) const;

    // Returns vertex index, and -1 if the vertex DNE
    int getVertex(T data) const;

    void printConnectionCounts() const;

    // Sets edge comparison to use distance
    void minDistance() const;
    // Sets edge comparison to use cost
    void minCost() const;

    // Displays the entire graph
    void print() const;

    // Prints each element in a path seperated by a delimiter
    void printPath(const std::vector<int>& path,
        std::string delimiter = " -> ", bool newline = true) const;
    
    // Converts directed graph to an undirected version
    // Creates a two way edge if one or two edges existed
    Graph toUndirected() const;

    // Creates a copy of the graph found using BFS
    Graph toBFS() const;

    // Creates a copy of the graph found using DFS
    Graph toDFS() const;

    //Generates a minimum spanning tree using prim's algorthim
    Graph prim(int& totalCost);

    //generates a minimum spanning tree using kruska's algorithim
    Graph kruskal(int& totalCost);

    // Returns path of indices from start to end indices
    // Discards paths that take over maxStops stops
    // If maxStops is negative then it has unlimited stops
    // Returns {} if no valid path found
    std::vector<int> djikstraMinPath(
        int startIndex, int endIndex, int maxStops = -1) const;
        
    //total flight path along a distance
    int getPathDistance(const std::vector<int>& path) const;

    // Returns the total cost along a given path of vertex indices
    int getPathCost(const std::vector<int>& path) const;

    // prints shortest path from one airport to every airport in a state
    void shortestPathsToState(int startIndex, const std::string& destState) const;

    // Only implemented for Graph<Airport>
    // Sets if each airport vertex should print its code or state
    void setPrintCode(bool useCode);


};

#include "Graph.tpp"
#include "Prim.tpp"
#include "Kruscal.tpp"
#include "Dijkstra.tpp"