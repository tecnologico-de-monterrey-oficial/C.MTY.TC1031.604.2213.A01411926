#ifndef Graph_h
#define Graph_h

using namespace std;

#include <queue>
#include <stack>
#include "Vertex.h"

template<class T>
class Graph {
private:
    vector< vector< Vertex<T> > > graph;
    vector<T> vertices;
    int size;
    int findVertex(T vertex);
    void DFSR(int vertexIndex, vector<bool> &status);
    int getSmallIndex(vector<bool> status, vector<int> cost);
public:
    Graph();
    Graph(vector<T> vertices);
    Graph(vector<T> vertices, vector< Vertex<T> > edges);
    void addEdges(vector< Vertex<T> > edges);
    void addEdge(Vertex<T> edge);
    void addVertex(T vertex);
    void BFS(T vertex); // Breadth First Search
    void DFS(T vertex); // Depth First Search
    void print();
    void Dijkstra(T vertex);
    void OrigenDestino(T orfigen, T destino);
    void InfoPuerto(T puerto);
};

// Constructor por default
template<class T>
Graph<T>::Graph() {
    size = 0;
}

// Constructor con lista de vertices
template<class T>
Graph<T>::Graph(vector<T> vertices) {
    this->vertices = vertices;
    size = vertices.size();
    // Cambiamos el tamaño de la matriz graph para almacenar todos los vertices
    graph.resize(size);
}

//Agregamos un vertoice al graph
template<class T>
void Graph<T>::addVertex(T vertex){
    this->vertices.push_back(vertex);
}

template<class T>
int Graph <T>::findVertex(T vertex) {
    typename vector<T>::iterator it = find(vertices.begin(), vertices.end(), vertex);
    if (it != vertices.end()) {
        return it - vertices.begin();
    } else {
        return -1;
    }     
}

template<class T>
Graph<T>::Graph(vector<T> vertices, vector< Vertex<T> > edges) {
    this->vertices = vertices;
    size = vertices.size();
    // Cambiamos el tamaño de la matriz graph para almacenar todos los vertices
    graph.resize(size);
    // iteramos en la lista de arcos para agregar cada arco
    for (auto edge : edges) {
        // buscar el indice del arco origen en la lista de vértices
        int sourceIndex = findVertex(edge.source);
        if (sourceIndex == -1) {
            throw out_of_range("El vértice no se encuentra en el grafo");
            return;
        }
        // agregamos el vertex en la poisición del sourceIndex en el grafo
        graph[sourceIndex].push_back(edge);
    }
}

template<class T>
void Graph<T>::BFS(T vertex) {
    // Creamos una vector del mismo tamaño del vector de vertices con valores boleanos inizializado en falso
    vector<bool> status(size, false);
    // Creamos una fila de tipo entero vacía
    queue<int> adjQueue;
    // Buscar el índice del vértice inicial (index)
    int index = findVertex(vertex);
    // validamos si existe
    if (index >= 0) {
        // si existe
        // agregamos el índice a la fila
        adjQueue.push(index);
        // cambiamos el estado del índice del vértice inicial en la lista de estados 
        status[index] = true;
        // Ciclo mientras la lista no este vacía
        while (!adjQueue.empty()) {
            // Obtenemos el elemento del principio de la fila
            index = adjQueue.front();
            // Imprimimos el nodo
            cout << vertices[index] << " ";
            // Recorremos todos los nodos adyacentes
            for (auto adjVertex : graph[index]) {
                // Buscamos el índice del nodo adyacente (adjIndex)
                int adjIndex = findVertex(adjVertex.target);
                // Revisamos el valor en la lista de estados de ese índice
                if (!status[adjIndex]) {
                    // si es falso
                    // agregamos el índice a la fila
                    adjQueue.push(adjIndex);
                    // cambiamos a verdado el valor de ese índice en la lista de estados
                    status[adjIndex] = true;
                }
            }
            // Sacamos el nodo de la fila
            adjQueue.pop();
        }
        // Salto de línea
        cout << endl;
    }


}

