#include <iostream>
#include <vector>

using namespace std;

#include "Graph.h"

int main()
{
    vector<int> vertices = {0,1,2,3,4,5,6,7};
    vector< Vertex<int> > edges;
    edges.push_back(Vertex<int>(0,4,1));
    edges.push_back(Vertex<int>(1,0,1));
    edges.push_back(Vertex<int>(1,2,1));
    edges.push_back(Vertex<int>(1,5,1));
    edges.push_back(Vertex<int>(1,6,1));
    edges.push_back(Vertex<int>(2,0,1));    
    edges.push_back(Vertex<int>(2,1,1));
    edges.push_back(Vertex<int>(3,5,1));
    edges.push_back(Vertex<int>(4,2,1));
    edges.push_back(Vertex<int>(4,6,1));
    edges.push_back(Vertex<int>(5,1,1));
    edges.push_back(Vertex<int>(5,6,1));
    edges.push_back(Vertex<int>(5,7,1));
    edges.push_back(Vertex<int>(6,7,1));
    edges.push_back(Vertex<int>(7,6,1));
    Graph<int> graph(vertices, edges);
    graph.print();
    graph.DFS(0);

    return 0;
}