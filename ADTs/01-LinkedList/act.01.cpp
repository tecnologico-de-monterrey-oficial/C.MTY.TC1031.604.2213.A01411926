#include <iostream>
#include <string>
using namespace std;

#include "LinkedList.h"

int main()
{
int ans;
LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);
    list.print();
cout<< "Elige el metodo (1=create, 2=read, 3=update, 4=delete)" << endl;
cin >> ans;
    if(ans==1){
    int n;    
    cout<< "Introduce un numero" << endl;
    cin >> n;
    list.append(n);
    list.print();
    } else if(ans==2){
    int n;
    cout<< "Introduce un numero" << endl;
    cin >> n;
    cout << list.getData(n) << endl;
    } else if(ans==3){
    int n;
    int n1;
    cout<< "Introduce un numero" << endl;
    cin >> n;
    cin >> n1;
    list.update(n,n1);
    list.print();
    } else if(ans==4){
    int n;   
    cout<< "Introduce el índice" << endl;
    cin >> n;
    list.deleteAt(n);
    list.print();
    }
    return 0;
}