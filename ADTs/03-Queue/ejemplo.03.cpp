#include <iostream>
using namespace std;

#include "Queue.h"

int main()
{
    Queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);
    queue.push(6);
    queue.print();
    queue.pop();
    queue.print();
    cout << queue.getFront() << endl;
    return 0;
}