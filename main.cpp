#include <iostream>
#include "MinHeap.h"
#include "CSVReader.h"

int main() {
    Graph<Airport> graph;

    // Task 1: build the graph from the CSV/TXT
    CSVReader::loadGraph(graph, "airports.txt");
    graph.setPrintCode(true);

    std::cout << "===== Task 1: Graph Construction =====" << std::endl;
    std::cout << "Vertices: " << graph.getVertexCount() << std::endl;
    std::cout << "Edges: " << graph.getEdgeCount() << std::endl;

    // Task 2: shortest path between two airports
    std::cout << "\n===== Task 2: Shortest Path =====" << std::endl;
    {
        int iad = graph.getVertex(std::string("IAD"));
        int mia = graph.getVertex(std::string("MIA"));
        if (iad != -1 && mia != -1) {
            auto path = graph.djikstraMinPath(iad, mia);
            std::cout << "Shortest route from IAD to MIA: ";
            if (path.empty()) {
                std::cout << "None" << std::endl;
            } else {
                graph.printPath(path, " -> ", false);
                std::cout << ". The length is " << graph.getPathDistance(path)
                    << ". The cost is " << graph.getPathCost(path) << "." << std::endl;
            }
        }

        int pit = graph.getVertex(std::string("PIT"));
        int act = graph.getVertex(std::string("ACT"));
        if (pit != -1 && act != -1) {
            auto path = graph.djikstraMinPath(pit, act);
            std::cout << "Shortest route from PIT to ACT: ";
            if (path.empty())
                std::cout << "None" << std::endl;
            else
                graph.printPath(path);
        }
    }

    // Task 3: shortest paths to all airports in a destination state
    std::cout << "\n===== Task 3: Shortest Paths to a State =====" << std::endl;
    {
        int atl = graph.getVertex(std::string("ATL"));
        if (atl != -1) {
            graph.shortestPathsToState(atl, "FL");
        }
    }

    // Task 4: shortest path with a stop limit
    std::cout << "\n===== Task 4: Shortest Path With Stop Limit =====" << std::endl;
    {
        int iad = graph.getVertex(std::string("IAD"));
        int mia = graph.getVertex(std::string("MIA"));
        if (iad != -1 && mia != -1) {
            auto path = graph.djikstraMinPath(iad, mia, 3);
            std::cout << "Shortest route from IAD to MIA with 3 stops: ";
            if (path.empty()) {
                std::cout << "None" << std::endl;
            } else {
                graph.printPath(path, " -> ", false);
                std::cout << ". The length is " << graph.getPathDistance(path)
                    << ". The cost is " << graph.getPathCost(path) << "." << std::endl;
            }
        }

        int pit = graph.getVertex(std::string("PIT"));
        int act = graph.getVertex(std::string("ACT"));
        if (pit != -1 && act != -1) {
            auto path = graph.djikstraMinPath(pit, act, 2);
            std::cout << "Shortest route from PIT to ACT with 2 stops: ";
            if (path.empty())
                std::cout << "None" << std::endl;
            else
                graph.printPath(path);
        }
    }

    // Task 5: total direct flight connections per airport, sorted
    std::cout << "\n===== Task 5: Airport Connection Counts =====" << std::endl;
    graph.printConnectionCounts();

    // Task 6: convert to undirected graph
    std::cout << "\n===== Task 6: Directed to Undirected Conversion =====" << std::endl;
    Graph<Airport> undirected = graph.toUndirected();
    std::cout << "Undirected vertices: " << undirected.getVertexCount() << std::endl;
    // each undirected edge is stored as two directed entries internally
    std::cout << "Undirected edges (one sided): "
        << undirected.getEdgeCount() << std::endl;
    
    // Task 7: Prim's MST
    std::cout << "\n===== Task 7: Prim's MST =====" << std::endl;
    {
        int totalCost = 0;
        Graph<Airport> primMST = undirected.prim(totalCost);
        std::cout << "Total Cost of MST: " << totalCost << std::endl;
    }

    // Task 8: Kruskal's MST / forest
    std::cout << "\n===== Task 8: Kruskal's MST =====" << std::endl;
    {
        int totalCost = 0;
        Graph<Airport> kruskalMST = undirected.kruskal(totalCost);
        std::cout << "Total Cost of MST: " << totalCost << std::endl;
    }

    return 0;
}