template<class T>
void Graph<T>::DFSR(int vertexIndex, vector<bool> &status) {
    // Imprimimos el vértice
    cout << vertices[vertexIndex] << " ";
    // Cambiamos su estado en la lista de estados a procesado
    status[vertexIndex] = true;
    // Recorremos por todos sus vértices adyacentes
    for (auto vertexAdj : graph[vertexIndex]) {
        // Buscamos el índice que corresponde al vértice adyacente
        int index = findVertex(vertexAdj.target);
        // Validamos su estado en la lista de estados
        if (!status[index]) {
            // si es falso
            // Mandamos llamar el proceso recursivo con índice del vertice adyacente y la lista de estados
            DFSR(index, status);
        }
    }
}

template<class T>
void Graph<T>::DFS(T vertex) {
    // buscar el índice del vertex que recibimos como parámetro
    int index = findVertex(vertex);
    // validar si existe
    if (index >= 0) {
        // si existe
        // crear un vector del mismo tamaña que el vector de vértices con valoir falso por default (lista de estados)
        vector<bool> status(size, false);
        // Mandamos llamar al proceso recursivo con el índice y la lista de estados
        DFSR(index, status);
        // Saltamos una línea
        cout << endl;
    }
}

// Buscamos cual es el valor más pequeño del vector de cost que en la tabla de status tenga un valor de falso y obtnemos el índice correspondiente 
template<class T>
int Graph<T>::getSmallIndex(vector<bool> status, vector<int> cost) {
    // Creamos una variable con el valor menor que sea igual a infinito (minCost)
    int minCost = INT_MAX;
    // Creamos una variable para guardar cual fue el índice menor (minIndex) y la igualamos a -1
    int minIndex = -1;
    // Recorremos todos los valor del vector de status
    for (int i=0; i<size; i++) {
        // si el valor del indice actual del ciclo en el vector de status es igual a falso
        if (!status[i]) {
            // si es falso
            // validamos si el costo del indice atual es menor a minCost
            if (cost[i] < minCost) {
                // si es menor
                // cambiamos el valor de minCost por el costo del indice actual
                minCost = cost[i];
                // cambiamos el valor de minIndex por el índice actual
                minIndex = i;
            }
        }
    }
    // Regresar el valor de minIndex
    return minIndex;
}

