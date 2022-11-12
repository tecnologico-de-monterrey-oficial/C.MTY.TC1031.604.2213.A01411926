#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "Log.h"
#include "Heap.h"
#include "MinHeap.h"
#include "BST.h"

using namespace std;

// Ordenamos la lista de menor a mayor con HeapSort
void HeapSortA(vector<Log>& list){
    MinHeap<Log> heap(list);
    list.clear();
    while(!heap.isEmpty()){
        list.push_back(heap.getTop());
        heap.pop();
    }    
}
// Ordenamos la lista de mayor a menor con HeapSort
void HeapSortD(vector<Log>& list){
    Heap<Log> heap(list);
    list.clear();
    while(!heap.isEmpty()){
        list.push_back(heap.getTop());
        heap.pop();
    }    
}
// Se despliega la lista de logs insertada, en formato de entrada, ubi, fecha y hora de entrada
void printAll(vector<Log> logs){
    for (auto log : logs){
        cout<< log.entry << " UBI: " << log.ubi << " datetime: " << log.date << " " << log.time << endl;
    }
}
int main(){
    // Creamos variables que vamos a utilizar
    ifstream file;
    string filename, ubisearch;
    int option = 0, option2 = 0;
    bool loop = true, loop2 = true;
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
    // Creamos variables para que los datos del archivo puedan ser temporalmente guardados e insertados en la clase log y luego guardarse en un vector
    string date, time, entry, ubi;
    vector<Log> logsM, logsR, logsCopy;
    BST<Log> tree;
    // Guardamos los datos del archivo, creamos un Log en el que se guardan las variables, y las metemos en una matriz dependiendo de su punto de entrada
    // Luego metemos los datos de ambas matrizes a un árbol de búsqueda binario
    while(file >> date >> time >> entry >> ubi){
        Log log(date, time, entry, ubi);
        if (entry == "M"){
            logsM.push_back(log);
        } else if (entry == "R"){
            logsR.push_back(log);
        }
        tree.insert(log);
    }
    loop=true;
    // Creamos el menú que nos ayuda a controlar el programa
    while (loop){
        loop2 = true;
        cout << endl << "SELECCIONE LA OPCIÓN DESEADA: " << endl;
        cout << "1. Desplegar entradas del Mar Mediterráneo" << endl;
        cout << "2. Desplegar entradas del Mar Mar Rojo" << endl;
        cout << "3. Buscar UBI" << endl;
        cout << "4. SALIR" << endl;
        cin >> option;
        cout << endl;
        // Opción 1 y 2: Desplegar los datos ordenados
        if(option == 1 || option == 2){
            // Dependiendo de que opción halla sido seleccionada, se creará un vector temporal que guardara los valores seleccionados para que después pueda ser despleado.
            if(option == 1){
                logsCopy = logsM;
            }
            else{
                logsCopy = logsR;
            }
            // Se selecciona si se quiere de mayor a menor o de menor a mayor y el vector con los datos se envía a la función de Heap Sort que se definió.
            // Después de ordenar los datos de la manera requerida, se imprimen los datos.
            while (loop2){
                cout << endl << "SELECCIONE LA OPCIÓN DESEADA" << endl;
                cout << "1. MAYOR A MENOR" << endl;
                cout << "2. MENOR A MAYOR" << endl;
                cout << "3. VOLVER" << endl;
                cin >> option2;
                cin.clear();
                if(option2 == 1){
                    HeapSortD(logsCopy);
                    printAll(logsCopy);
                    loop2 = false;
                }
                else if(option2 == 2){
                    HeapSortA(logsCopy);
                    printAll(logsCopy);
                    loop2 = false;
                }
                else if(option2 == 3){
                    loop2 = false;
                }
                else{
                    cout << "ERROR. INTENTE NUEVAMENTE." << endl;
                }
            }
        }
        // Opción 3: Buscar por UBI
        else if(option == 3){
            while(loop2){
                // Se inserta la UBI pedida, y si no es "VOLVER" se envía a la función dentro de la clase de árbol llamada searchByUbi."
                cout << endl << "INTRODUZCA EL UBI O ESCRIBA 'VOLVER' " << endl;
                cin >> ubisearch;
                if(ubisearch=="VOLVER"){
                    loop2 = false;
                } 
                else {
                    tree.searchByUbi(ubisearch);
                }
            }
        }
        // Opción 4: Terminar el programa.
        else if(option == 4){
            cout << "PROGRAMA FINALIZADO" << endl;
            loop = false;
        }
        else{
            cout << "ERROR. INTENTE NUEVAMENTE." << endl;
        }
    }
    return 0;
}