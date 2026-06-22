#include "CSVReader.h"
#include "Airport.h"
#include <fstream>
#include <iostream>
#include <vector>

//stores airport information 
vector<Airport> airportList;

//checks if airport already exist in the list
bool airportExists(string code)
{
    for (int i = 0; i < airportList.size(); i++)
    {
        if (airportList[i].code == code)
        {
            return true;
        }
    }

    return false;
}

//parses one CSV row and adds the flight data into the graph
void CSVReader::parseLine(Graph<string>& graph, string line)
{
    //gets airport codes "Abreviated Names Ex: ABQ"
    string origin = line.substr(0, 3);
    string destination = line.substr(4, 3);

    //find the origins city
    int firstQuote = line.find('"');
    int secondQuote = line.find('"', firstQuote + 1);

    //finds origin city location
    string originCity = line.substr(firstQuote + 1, secondQuote - firstQuote - 1);

    //gets origin city and state
    string originState = originCity.substr(originCity.size() - 2);

    //find desination city location
    int thirdQuote = line.find('"', secondQuote + 1);
    int fourthQuote = line.find('"', thirdQuote + 1);

    //find desination city and state
    string destinationCity = line.substr(thirdQuote + 1, fourthQuote - thirdQuote - 1);
    
    //add orgin airport Data
    string destinationState = destinationCity.substr(destinationCity.size() - 2);   
    if (!airportExists(origin))
    {
        Airport airport;
        airport.code = origin;
        airport.state = originState;
        airportList.push_back(airport);
    }

    //adds desination Data
    if (!airportExists(destination))
    {
        Airport airport;
        airport.code = destination;
        airport.state = destinationState;

        airportList.push_back(airport);
    }    

    // add airports if they do not exist
    graph.pushVertex(origin);
    graph.pushVertex(destination);

    // find distance and cost location
    int lastComma = line.rfind(',');
    int secondLastComma = line.rfind(',', lastComma - 1);
    
    // find their indices
    int start = graph.getVertex(origin);
    int end = graph.getVertex(destination);

    string distanceStr = line.substr(secondLastComma + 1, lastComma - secondLastComma - 1);

    string costStr = line.substr(lastComma + 1);
    int distance = stoi(distanceStr);
    int cost = stoi(costStr);

    //push edge with weights
    graph.pushEdge(start, end, distance, cost);
}

void CSVReader::loadGraph(Graph<string>& graph, string filename)
{
    ifstream file(filename);

    string line;

    // skip header in the CSV
    getline(file, line);

    while(getline(file, line))
    {
        parseLine(graph, line);
    }
}