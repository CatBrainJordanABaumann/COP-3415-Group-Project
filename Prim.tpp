#pragma once

#include "Graph.h"
#include "MinHeap.h"
#include "DisjointSet.h"
#include <iostream>

template <typename T>
Graph<T> Graph<T>::prim(int& totalCost)
{
    //cost edge comparison weight
    minCost();

    Graph<T> result(vertexCapacity, edgeCapacity);

    //initialize total cost 
    totalCost = 0;

    // copy vertices result graph
    for(int i = 0; i < vertexCount; i++)
    {
        result.pushVertex(vertices[i]);
    }

    //track visted vertex's
    bool* visited = new bool[vertexCount]();

    //start from first vertex
    visited[0] = true;

    //store candidite edges
    MinHeap<Edge> frontier;

    // add starting edges
    for(int i = 0; i < vertexEdgeCounts[0]; i++)
    {
        frontier.push(edges[0][i]);
    }

    //continue while candidate edges exist
    while(!frontier.empty())
    {
        Edge current = frontier.pop();

        int destination = current.getEnd();

        if(visited[destination])
        {
            continue;
        }

        result.pushEdge(
            current.getStart(),
            current.getEnd(),
            current.getDistance(),
            current.getCost()
        );
        //Add edge cost to total cost
        totalCost += current.getCost();

        //mark vertex as vistited
        visited[destination] = true;

        //add the outgoing edges
        for(int i = 0;
            i < vertexEdgeCounts[destination];
            i++)
        {
            frontier.push(
                edges[destination][i]
            );
        }
    }

    int totalVisited = 0;
    for (int i = 0; i < vertexCount; i++)
        if (visited[i])
            totalVisited++;

    if (totalVisited < vertexCount) {
        std::cout << "Graph is disconnected. MST cannot be formed." << std::endl;
    }

    delete[] visited;

    return result;
}