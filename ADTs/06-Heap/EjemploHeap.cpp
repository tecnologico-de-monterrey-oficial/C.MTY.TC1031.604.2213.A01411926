#include <iostream>
#include <vector>
using namespace std;

#include "Heap.h"
#include "MinHeap.h"

template<class T>
void HeapSortD(vector<T>& list) {
    // Creamos un heap en base a la lista
    Heap<T> heap(list); 
    // removemos todos los elementos de la lista
    list.clear();
    // Eliminamos todos los elementos del heap hasta que este vacío
    while (!heap.isEmpty()) {
        // Insertamos en la lista el primer elemento del heap
        list.push_back(heap.getTop());
        // Removemos el primer elemento del heap
        heap.pop();
    }
}

template<class T>
void HeapSortA(vector<T>& list) {
    // Creamos un heap en base a la lista
    MinHeap<T> heap(list); 
    // removemos todos los elementos de la lista
    list.clear();
    // Eliminamos todos los elementos del heap hasta que este vacío
    while (!heap.isEmpty()) {
        // Insertamos en la lista el primer elemento del heap
        list.push_back(heap.getTop());
        // Removemos el primer elemento del heap
        heap.pop();
    }
}

int main()
{
    // vector<int> list = {8,5,17,19,28,21};

    // Ordena la lista de mayor a menor utilizando heap sort
    // HeapSort(list);
    // // Imprime la lista ordenada
    // for (auto el : list) {
    //     cout << el << " ";
    // }
    // cout << endl;

    // MinHeap<int> heap = {31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    vector<int> list = {31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    HeapSortD(list);
    // Imprime la lista ordenada
    for (auto el : list) {
        cout << el << " ";
    }
    cout << endl;
    
    return 0;
}