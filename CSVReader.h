#pragma once

#include <string>
#include "Graph.h"
#include "Airport.h"

class CSVReader
{
private:
    static void parseLine(Graph<Airport>& graph, const std::string& line);

public:
    static void loadGraph(Graph<Airport>& graph, const std::string& filename);
};

