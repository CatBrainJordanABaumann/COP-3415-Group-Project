#pragma once

#include "Graph.h"
#include "MinHeap.h"
#include "DisjointSet.h"

template <typename T>
Graph<T> Graph<T>::kruskal(int& totalCost)
{   
    //cost as edge wieght
    minCost();

    Graph<T> result(vertexCapacity, edgeCapacity);

    totalCost = 0;

    // copy vertices
    for(int i = 0; i < vertexCount; i++)
    {
        result.pushVertex(vertices[i]);
    }

    // create disjoint sets
    DisjointSet sets(vertexCount);

    // store all edges in heap
    MinHeap<Edge> edgeHeap;

    for(int i = 0; i < vertexCount; i++)
    {
        for(int j = 0; j < vertexEdgeCounts[i]; j++)
        {
            edgeHeap.push(edges[i][j]);
        }
    }

    while(!edgeHeap.empty())
    {
        Edge current = edgeHeap.pop();

        int start = current.getStart();
        int end = current.getEnd();

        // skip if already connected
        if(sets.find(start) == sets.find(end))
        {
            continue;
        }

        // add edge to MST / forest
        result.pushEdge(
            start,
            end,
            current.getDistance(),
            current.getCost()
        );

        totalCost += current.getCost();

        // merge components
        sets.unionSets(start, end);
    }

    return result;
}