#pragma once

//Stores the connection flight information
class Edge
{
private:
    //distance and cost are both weights
    //distance -> Dijkstra
    //cost -> prim/kruskal
    int startIndex, endIndex, distance, cost;

public:
    //Edge function declarations

    //default constructor for edge
    Edge();

    //param constructor for edge
    Edge(int start, int end, int dist, int cst);

    //returns start index
    int getStart() const;

    //returns end index
    int getEnd() const;
    //used for shortest path calculations
    int getDistance() const;
    //used for Minumum spanning tree calculations
    int getCost() const;
}; 