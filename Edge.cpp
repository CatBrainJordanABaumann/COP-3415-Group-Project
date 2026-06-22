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


void Edge::setUseDistance(bool useDistance) {
    this->useDistance = useDistance;
}

void Edge::minDistance() {
    setUseDistance(true);
}

void Edge::minCost() {
    setUseDistance(false);
}


bool Edge::operator<(const Edge& other) const {
    return useDistance ? distance < other.distance : cost < other.cost;
}