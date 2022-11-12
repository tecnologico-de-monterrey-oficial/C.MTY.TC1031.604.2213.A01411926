#ifndef Stack_h
#define Stack_h

#include "Node.h"

template<class T>
class Stack {
private:
    Node<T>* front;
    int size;
public:
    Stack(); 
    T pop();
    void push(T data); 
    T peak(); 
    void print(); 
    bool isEmpty(); 
};

template<class T>
Stack<T>::Stack(){
    front = nullptr;
    size = 0;
}
template<class T>
void Stack<T>::push(T data){
    Node<T>* aux = front;
    front = new Node<T>(data, front);
    this->size++;
}

template<class T>
T Stack<T>::peak() {
    return front->data;
}
template<class T>
T Stack<T>::pop() {
        Node<T>* temp = front;
        T toReturn = temp->data;
        front = front->next;
        delete temp;
        return toReturn;
}
template<class T>
void Stack<T>::print(){
    Node<T>* aux = front;
    int x = 1;
    while (aux-> next != nullptr)
    {
        cout << "dato " << x << ": " << aux->data << endl;
        x++;
        aux = aux -> next;
    }
    cout << "dato " << x << ": " << aux->data << endl;
}
template<class T>
bool Stack<T>::isEmpty() {
    return size == 0;
}
#endif