#ifndef Stack_h
#define Stack_h

template<class T>
class Stack {
private:
    Node<T>* top;
    int size;
public:
    Stack(); // constructor por default
    T getTop(); // regresa el valor de arriba del stack
    T pop(); // Elimina el valor de arriba del stack
    void push(T data); // agrega un elemento a arriba del stack
    void print() // Imprime el stack
    bool isEmpty(); // Regresa si el stack esta vacio
};

#endif