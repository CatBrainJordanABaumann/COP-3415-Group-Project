#pragma once

//Stores the connection flight information
class Edge
{
private:
    //distance and cost are both weights
    //distance -> Dijkstra
    //cost -> prim/kruskal
    int startIndex, endIndex, distance, cost;
    bool useDistance;

    // Sets edge comparison mode. True is distance false is cost
    void setUseDistance(bool useDistance);

public:
    //Edge function declarations

    //param constructor for edge
    Edge(int startIndex = 0, int endIndex = 0, int distance = 0, int cost = 0);

    //returns start index
    int getStart() const;

    //returns end index
    int getEnd() const;
    //used for shortest path calculations
    int getDistance() const;
    //used for Minumum spanning tree calculations
    int getCost() const;

    // Used for conversion from directed to undirected graphs
    void setCost(int cost);

    // Sets edge comparison to use distance
    void minDistance();
    // Sets edge comparison to use cost
    void minCost();

    bool operator<(const Edge& other) const;
}; 