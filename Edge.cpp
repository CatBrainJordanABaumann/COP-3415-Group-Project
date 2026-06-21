#include "Edge.h"

//default constructor sets all to 0
Edge::Edge()
{
    startIndex = 0;
    endIndex = 0;
    distance = 0;
    cost = 0;
}
//Edge constructor intializes information
Edge::Edge(int start, int end, int dist, int cst)
{
    startIndex = start;
    endIndex = end;
    distance = dist;
    cost = cst;
}

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