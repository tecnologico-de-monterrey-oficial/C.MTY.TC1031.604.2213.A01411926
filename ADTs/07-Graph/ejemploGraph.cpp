#include <iostream>
#include <vector>

using namespace std;

#include "Graph.h"

int main()
{
    vector<int> vertices = {0,1,2,3,4,5,6,7};
    vector< Vertex<int> > edges;
    edges.push_back(Vertex<int>(0,1,1));
    edges.push_back(Vertex<int>(1,0,1));
    edges.push_back(Vertex<int>(1,2,9));
    edges.push_back(Vertex<int>(1,3,6));
    edges.push_back(Vertex<int>(1,5,5));
    edges.push_back(Vertex<int>(1,6,9));
    edges.push_back(Vertex<int>(2,1,9));    
    edges.push_back(Vertex<int>(3,1,6));
    edges.push_back(Vertex<int>(3,5,8));
    edges.push_back(Vertex<int>(4,6,8));
    edges.push_back(Vertex<int>(4,7,8));
    edges.push_back(Vertex<int>(5,1,5));
    edges.push_back(Vertex<int>(5,3,8));
    edges.push_back(Vertex<int>(5,7,5));
    edges.push_back(Vertex<int>(6,1,9));
    edges.push_back(Vertex<int>(6,4,8));
    edges.push_back(Vertex<int>(7,4,8));
    edges.push_back(Vertex<int>(7,5,5));
    Graph<int> graph(vertices, edges);
    graph.print();
    graph.DFS(0);

    return 0;
}