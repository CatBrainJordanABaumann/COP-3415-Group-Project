#pragma once

#include <string>
#include "Graph.h"

using namespace std;

class CSVReader
{
private:
    static void parseLine(Graph<string>& graph, string line);

public:
    static void loadGraph(Graph<string>& graph, string filename);
};

