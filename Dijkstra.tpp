#pragma once

#include "MinHeap.h"
#include "Graph.h"

//finds shortest path by distance, limited by max stops optionally
template <typename T>
std::vector<int> Graph<T>::djikstraMinPath(
    int startIndex, int endIndex, int maxStops) const {

    minDistance();// use distances for comparing

    bool* visited = new bool[vertexCount]();
    int* distances = new int[vertexCount]();
    std::vector<int>* paths = new std::vector<int>[vertexCount];
    
    //start with all unreachables exept for the start
    for (int i = 0; i < vertexCount; i++) {
        distances[i] = (i == startIndex) ? 0 : __INT_MAX__;
    }
    paths[startIndex].push_back(startIndex);

    MinHeap<Edge> toSearch;

    // seed the heap with the start vertex at dist 0
    Edge startEntry(startIndex, startIndex, 0, 0);
    toSearch.push(startEntry);

    while (!toSearch.empty()) {
        Edge current = toSearch.pop();
        int currentVertex = current.getEnd();
        int currentDist = current.getDistance();

        //skip if visited
        if (visited[currentVertex])
            continue;

        visited[currentVertex] = true;

        //skip if it took to many stops
        int stopsSoFar = (int)paths[currentVertex].size() - 1;
        if (maxStops != -1 && stopsSoFar > maxStops)
            continue;

        //checks every flight outside of the vertex
        for (int i = 0; i < vertexEdgeCounts[currentVertex]; i++) {
            Edge& flight = edges[currentVertex][i];
            int nextVertex = flight.getEnd();

            if (visited[nextVertex])
                continue;

            //found a shorter way, and then updates it
            int newDist = currentDist + flight.getDistance();

            if (newDist < distances[nextVertex]) {
                distances[nextVertex] = newDist;

                paths[nextVertex] = paths[currentVertex];
                paths[nextVertex].push_back(nextVertex);

                Edge nextEntry(currentVertex, nextVertex, newDist, 0);
                toSearch.push(nextEntry);
            }
        }
    }

    std::vector<int> result = paths[endIndex];

    delete[] visited;
    delete[] distances;
    delete[] paths;
    //empty path = start vertex only, so no real path is found
    return (result.size() > 1) ? result : std::vector<int>{};
}