template<class T>
void Graph<T>::Dijkstra(T vertex) {
    // Obtener el índice del vértice que recibimos de parámetro
    int vertexIndex = findVertex(vertex);
    // Validar que si exista el vértice en la tabla de vértices
    if (vertexIndex >= 0) {
        // Si existe
        // Inicializamos las tablas de trabajo
        // Creamos una vector del tamaño de size y la inicializamos en falso (status)
        vector<bool> status(size, false); // El vector de estatus
        // Creamos una vector del tamaño de size y la inicializamos con infinito (cost)
        vector<int> cost(size, INT_MAX); // El vector de costos
        // Al valor del índice que corresponde al vértice inicial le asignamos 0
        cost[vertexIndex] = 0;
        // Creamos una vector del tanaño de size y la inicializamos en -1
        vector<int> path(size, -1); // El vector de path
        // Creamos un varibale smallIndex y le asignamos el valor de la funcion getSmallIndex
        int smallIndex = getSmallIndex(status, cost);
        // Ciclo mientras smallIndex >= 0
        while (smallIndex >= 0) {
            // Actualizar el estado en el vector de status del smallIndex
            status[smallIndex] = true;
            // Recorremos todos los índice adyacentes del vertice con smallIndex
            for (auto adjVertex : graph[smallIndex]) {
                // Buscamos el índice del vértice adyacente y se lo asignamos a adjIndex
                int adjIndex = findVertex(adjVertex.target);
                // Validamos que en el vector de status en adjIndex sea falso
                if (!status[adjIndex]) {
                    // Si es Falso
                    // Validamos si el costo de adjIndex es mayor al costo de smallIndex + el peso del vértice adyacente
                    if (cost[adjIndex] > cost[smallIndex] + adjVertex.weight) {
                        // Si es mayor
                        // Cambiamos el costo de adjIndex al valor de la suma del costo de smallIndex + el peso del vértice adyacente
                        cost[adjIndex] = cost[smallIndex] + adjVertex.weight;
                        // Cambiamos el valor del path de adjIndex por el valor de smallIndex
                        path[adjIndex] = smallIndex;
                    }
                }
            }
            // actualizams el valor de smallIndex con el valor de la funcion getSmallIndex
            smallIndex = getSmallIndex(status, cost);
        }
        // imprimimos el valor de los vectores de trabajo
        for (auto st : status) {
            cout << st << " ";
        }
        cout << endl;
        // imprimimos el valor de los vectores de trabajo
        for (auto cs : cost) {
            cout << cs << " ";
        }
        cout << endl;
        // imprimimos el valor de los vectores de trabajo
        for (auto pt : path) {
            cout << pt << " ";
        }
        cout << endl;
        // Aquí termina la primera parte del algoritmo
        // Empieza la segunda parte

        // Creamos un vector de pilas de números enteros del tamaño de size (pathStack) vetor< stack<int> > pathStack
        vector < stack<int> > pathStack(size);
        // Recorremos todos los vértices de mi tabla de vértices 
        for (int index = 0; index < size; index++) {
            // Validamos si el valor del vector cost en la posición del índice actual es < menor a infinito
            if (cost[index] < INT_MAX) {
                // Si es menor
                // Insertar el índice actual en la pila en la posición del vector de pilas correspondiente al índice actual (pathStack[i].push(i))
                pathStack[index].push(index);
                // Creamos una variable para guardar el valor actual del path (pathIndex) pathIndex = i
                int pathIndex = index;
                // Ciclo mientras valor del vector path de la posición pathIndex != -1
                while (path[pathIndex] != -1) {
                    // insertar el valor que se encuentra en el vector path en la posición pathIndex en la pila en la posición del vector de pilas correspondiente al índice actual (pathStack[i].push(path[pathIndex]))
                    pathStack[index].push(path[pathIndex]);
                    // Actualizamos el valor de pathIndex con el valor del vector de path en la posición de pathIndex
                    pathIndex = path[pathIndex];
                }
            }
        }
        // Imprimir todos los paths
        for (int i=0; i<size; i++) {
            // imprimimos el vértice
            cout << vertices[i] << " ";
            // imprimimos todos los elementos de la pila
            while (!pathStack[i].empty()) {
                cout << pathStack[i].top() << " ";
                pathStack[i].pop();
            }
            cout << endl;
        }
    } else {
        // No existe
        // Imprimir un error
        cout << "El vértice inicial no existe" << endl;
    }
}

