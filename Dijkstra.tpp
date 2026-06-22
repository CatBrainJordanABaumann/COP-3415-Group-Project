#pragma once

#include "MinHeap.h"
#include "Graph.h"

template <typename T>
std::vector<int> Graph<T>::djikstraMinPath(int startIndex, int endIndex) {
    minDistance();

    bool* visited = new bool[vertexCount]();
    int* distances = new int[vertexCount]();
    std::vector<int>* paths = new std::vector<int>[vertexCount]();

    for (int i = 0; i < vertexCount; i++) {
        distances[i] = i == startIndex ? 0 : __INT_MAX__;
        paths[i].push_back(startIndex);
    }
    
    
    MinHeap<Edge> toSearch;
    int currentVertex = startIndex;

    for (int verticesVisited = 0; verticesVisited < vertexCount;
        verticesVisited++) {
        for (int i = 0; i < vertexEdgeCounts[i]; i++) {
            Edge& currentEdge = edges[currentVertex][i].getEnd();
            int currentEnd = currentEdge.getEnd();

            if (visited[currentEnd])
                continue;
            
            toSearch.push(currentEdge);

            int totalDist = distances[i] + currentEdge.distance;

            if (totalDist >= distances[currentEnd])
                continue;
            
            distances[currentEnd] = totalDist;
            paths[i] = paths[currentVertex];
            paths[i].push_back(i);
        }
    
        Edge bestEdge = toSearch.pop();
    
        visited[currentVertex] = true;
        currentVertex = bestEdge.getEnd();
    }

    return paths[endIndex];
}