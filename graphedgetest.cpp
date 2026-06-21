#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
    Graph<int> g;

    cout << "Adding vertices..." << endl;

    g.pushVertex(1);
    g.pushVertex(2);

    cout << "Adding edge..." << endl;

    g.pushEdge(0, 1, 424, 374);

    cout << "It works!" << endl;

    return 0;
}