#include "Edge.h"

//Edge constructor intializes information
Edge::Edge(int startIndex, int endIndex, int distance, int cost) :
    startIndex(startIndex), endIndex(endIndex),
    distance(distance), cost(cost) { }

//getters for an Edge
int Edge::getStart() const
{
    return startIndex;
}

int Edge::getEnd() const
{
    return endIndex;
}

int Edge::getDistance() const
{
    return distance;
}

int Edge::getCost() const
{
    return cost;
}


void Edge::minDistance() {
    useDistance = true;
}

void Edge::minCost() {
    useDistance = false;
}


bool Edge::operator<(const Edge& other) const {
    return useDistance ? distance < other.distance : cost < other.cost;
}