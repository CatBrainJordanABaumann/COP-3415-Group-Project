#pragma once

#include <string>
#include "Graph.h"
#include "Airport.h"

//reads the airports CVS file and Builds the graph from it
namespace CSVReader {
    void loadGraph(Graph<Airport>& graph, const std::string& filename);
};