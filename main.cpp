#include <iostream>
#include "MinHeap.h"
#include "CSVReader.h"

int main() {
Graph<string> graph;

CSVReader::loadGraph(graph, "airports.csv");
    return 0;
}