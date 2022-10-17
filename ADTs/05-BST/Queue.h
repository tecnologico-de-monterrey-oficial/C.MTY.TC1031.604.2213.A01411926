#ifndef Queue_h
#define Queue_h

#include "Node.h"

template<class T>
class Queue {
private:
    Node<T>* front;
    int size;
public:
    Queue(); // Constructor de la Fila
    void push(T data); // Agregar un elemento a la fila
    T pop(); // Eliminar el primer elemento de la fila y regresa su valor
    T getFront(); // Regresa el valor del primer elemento de la fila
    void print(); // Imprime la fila
    bool isEmpty(); // Revisa si la fila esta vacía
};

template<class T>
Queue<T>::Queue() {
    size = 0;
    front = nullptr;
}

template<class T>
void Queue<T>::push(T data) {
    // Encontrar cual es el último elemento de la lista
    // Verificar si la lista esta vacia
    if (isEmpty()) {
        // Agregar un elemento nuevo que apunte a nulo
        // Apuntar head a ese elemento
        front = new Node<T>(data);
    } else {
        // Recorrer la lista desde head hasta que el apuntador al siguiente nodo sea igual a nulo
        // Crear un apuntador de tipo node que sea igual a head (aux)
        Node<T>* aux = front;
        // ciclo mientras el puntador next de aux sea diferente de nulo
        while (aux->next != nullptr) {
            // Recorremos aux al siguiente nodo
            aux = aux->next;
        }
        // Apuntar el apuntador next del último elemento a este nuevo elemento
        aux->next = new Node<T>(data);
    }
    // Incrementar en uno el valor del tamaño de la lista 
    size++;
}

template<class T>
T Queue<T>::pop() {
    if (!isEmpty()) {
        // Crear un apuntador auxiliar que apunte a head
        Node<T>* aux = front;
        // craamos un a variable auxiliar para guardar el valor de aux
        T auxData = aux->data;
        // Recorresmos front al valor de next de front
        front = front->next;
        // Borramos aux
        delete aux;
        // Decrementamos el tamaño de la fila
        size--;
        // regresamos auxData
        return auxData;
    } else {
        throw out_of_range("La fila esta vacía");
    }
}

template<class T>
T Queue<T>::getFront() {
    if (!isEmpty()) {
        // regresamos front->data
        return front->data;
    } else {
        throw out_of_range("La fila esta vacía");
    }
}

template<class T>
void Queue<T>::print() {
    // Recorrer la lista de head hasta que el puntador al siguiente nodo sea igual a nulo
    // imprimir nodo por nodo
    Node<T>* aux = front;
    // ciclo mientras el puntador next de aux sea diferente de nulo
    while (aux != nullptr) {
        // Imprimimos el valor del nodo
        cout << aux->data << " ";
        // Recorremos aux al siguiente nodo
        aux = aux->next;
    }
    // Saltamos una línea
    cout << endl;
}

template<class T>
bool Queue<T>::isEmpty() {
    return size == 0;
}


#endif