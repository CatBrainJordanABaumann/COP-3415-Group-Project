#pragma once

#include <string>
#include "Graph.h"
#include "Airport.h"

//reads the airports CVS file and Builds the graph from it
class CSVReader
{

private:
    //parses one line of the CSV and adds it to the graph
    static void parseLine(Graph<Airport>& graph, const std::string& line);

public:
    //opens the file and reads every line into the graph
    static void loadGraph(Graph<Airport>& graph, const std::string& filename);
};

