#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
    Graph<int> g;

    g.pushVertex(1);
    g.pushVertex(2);

    g.pushEdge(0, 1, 424, 374);

    cout << "Vertices: "
         << g.getVertexCount()
         << endl;

    cout << "Edges: "
         << g.getEdgeCount()
         << endl;

    return 0;
}