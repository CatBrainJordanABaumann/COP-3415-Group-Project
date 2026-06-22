#include <iostream>
#include "MinHeap.h"
#include "CSVReader.h"

int main() {
    Graph<Airport> graph;

    CSVReader::loadGraph(graph, "airports.csv");
    std::cout << "Vertices: " << graph.getVertexCount() << std::endl;
    std::cout << "Edges: " << graph.getEdgeCount() << std::endl;

    //graph.setPrintCode(true);
    //graph.print();
    //graph.setPrintCode(false);
    //graph.print();
    
    return 0;
}