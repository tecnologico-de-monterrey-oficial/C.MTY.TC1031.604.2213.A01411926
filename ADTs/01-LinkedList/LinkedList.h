#ifndef LinkedList_h
#define LinkedList_h


#include "Node.h"

template<class T>
class LinkedList {
private:
    Node<T>* head;
    int size;
public:
    LinkedList();
    void append(T data); 
    void appendLeft(T data); 
    int findData(T data); 
    T getData(int index); 
    T& operator[](int index); 
    void insert(int index, T data); 
    void deleteAt(int index); 
    void deleteData(T data); 
    void print();
    bool isEmpty();
    void update(int index, T data);
};

template<class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    size = 0;
}
template<class T>
void LinkedList<T>::append(T data) {

    if (isEmpty()) {
        head = new Node<T>(data);
    } else {
        Node<T>* aux = head;
        while (aux->next != nullptr) {
            aux = aux->next;
        }
        aux->next = new Node<T>(data);
    }
    size++;
}
template<class T>
void LinkedList<T>::update(int index, T data){
    if (index >= 0 && index < size) {
        Node<T>* aux = head;
        int auxIndex = 0;
        while (auxIndex < index) {
            auxIndex++;
            aux = aux->next;
        }
        aux->data=data;
    } else {
        throw out_of_range("El índice es inválido");
    }
}
template<class T>
void LinkedList<T>::appendLeft(T data) {
    head = new Node<T>(data, head);
    size++;
}
template<class T>
int LinkedList<T>::findData(T data) {
    
    Node<T>* aux = head;
    if (aux->data == data) {
        int index = 0;
        return index;
        } else {
            Node<T>* prevAux = head;
            aux = head->next;
            int auxIndex = 1;
            while (aux->data != data) {
                auxIndex++;
                prevAux = aux;
                aux = aux->next;
            }
            prevAux->next = aux->next;
            return auxIndex;
        }

}
template<class T>
T LinkedList<T>::getData(int index) {
    if (index >= 0 && index < size) {
        Node<T>* aux = head;
        int auxIndex = 0;
        while (auxIndex < index) {
            auxIndex++;
            aux = aux->next;
        }
        return aux->data;
    } else {
        throw out_of_range("El índice es inválido");
    }
}
template<class T>
T& LinkedList<T>::operator[](int index) {
    if (index >= 0 && index < size) {
        Node<T>* aux = head;
        int auxIndex = 0;
        while (auxIndex < index) {
            auxIndex++;
            aux = aux->next;
        }
        return aux->data;
    } else {
        throw out_of_range("El índice es inválido");
    }
}
template<class T>
void LinkedList<T>::deleteAt(int index) {
    if (index >= 0 && index < size) {
        Node<T>* aux = head;
        if (index == 0) {
            head = head->next;
            delete aux;
        } else {
            Node<T>* prevAux = head;
            aux = head->next;
            int auxIndex = 1;
            while (auxIndex < index) {
                auxIndex++;
                prevAux = aux;
                aux = aux->next;
            }
            prevAux->next = aux->next;
            delete aux;
        }
    } else {
        throw out_of_range("El índice es inválido");
    }
}
template<class T>
void LinkedList<T>::deleteData(T data) {

        Node<T>* aux = head;
        if (aux->data == data) {
            head = head->next;
            delete aux;

        } else {
            Node<T>* prevAux = head;
            aux = head->next;
            int auxIndex = 1;
            while (aux->data != data) {
                auxIndex++;
                prevAux = aux;
                aux = aux->next;
            }
            prevAux->next = aux->next;
            delete aux;
        }
}
template<class T>
void LinkedList<T>::insert(int index, T data) {
    if (index >= 0 && index < size) {
        Node<T>* aux = head; 
        int auxIndex = 0;
        while (auxIndex < index) {
            auxIndex++;
            aux = aux->next;
        }
        aux->next = new Node<T>(data, aux->next);
        size++;
    
    } else {
        throw out_of_range("El índice es inválido");
    }
}
template<class T>
void LinkedList<T>::print() {
    Node<T>* aux = head;
    while (aux != nullptr) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}
template<class T>
bool LinkedList<T>::isEmpty() {
    return size == 0;
}
#endif