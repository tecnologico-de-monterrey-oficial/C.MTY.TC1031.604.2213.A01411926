#include <iostream>
using namespace std;

#include "Stack.h"

int main()
{
    Stack<int> stack;    
    stack.push(40);
    stack.push(20);    
    stack.push(60); 
    stack.push(10);
    stack.push(30);
    stack.push(15);   
    stack.push(25);
    stack.push(12);
    stack.print();
    cout << stack.peak() << endl;
    stack.pop();
    stack.print();
    return 0;
}