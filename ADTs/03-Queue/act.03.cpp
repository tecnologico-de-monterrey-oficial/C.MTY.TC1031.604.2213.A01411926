#include <iostream>
using namespace std;

#include "Queue.h"

int main()
{
int ans;
Queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);
    queue.push(6);
    queue.print();
cout<< "Elige el metodo (1 = pop, 2 = push, 3 = front)" << endl;
cin >> ans;
    if(ans==1){
        queue.pop();
        queue.print();
    } else if(ans==2){
int n;
cout<< "Ingresa un numero" << endl;
cin >> n;
    queue.push(n);
    } else if(ans==3){
        cout << queue.getFront() << endl;
    }
    return 0;
}