#include <iostream>
#include "MinHeap.h"
#include "CSVReader.h"

int main() {
    Graph<string> graph;

    CSVReader::loadGraph(graph, "airports.csv");
    cout << "Vertices: " << graph.getVertexCount() << endl;
    cout << "Edges: " << graph.getEdgeCount() << endl;
    
    return 0;
}