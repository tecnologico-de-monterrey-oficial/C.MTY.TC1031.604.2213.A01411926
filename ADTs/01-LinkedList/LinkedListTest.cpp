#include <iostream>

using namespace std;


#include "LinkedList.h"

int main()
{
    LinkedList<string> list;
    list.appendLeft("Z");
    list.print();
    list.append("A");
    list.append("C");
    list.append("D");
    list.appendLeft("Y");
    try {
        list.insert(2,"B");
    } catch(out_of_range &error) {
        cout << error.what() << endl;
    }
    list.print();
    // string aux = list.getData(10);
    try {
        string aux = list.getData(2);
        cout << "Valor de la posición 2: " << aux << endl;
    } catch(out_of_range &error) {
        cout << error.what() << endl;
    }
    list[0] = "X";
    cout << list[0] << endl;
    list.print();
    try {
        list.deleteAt(2);
        list.print();
        list.deleteAt(0);
        list.print();
    } catch(out_of_range &error) {
        cout << error.what() << endl;
    }

    

    
    
    return 0;
}
