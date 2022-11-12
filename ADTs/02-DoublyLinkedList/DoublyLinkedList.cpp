#include <iostream>
using namespace std;

#include "DoublyLinkedList.h"

int main()
{
    DoublyLinkedList<int> list;

    list.append(5);
    list.deleteData(5);
    list.print();
    list.append(10);
    list.appendLeft(15);
    list.appendLeft(20);
    list.print(); 
    list.deleteData(15);
    list.deleteData(20);
    list.print();    
    list.insert(0,20);
    list.insert(1,30);
    list.append(40);
    try {
        int index = list.findData(40);
        cout << "el dato se encuentra en el índice: " << index << endl;
        int aux = list.getData(3);
        cout << "el dato en la posición 3 es: " << aux << endl;
        list[3] = 50;
        aux = list.getData(3);
        cout << "el dato en la posición 3 es: " << aux << endl;
        list.deleteAt(3);
        list.deleteAt(0);
        list.print();
        list.deleteAt(0);
        list.deleteAt(0);
        list.print();
        list.deleteAt(0);
    } catch(out_of_range &error) {
        cout << error.what() << endl;
    }
    
        
    return 0;
}
