#include "CSVReader.h"
#include "Airport.h"
#include <fstream>
#include <iostream>
#include <vector>

//parses one CSV row and adds the flight data into the graph
void CSVReader::parseLine(Graph<Airport>& graph, const std::string& line)
{
    //gets airport codes "Abreviated Names Ex: ABQ"
    std::string origin = line.substr(0, 3);
    std::string destination = line.substr(4, 3);

    //find the origins city
    int firstQuote = line.find('"');
    int secondQuote = line.find('"', firstQuote + 1);

    //finds origin city location
    std::string originCity = line.substr(firstQuote + 1, secondQuote - firstQuote - 1);

    //gets origin city and state
    std::string originState = originCity.substr(originCity.size() - 2);

    //find desination city location
    int thirdQuote = line.find('"', secondQuote + 1);
    int fourthQuote = line.find('"', thirdQuote + 1);

    //find desination city and state
    std::string destinationCity = line.substr(thirdQuote + 1, fourthQuote - thirdQuote - 1);
    
    //add orgin airport Data
    std::string destinationState = destinationCity.substr(destinationCity.size() - 2);

    Airport originAirport(origin, originState);
    Airport destinationAirport(destination, destinationState);

    // add airports if they do not exist
    graph.pushVertex(originAirport);
    graph.pushVertex(destinationAirport);

    // find distance and cost location
    int lastComma = line.rfind(',');
    int secondLastComma = line.rfind(',', lastComma - 1);
    
    // find their indices
    int start = graph.getVertex(origin);
    int end = graph.getVertex(destination);

    std::string distanceStr = line.substr(secondLastComma + 1, lastComma - secondLastComma - 1);

    std::string costStr = line.substr(lastComma + 1);
    int distance = stoi(distanceStr);
    int cost = stoi(costStr);

    //push edge with weights
    graph.pushEdge(start, end, distance, cost);
}

void CSVReader::loadGraph(Graph<Airport>& graph, const std::string& filename)
{
    std::ifstream file(filename);

    std::string line;

    // skip header in the CSV
    getline(file, line);

    while(getline(file, line))
    {
        parseLine(graph, line);
    }
}