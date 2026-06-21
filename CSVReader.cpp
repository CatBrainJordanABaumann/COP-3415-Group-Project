#include "CSVReader.h"
#include <fstream>
#include <iostream>

void CSVReader::loadGraph(Graph<string>& graph, string filename)
{
    ifstream file(filename);

    string line;


    getline(file, line);

    while(getline(file, line))
    {
        cout << line << endl;
    }
}