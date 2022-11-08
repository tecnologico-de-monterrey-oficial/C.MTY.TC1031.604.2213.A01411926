#ifndef GraphM_h
#define GraphM_h
#include<iterator>
#include "Vertex.h"

template<class T>
class GraphM {
private:
    vector< vector<int> > graph;
    vector<T> vertices;
    int size; 
    int findVertex(T vertex);
public:
    GraphM();
    GraphM(vector<T> vertices);
    GraphM(vector<T> vertices, vector< Vertex<T> > edges);
    void addEdges(vector< Vertex<T> > edges);
    void addEdge(Vertex<T> edge);
    void addVertex(T vertex); // dejar pendiente
    void print();
};

// Constructor por default
template<class T>
GraphM<T>::GraphM() {
    size = 0;
}

// Constructor con lista de vertices
template<class T>
GraphM<T>::GraphM(vector<T> vertices) {
    this->vertices = vertices;
    size = vertices.size();
    // Actualizar la matriz de adyacencias de acuerdo a la lista de arcos
    // Creamos un renglón del tamaño de vértices con valor por default de 0
    vector<int> row(size, 0);
    // Cambiamos el tamaño de la matriz graph para almacenar todos los elementos de la matriz igual a 0
    graph.resize(size, row);
}

template<class T>
int GraphM<T>::findVertex(T vertex) {
    typename vector<int>::iterator it = find(vertices.begin(), vertices.end(), vertex);
    if (it != vertices.end()) {
        return it - vertices.begin();
    } else {
        return -1;
    }     
}

template<class T>
GraphM<T>::GraphM(vector<T> vertices, vector< Vertex<T> > edges) {
    this->vertices = vertices;
    size = vertices.size();
    // Actualizar la matriz de adyacencias de acuerdo a la lista de arcos
    // Creamos un renglón del tamaño de vértices con valor por default de 0
    vector<int> row(size, 0);
    // Cambiamos el tamaño de la matriz graph para almacenar todos los elementos de la matriz igual a 0
    graph.resize(size, row);
    // Iteramos cada uno de los elementos de vector de arcos
    for (auto vertex : edges) {
        // Creamos un índice del vertice origen <- buscamos el vertice origen en la lista de vertices
        int sourceIndex = findVertex(vertex.source);
        // Revisamos que el vértice origen existe en mi lista de vértice
        if (sourceIndex == -1) {
            throw out_of_range("El vértice no se encuentra en el grafo");
            return;
        }
        // Creamos un índice del vertice destino <- buscamos el vertice destino en la lista de vertices
        int targetIndex = findVertex(vertex.target);
        // Revisamos que el vértice origen existe en mi lista de vértice
        if (targetIndex == -1) {
            throw out_of_range("El vértice no se encuentra en el grafo");
            return;
        }
        // Atualizamos el peso en la posición de la matriz correspondiente
        graph[sourceIndex][targetIndex] = vertex.weight;
    }
}


template<class T>
void GraphM<T>::print() {
    for (int i=0; i<vertices.size(); i++ ) {
        cout << vertices[i] << " ";
        for (int j=0; j<vertices.size(); j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

template<class T>
void GraphM<T>::addEdges(vector< Vertex<T> > edges) {
    // Iteramos cada uno de los elementos de vector de arcos
    for (auto vertex : edges) {
        // Creamos un índice del vertice origen <- buscamos el vertice origen en la lista de vertices
        int sourceIndex = findVertex(vertex.source);
        // Revisamos que el vértice origen existe en mi lista de vértice
        if (sourceIndex == -1) {
            throw out_of_range("El vértice no se encuentra en el grafo");
            return;
        }
        // Creamos un índice del vertice destino <- buscamos el vertice destino en la lista de vertices
        int targetIndex = findVertex(vertex.target);
        // Revisamos que el vértice origen existe en mi lista de vértice
        if (targetIndex == -1) {
            throw out_of_range("El vértice no se encuentra en el grafo");
            return;
        }
        // Atualizamos el peso en la posición de la matriz correspondiente
        graph[sourceIndex][targetIndex] = vertex.weight;
    }
}

template<class T>
void GraphM<T>::addEdge(Vertex<T> edge) {
    // Creamos un índice del vertice origen <- buscamos el vertice origen en la lista de vertices
    int sourceIndex = findVertex(vertex.source);
    // Revisamos que el vértice origen existe en mi lista de vértice
    if (sourceIndex == -1) {
        throw out_of_range("El vértice no se encuentra en el grafo");
        return;
    }
    // Creamos un índice del vertice destino <- buscamos el vertice destino en la lista de vertices
    int targetIndex = findVertex(vertex.target);
    // Revisamos que el vértice origen existe en mi lista de vértice
    if (targetIndex == -1) {
        throw out_of_range("El vértice no se encuentra en el grafo");
        return;
    }
    // Atualizamos el peso en la posición de la matriz correspondiente
    graph[sourceIndex][targetIndex] = vertex.weight;
}

#endif