template<class T>
void Graph<T>::OrigenDestino(T origen, T destino) {
    // Obtener los índices de los vértices que recibimos de parámetro
    int origenIndex = findVertex(origen);
    int destinoIndex = findVertex(destino);
    // Validar que si existan los vértices en la tabla de vértices
    if (origenIndex >= 0 && destinoIndex >= 0) {
        // Si existe
        // Inicializamos las tablas de trabajo
        // Creamos una vector del tamaño de size y la inicializamos en falso (status)
        vector<bool> status(size, false); // El vector de estatus
        // Creamos una vector del tamaño de size y la inicializamos con infinito (cost)
        vector<int> cost(size, INT_MAX); // El vector de costos
        // Al valor del índice que corresponde al vértice inicial le asignamos 0
        cost[origenIndex] = 0;
        // Creamos una vector del tanaño de size y la inicializamos en -1
        vector<int> path(size, -1); // El vector de path
        // Creamos un varibale smallIndex y le asignamos el valor de la funcion getSmallIndex
        int smallIndex = getSmallIndex(status, cost);
        // Ciclo mientras smallIndex >= 0
        while (smallIndex >= 0) {
            // Actualizar el estado en el vector de status del smallIndex
            status[smallIndex] = true;
            // Recorremos todos los índice adyacentes del vertice con smallIndex
            for (auto adjVertex : graph[smallIndex]) {
                // Buscamos el índice del vértice adyacente y se lo asignamos a adjIndex
                int adjIndex = findVertex(adjVertex.target);
                // Validamos que en el vector de status en adjIndex sea falso
                if (!status[adjIndex]) {
                    // Si es Falso
                    // Validamos si el costo de adjIndex es mayor al costo de smallIndex + el peso del vértice adyacente
                    if (cost[adjIndex] > cost[smallIndex] + adjVertex.weight) {
                        // Si es mayor
                        // Cambiamos el costo de adjIndex al valor de la suma del costo de smallIndex + el peso del vértice adyacente
                        cost[adjIndex] = cost[smallIndex] + adjVertex.weight;
                        // Cambiamos el valor del path de adjIndex por el valor de smallIndex
                        path[adjIndex] = smallIndex;
                    }
                }
            }
            // actualizams el valor de smallIndex con el valor de la funcion getSmallIndex
            smallIndex = getSmallIndex(status, cost);
        }
        // Aquí termina la primera parte del algoritmo
        // Empieza la segunda parte

        // Creamos un vector de pilas de números enteros del tamaño de size (pathStack) vetor< stack<string> > pathStack
        vector < stack<string> > pathStack(size);
        // Recorremos todos los vértices de mi tabla de vértices 
        for (int index = 0; index < size; index++) {
            // Validamos si el valor del vector cost en la posición del índice actual es < menor a infinito
            if (cost[index] < INT_MAX) {
                // Si es menor
                // Creamos una variable para guardar el valor actual del path (pathIndex) pathIndex = i
                int pathIndex = index;
                // Ciclo mientras valor del vector path de la posición pathIndex != -1
                while (path[pathIndex] != -1) {
                    // insertar el nombre del vértice que se encuentra en el vector path en la posición pathIndex en la pila en la posición del vector de pilas correspondiente al índice actual (pathStack[i].push(vertice[pathIndex]))
                    pathStack[index].push(vertices[pathIndex]);
                    // Actualizamos el valor de pathIndex con el valor del vector de path en la posición de pathIndex
                    pathIndex = path[pathIndex];
                }
            }
        }
        // Imprimimos la ruta del origen al destino
        
        cout << "Ruta de " << vertices[origenIndex] << " a "<< vertices[destinoIndex] << endl;
        // imprimimos el vértice
        cout <<vertices[origenIndex]<<" ";
        // imprimimos todos los elementos de la pila
        while (!pathStack[destinoIndex].empty()) {
            cout << pathStack[destinoIndex].top() << " ";
            pathStack[destinoIndex].pop();
        }
        cout << endl<<"Millas Nauticas: "<<cost[destinoIndex]<<endl;
    } else {
        // No existe
        // Imprimir un error
        cout << "El vértice inicial no existe" << endl;
    }
}

