#pragma once

//stores and manages disjoint set
class DisjointSet
{
private:
    //stores the parent of each element
    int* parent;

    //stores the the total ammount of elements
    int size;

public:

    //creates disjoint set
    DisjointSet(int size);

    //destructor
    ~DisjointSet();

    //returns root parent of a element
    int find(int element);

    //Merge the sets together
    void unionSets(int first, int second);
};