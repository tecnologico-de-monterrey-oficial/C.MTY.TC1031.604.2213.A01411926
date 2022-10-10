#ifndef dlinkedlist_h
#define dlinkedlist_h
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Node.h"


template<class T>
class dlinkedlist {
private:
    int size;
    NodeD<T>* head;
    NodeD<T>* tail;
    
public:
    
    dlinkedlist(); 
    int getSize();
    void append(T data); 
    void appendLeft(T data); 
    void deleteAt(int index); 
    int findData(T data); 
    T getData(int index); 
    T& operator[](int index); 
    void insert(int index, T data); 
    void deleteData(T data); 
    void print(); 
    void printReverse(); 
    bool isEmpty();
    
};


template<class T>
int dlinkedlist<T>::getSize(){

  return size;
  
}

template<class T>
dlinkedlist<T>::dlinkedlist() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

template<class T>
void dlinkedlist<T>::appendLeft(T data) {
    head = new NodeD<T>(data, head, nullptr);
    if (tail == nullptr) {
        tail = head;
    } else {
        head->next->prev = head;
    }
    size++;
}

template<class T>
void dlinkedlist<T>::append(T data) {
    tail = new NodeD<T>(data, nullptr, tail);
    if (head == nullptr) {
        head = tail;
    } else {
        tail->prev->next = tail;
    }
    size++;
}

template<class T>
T dlinkedlist<T>::getData(int index) {
    if (index >= 0 && index < size) {
        NodeD<T>* aux;
        if (index < size/2) {
            aux = head;
            int auxIndex = 0; 
            while (auxIndex < index) {
                aux = aux->next;
                auxIndex++;
            }   
        } else {
            aux = tail->prev;
            int auxIndex = size - 2; 
            while (auxIndex > index) {
                aux = aux->prev;
                auxIndex--;
            }   
        }
        return aux->data;
    } else {
        throw out_of_range("Índice no válido");
    }
}

template<class T>
T& dlinkedlist<T>::operator[](int index) {
    if (index >= 0 && index < size) {
        NodeD<T>* aux;
        if (index < size/2) {
            aux = head;
            int auxIndex = 0; 
            while (auxIndex < index) {
                aux = aux->next;
                auxIndex++;
            }   
        } else {
            aux = tail->prev;
            int auxIndex = size - 2; 
            while (auxIndex > index) {
                aux = aux->prev;
                auxIndex--;
            }   
        }
        return aux->data;
    } else {
        throw out_of_range("Índice no válido");
    }
}


template<class T>
void dlinkedlist<T>::deleteAt(int index) {
    if (index >= 0 && index < size) {
        if (size == 1) {
            NodeD<T>* aux = head;
            head = nullptr;
            tail = nullptr;
            delete aux;
        } else {
            if (index == 0) {
                NodeD<T>* aux = head;
                head = head->next;
                head->prev = nullptr;
                delete aux;
            } else {
                if (index == size -1) {
                    NodeD<T>* aux = tail;
                    tail = tail->prev;
                    tail->next = nullptr;
                    delete aux;
                } else {
                    NodeD<T>* aux;
                    if (index < size/2) {
                        aux = head->next;
                        int auxIndex = 1; 
                        while (auxIndex < index) {
                            aux = aux->next;
                            auxIndex++;
                        }   
                    } else {
                        aux = tail->prev;
                        int auxIndex = size - 2; 
                        while (auxIndex > index) {
                            aux = aux->prev;
                            auxIndex--;
                        }   
                    }
                    aux->prev->next = aux->next;
                    aux->next->prev = aux->prev;
                    delete aux;
                }
            }
        
        }
        size--;
    } else {
        throw out_of_range("Índice no válido");
    }
}
template<class T>
void dlinkedlist<T>::insert(int index, T data) {
    if (index >= 0 && index < size) {
        if (index < size / 2) {
            int auxIndex = 0;
            NodeD<T>* aux = head;
            while (auxIndex < index) {
                aux = aux->next;
                auxIndex++;
            }
            NodeD<T>* newNode = new NodeD<T>(data, aux->next, aux);
            aux->next = newNode;
            newNode->next->prev = newNode;
        } else {
            if (index == size - 1) {
                tail->next = new NodeD<T>(data, nullptr, tail);
                tail = tail->next;
            } else {
                int auxIndex = size - 2;
                NodeD<T>* aux = tail->prev;
                while (auxIndex > index) {
                    aux = aux->prev;
                    auxIndex--;
                }
                NodeD<T>* newNode = new NodeD<T>(data, aux->next, aux);
                aux->next = newNode;
                newNode->next->prev = newNode;
            }
        }
        size++;
    } else {
        throw out_of_range("Índice no válido");
    }
}

template<class T>
void dlinkedlist<T>::deleteData(T data) {
    NodeD<T>* aux = head;
    if (aux->data == data) {
        if (size == 1) {
            head = nullptr;
            tail = nullptr;
            delete aux;
        } else {
            head = head->next;
            head->prev = nullptr;
            delete aux;
        }
        size--;
    } else {
        aux = aux->next;
        while (aux != nullptr) {
            if (aux->data == data) {
                if (aux->next == nullptr) {
                    tail = aux->prev;
                    tail->next = nullptr;
                    delete aux;
                } else {
                    aux->prev->next = aux->next;
                    aux->next->prev = aux->prev;
                    delete aux;
                }
                size--;
                return;
            } else {
                aux = aux->next;
            }
        }
        throw out_of_range("Dato no econtrado");
    }
}

template<class T>
int dlinkedlist<T>::findData(T data) {
    NodeD<T>* aux = head;
    int auxIndex = 0;
    while (aux != nullptr) {
        if (aux->data == data) {
            return auxIndex;
        } else {
            aux = aux-> next;
            auxIndex++;
        }
    }
    throw out_of_range("El dato no se encuentra");
}


template<class T>
void dlinkedlist<T>::print() {
    NodeD<T>* aux = head;
    while (aux != nullptr) {
        cout << aux->data << " "<<endl;
        aux = aux->next;
    }
    cout << endl;
}


template<class T>
void dlinkedlist<T>::printReverse() {
    NodeD<T>* aux = tail;
    while (aux != nullptr) {
        cout << aux->data << " ";
        aux = aux->prev;
    }
    cout << endl;
}


template<class T>
bool dlinkedlist<T>::isEmpty() {
    return size == 0;
}


#endif