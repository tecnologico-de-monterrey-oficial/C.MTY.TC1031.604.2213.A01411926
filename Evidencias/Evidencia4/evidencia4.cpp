#include <iostream>
#include <fstream>
#include <vector>
#include "Vertex.h"
#include <string>
#include "Graph.h"
#include "HashMat.h"

using namespace std;
int main(){
    // Creamos variables que vamos a utilizar
    ifstream file;
    string filename;
    bool loop = true;
    int option = 0;
    // Insertamos el nombre del archivo, si un archivo no es detectado, se reinicia el loop hasta que el archivo insertado pueda ser detectado
    while (loop){
        cout << endl << "Introduce el nombre COMPLETO del archivo a leer (Ejemplo: test.txt)." << endl;
        cin >> filename;
        ifstream fileCheck(filename);
        if(fileCheck.good()){
            loop = false;
        } else {
            cout << "ERROR. INTENTE NUEVAMENTE" << endl;
        }
    }
    // Abrimos el archivo para poder sacar datos de el
    file.open(filename);
    // Creamos variables para que los datos del archivo puedan ser temporalmente guardados e insertados en el graph, después de haber sido guardados en el Hash
    int peso,N;
    string origen, destino, vertice;
    HashMat vertices;
    vector<Vertex<string>> edges;
    //Sacamos el número de edges que van a haber dentro del documento
    file >> N;
    //Agregamos los edges a un vector
    for(int i=0;i<N;i++){
        file>>origen>>destino>>peso;
        Vertex<string> edge(origen,destino,peso);
        edges.push_back(edge);
    }   
    //Sacamos el número de vertices que van a haber dentro del documento
    file >> N;
    //Agregamos los vertices al heap
    for(int i=0;i<N;i++){
        file>>vertice;
        vertices.addMatricula(vertice);
    }   
    //Creamos el graph
    Graph<string> graph;

    //Insertamos los vertices al graph
    for(int i=0;i<99;i++){
        if(vertices.get(i) != ""){
            graph.addVertex(vertices.get(i));
        }
    } 
    //Insertamos las conecciones al graph
    graph.addEdges(edges);

    //Conseguimos el puerto de origen y destino para buscar su ruta
    string pOrigen, pDestino;
    cout<<"Seleccione un puerto de origen."<<endl;
    cin>>pOrigen;
    cout<<"Seleccione un puerto de destino."<<endl;
    cin>>pDestino;
    cout<<endl;
    //Buscamos e imprimimos su ruta con el método de Dijkstra
    graph.OrigenDestino(pOrigen,pDestino);
    cout<<endl;

    //Sacamos la ruta más larga de este puerto, junto con los puertos a los que no puede acceder y los imprimimos
    graph.InfoPuerto(pOrigen);

    loop = true;
    //Damos la opción de poder sacar información de otro puerto;
    while(loop){
        cout << endl << "¿DESPLEGAR INFORMACIÓN DE OTRA RUTA?" << endl;
        cout << "1. SI" << endl;
        cout << "2. TERMINAR PROGRAMA" << endl;
        cin >> option;
        if(option == 1){
            cout<<endl<<"Seleccione un puerto."<<endl;
            cin>>pOrigen;
            cout<<endl;
            graph.InfoPuerto(pOrigen);
        }
        else if(option == 2){
            loop = false;
        }
        else{
            cout << "ERROR. INTENTE NUEVAMENTE." << endl;
        }
    }
    cout<<"Ha terminado el programa"<<endl;
}