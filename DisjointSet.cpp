#include "DisjointSet.h"

// Creates a disjoint set, each element contains its own set
DisjointSet::DisjointSet(int size)
{
    this -> size = size;

    //stores memory for parent array
    parent = new int[size];

    for(int i = 0; i < size; i++)
    {
        parent[i] = i;
    }
}

//desctructor
DisjointSet::~DisjointSet()
{
    delete[] parent;
}

// Finds the root parent
int DisjointSet::find(int element)
{
    if(parent[element] == element)
    {
        return element;
    }

    return find(parent[element]);
}

// Merges two sets together
void DisjointSet::unionSets(int first, int second)
{
    int root1 = find(first);
    int root2 = find(second);

    if(root1 != root2)
    {
        parent[root2] = root1;
    }
}