template<class T>
void Graph<T>::InfoPuerto(T puerto) {
    // Obtener el índice del vértice que recibimos de parámetro
    int puertoIndex = findVertex(puerto);
    // Validar que si exista el vértice en la tabla de vértices
    if (puertoIndex >= 0) {
        // Si existe
        // Inicializamos las tablas de trabajo
        // Creamos una vector del tamaño de size y la inicializamos en falso (status)
        vector<bool> status(size, false); // El vector de estatus
        // Creamos una vector del tamaño de size y la inicializamos con infinito (cost)
        vector<int> cost(size, INT_MAX); // El vector de costos
        // Al valor del índice que corresponde al vértice inicial le asignamos 0
        cost[puertoIndex] = 0;
        // Creamos una vector del tanaño de size y la inicializamos en -1
        vector<int> path(size, -1); // El vector de path
        // Creamos un varibale smallIndex y le asignamos el valor de la funcion getSmallIndex
        int smallIndex = getSmallIndex(status, cost);
        // Ciclo mientras smallIndex >= 0
        while (smallIndex >= 0) {
            // Actualizar el estado en el vector de status del smallIndex
            status[smallIndex] = true;
            // Recorremos todos los índice adyacentes del vertice con smallIndex
            for (auto adjVertex : graph[smallIndex]) {
                // Buscamos el índice del vértice adyacente y se lo asignamos a adjIndex
                int adjIndex = findVertex(adjVertex.target);
                // Validamos que en el vector de status en adjIndex sea falso
                if (!status[adjIndex]) {
                    // Si es Falso
                    // Validamos si el costo de adjIndex es mayor al costo de smallIndex + el peso del vértice adyacente
                    if (cost[adjIndex] > cost[smallIndex] + adjVertex.weight) {
                        // Si es mayor
                        // Cambiamos el costo de adjIndex al valor de la suma del costo de smallIndex + el peso del vértice adyacente
                        cost[adjIndex] = cost[smallIndex] + adjVertex.weight;
                        // Cambiamos el valor del path de adjIndex por el valor de smallIndex
                        path[adjIndex] = smallIndex;
                    }
                }
            }
            // actualizams el valor de smallIndex con el valor de la funcion getSmallIndex
            smallIndex = getSmallIndex(status, cost);
        }
        // Aquí termina la primera parte del algoritmo
        // Empieza la segunda parte

        // Creamos un vector de pilas de números enteros del tamaño de size (pathStack) vetor< stack<string> > pathStack
        vector < stack<string> > pathStack(size);
        vector < stack<string> > nopathStack(size);
        // Recorremos todos los vértices de mi tabla de vértices 
        for (int index = 0; index < size; index++) {
            // Validamos si el valor del vector cost en la posición del índice actual es < menor a infinito
            if (cost[index] < INT_MAX) {
                // Si es menor
                // Creamos una variable para guardar el valor actual del path (pathIndex) pathIndex = i
                int pathIndex = index;
                // Ciclo mientras valor del vector path de la posición pathIndex != -1
                while (path[pathIndex] != -1) {
                    // insertar el nombre del vértice que se encuentra en el vector path en la posición pathIndex en la pila en la posición del vector de pilas correspondiente al índice actual (pathStack[i].push(vertice[pathIndex]))
                    pathStack[index].push(vertices[pathIndex]);
                    // Actualizamos el valor de pathIndex con el valor del vector de path en la posición de pathIndex
                    pathIndex = path[pathIndex];
                }
            }
        }
        //Comprobamos cual ruta es la que tiene mayor Millas Náuticas con busqueda sequencial.
        int CostoMayor = 0;
        int MayorIndex;
        for(int i=0;i<cost.size();i++){
            if(cost[i] > CostoMayor && cost[i] != INT_MAX){
                CostoMayor = cost[i];
                MayorIndex = i;
            }
        }

        // Imprimir la mayor ruta
        cout << "La mayor ruta es la ruta de " << vertices[puertoIndex] << " a "<< vertices[MayorIndex] << endl;
        // imprimimos el vértice
        cout <<vertices[puertoIndex]<<" ";
        // imprimimos todos los elementos de la pila
        while (!pathStack[MayorIndex].empty()) {
            cout << pathStack[MayorIndex].top() << " ";
            pathStack[MayorIndex].pop();
        }
        cout << endl<<"Millas Nauticas: "<<cost[MayorIndex]<<endl;

        //Buscamos los puertos inaxesibles por el puerto actual checando cual costo tiene el límite maximo y lo guardamos en una variable
        vector<T> NoAccesible;
        for(int i=0;i<cost.size();i++){
            if(cost[i] == INT_MAX){
                NoAccesible.push_back(vertices[i]);
            }
        }
        //Si el vector no tiene un dato dentro de él quiere decir que puede acceder a todos los puertos.
        if(NoAccesible.size() > 0){
            //No puede acceder a todos
            cout<<"Los puertos a los que no puede acceder son: "<<endl;
            //Imprimimos los puertos a los que no puede acceder
            for(auto el : NoAccesible){
                cout<<el<<endl;
            }
        }
        else{
            //Puede acceder a todos.
            cout<<"Puede acceder a todos los puertos."<<endl;
        }

    } else {
        // No existe
        // Imprimir un error
        cout << "El vértice inicial no existe" << endl;
    }
}

template<class T>
void Graph<T>::print() {
    for (int i=0; i<size; i++) {
        cout << vertices[i] << " ";
        for (auto vertex : graph[i]) {
            cout << vertex.target << "," << vertex.weight << " ";
        }
        cout << endl;
    }
}

#endif