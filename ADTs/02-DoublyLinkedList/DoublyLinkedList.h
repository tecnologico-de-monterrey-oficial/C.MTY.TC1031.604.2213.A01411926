#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include "NodeD.h"

template<class T>
class DoublyLinkedList {
private:
    NodeD<T>* head;
    NodeD<T>* tail;
    int size;
public:
    DoublyLinkedList(); // Constructor por default
    void append(T data); // Agrega un elemento al final de la lista
    void appendLeft(T data); // Agrega un elemento al principio de la lista
    void deleteAt(int index); // Elimina un elemento en el índice dado
    int findData(T data); // Regresa el indice donde se encontruentra el valor buscado
    T getData(int index); // Regresa el valor que se encuentra en el índice dado
    T& operator[](int index); // Regresa el valor que se encuentra en el índice dado
    void insert(int index, T data); // Inserta un elemento después del índice dado
    void deleteData(T data); // Elimina el elemento dado (El primero que encuentre)
    void print(); // Imprime la lista de izquierda a derecha
    void printReverse(); // Imprime la lista de derecha a izquierda
    bool isEmpty();
};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

// Agrega un elemento al principio de la lista
template<class T>
void DoublyLinkedList<T>::appendLeft(T data) {
    // Apuntar head a un nuevo elemento donde el apuntador next de este nuevo elemento, apunte al valor de head
    head = new NodeD<T>(data, head, nullptr);
    // Revisamos si la lista estaba vacía
    if (tail == nullptr) {
        // La lista estaba vacía
        // Actualizamos tail con el valor de head
        tail = head;
    } else {
        // La lista no esta vacía
        // El apuntador prev del siguiente elemento lo apuntamos al nuevo elemento    
        head->next->prev = head;
    }
    // incrementar en uno size
    size++;
}

// Agrega un elemento al principio de la lista
template<class T>
void DoublyLinkedList<T>::append(T data) {
    // Apuntar head a un nuevo elemento donde el apuntador next de este nuevo elemento, apunte al valor de head
    tail = new NodeD<T>(data, nullptr, tail);
    // Revisamos si la lista estaba vacía
    if (head == nullptr) {
        // La lista estaba vacía
        // Actualizamos tail con el valor de head
        head = tail;
    } else {
        // La lista no esta vacía
        // El apuntador prev del siguiente elemento lo apuntamos al nuevo elemento    
        tail->prev->next = tail;
    }
    // incrementar en uno size
    size++;
}

// Regresa el valor de una posición dada
template<class T>
T DoublyLinkedList<T>::getData(int index) {
    // Validamos que el índice sea válido
    if (index >= 0 && index < size) {
        // Creamos un apuntador auxliar que sea igual a head
        NodeD<T>* aux;
        // Revisamos por donde voy a buscar el elemento a borrar
        if (index < size/2) {
            // Busco el elemento por el lado izquierdo
            // Apuntador auxliar que sea igual al next de head
            aux = head;
            // Inicializamos una index auxiliar con 0
            int auxIndex = 0; 
            // Recorremos la lista hasta el elemento a borrar
            while (auxIndex < index) {
                // Recorremos aux
                aux = aux->next;
                // incrementamos el indice auxiliar
                auxIndex++;
            }   
        } else {
            // Buscar el elemento por el lado derecho
            // Apuntador auxliar que sea igual al prev de tail 
            aux = tail->prev;
            // Inicializamos una index auxiliar con el último elemento
            int auxIndex = size - 2; 
            // Recorremos la lista hasta el elemento a borrar
            while (auxIndex > index) {
                // Recorremos aux
                aux = aux->prev;
                // decrementamos el indice auxiliar
                auxIndex--;
            }   
        }
        // En aux tenemos el elemento a regresar
        return aux->data;
    // No es valido
    } else {
        // Generar una excepción
        throw out_of_range("El índice es inválido");
    }
}

// Regresa el valor de una posición dada
template<class T>
T& DoublyLinkedList<T>::operator[](int index) {
    // Validamos que el índice sea válido
    if (index >= 0 && index < size) {
        // Creamos un apuntador auxliar que sea igual a head
        NodeD<T>* aux;
        // Revisamos por donde voy a buscar el elemento a borrar
        if (index < size/2) {
            // Busco el elemento por el lado izquierdo
            // Apuntador auxliar que sea igual al next de head
            aux = head;
            // Inicializamos una index auxiliar con 0
            int auxIndex = 0; 
            // Recorremos la lista hasta el elemento a borrar
            while (auxIndex < index) {
                // Recorremos aux
                aux = aux->next;
                // incrementamos el indice auxiliar
                auxIndex++;
            }   
        } else {
            // Buscar el elemento por el lado derecho
            // Apuntador auxliar que sea igual al prev de tail 
            aux = tail->prev;
            // Inicializamos una index auxiliar con el último elemento
            int auxIndex = size - 2; 
            // Recorremos la lista hasta el elemento a borrar
            while (auxIndex > index) {
                // Recorremos aux
                aux = aux->prev;
                // decrementamos el indice auxiliar
                auxIndex--;
            }   
        }
        // En aux tenemos el elemento a regresar
        return aux->data;
    // No es valido
    } else {
        // Generar una excepción
        throw out_of_range("El índice es inválido");
    }
}


// Borra un elemento en una posición dada
template<class T>
void DoublyLinkedList<T>::deleteAt(int index) {
    // Validamos que el índice sea válido
    if (index >= 0 && index < size) {
        // Validar si solo existe un elemento
        if (size == 1) {
            // solo existe un elemento
            // Creamos un apuntador auxiliar que apunte a head
            NodeD<T>* aux = head;
            // Apuntamos head y tail a nullptr
            head = nullptr;
            tail = nullptr;
            // borramos aux
            delete aux;
        } else {
            // Validamos si el valor a borrar es el primero
            if (index == 0) {
                // quiero borrar el primero
                // Creamos un apuntador auxiliar que apunte a head
                NodeD<T>* aux = head;
                // Apuntamos a head al siguiente nodo
                head = head->next;
                // El prev del siguiente elemento debe apuntar a nullptr
                head->prev = nullptr;
                // borramos aux
                delete aux;
            } else {
                // Validamos si el valor a borrar es el último elemento
                if (index == size -1) {
                    // quiero borrar el último
                    // Creamos un apuntador auxiliar que apunte a tail
                    NodeD<T>* aux = tail;
                    // Apuntamos a tail al nodo anterior
                    tail = tail->prev;
                    // El next del nodo anterior debe apuntar a nullptr
                    tail->next = nullptr;
                    // borramos aux
                    delete aux;
                } else {
                    // Vamos a borrar los que estan en medio
                    // Creamos un apuntador auxliar que sea igual a head
                    NodeD<T>* aux;
                    // Revisamos por donde voy a buscar el elemento a borrar
                    if (index < size/2) {
                        // Busco el elemento por el lado izquierdo
                        // Apuntador auxliar que sea igual al next de head
                        aux = head->next;
                        // Inicializamos una index auxiliar con 1
                        int auxIndex = 1; 
                        // Recorredr aux hasta el elemento a borrar
                        while (auxIndex < index) {
                            // Recorremos aux
                            aux = aux->next;
                            // incrementamos el indice auxiliar
                            auxIndex++;
                        }   
                    } else {
                        // Buscar el elemento por el lado derecho
                        // Apuntador auxliar que sea igual al prev de tail 
                        aux = tail->prev;
                        // Inicializamos una index auxiliar con 1
                        int auxIndex = size - 2; 
                        // Recorredr aux hasta el elemento a borrar
                        while (auxIndex > index) {
                            // Recorremos aux
                            aux = aux->prev;
                            // decrementamos el indice auxiliar
                            auxIndex--;
                        }   
                    }
                    // En aux tenemos el elemento a borrar
                    // El siguiente de prev es igual al siguiente de aux
                    aux->prev->next = aux->next;
                    // El prev del siguiente es igual al prev de aux
                    aux->next->prev = aux->prev;
                    // Borramos aux
                    delete aux;
                }
            }
        
        }
        // Decrementamos size
        size--;
    // No es valido
    } else {
        // Generar una excepción
        throw out_of_range("El índice es inválido");
    }
}
// insert(0, 100)
// 0 1 2 3 4 5 -> 0 100 1 2 3 4 5 
// insert(5, 100)
// 0 1 2 3 4 5 -> 0 1 2 3 4 5 100 
// Inserta un elemento después del índice dado
template<class T>
void DoublyLinkedList<T>::insert(int index, T data) {
    // Validamos que el índice sea válido
    if (index >= 0 && index < size) {
        // índice válido
        // Vamos a revisar por donde recorrer la lista hasta encontrar el índice
        if (index < size / 2) {
            // Recorremos por el lado izquierdo
            // Crear un indice auxiliar igual a 0
            int auxIndex = 0;
            // crear un apuntador auxiliar igual a head
            NodeD<T>* aux = head;
            // Recorremos la lista hasta llegar al índice buscado
            while (auxIndex < index) {
                // Recorremos aux
                aux = aux->next;
                // incrementamos el índice auxiliar
                auxIndex++;
            }
            // En aux tenemos el índice buscado
            // Creamos un nodo auxliar nuevo
            NodeD<T>* newNode = new NodeD<T>(data, aux->next, aux);
            // insertamos el valor dado a la derecha de aux
            aux->next = newNode;
            // Actualizamos el apuntador prev del siguiente nodo del nuevo nodo
            newNode->next->prev = newNode;
        } else {
            //Recorremos por lado derecho
            // Validamos si vamos a insertar el elemento al final de la lista
            if (index == size - 1) {
                // Insertamos el elemento al final de la lista
                tail->next = new NodeD<T>(data, nullptr, tail);
                // Cambiamos tail al nuevo nodo
                tail = tail->next;
            } else {
                // Crear un indice auxiliar igual a size - 2
                int auxIndex = size - 2;
                // crear un apuntador auxiliar igual a tail
                NodeD<T>* aux = tail->prev;
                // Recorremos la lista hasta llegar al índice buscado
                while (auxIndex > index) {
                    // Recorremos aux
                    aux = aux->prev;
                    // incrementamos el índice auxiliar
                    auxIndex--;
                }
                // Creamos un nodo auxliar nuevo
                NodeD<T>* newNode = new NodeD<T>(data, aux->next, aux);
                // insertamos el valor dado a la derecha de aux
                aux->next = newNode;
                // Actualizamos el apuntador prev del siguiente nodo del nuevo nodo
                newNode->next->prev = newNode;
            }
        }
        // Incrementamos size
        size++;
    // No es valido
    } else {
        // Generar una excepción
        throw out_of_range("El índice es inválido");
    }
}

// Borramos el primer elemento que sea igual a data
template<class T>
void DoublyLinkedList<T>::deleteData(T data) {
    // Creamos un nodo auxiliar igual a head
    NodeD<T>* aux = head;
    // Validamos si el nodo a borrar es el primero
    if (aux->data == data) {
        // si es el primero
        // Validamos si solo hay un nodo
        if (size == 1) {
            // solo hay un nodo
            // Apuntamos head y tail a nulos
            head = nullptr;
            tail = nullptr;
            // borramos aux
            delete aux;
        } else {
            // Hay más de un elemento
            // Apuntamos a head al siguiente elemento de head
            head = head->next;
            // El prev del siguiente elemento ahora va apuntar a nulos
            head->prev = nullptr;
            // borramos aux
            delete aux;
        }
        // decrementamos size
        size--;
    } else {
        // No vamos a borrar el siguiente elemento
        // Asignamos a aux al siguiente elemento de head
        aux = aux->next;
        // Recorremos la lista mientras aux no sea igual a nulos
        while (aux != nullptr) {
            // Validar si es el elemento a borrar
            if (aux->data == data) {
                // si es el dato a borrar
                // validamos si es el último dato de la lista el que queremos borrar
                if (aux->next == nullptr) {
                    // Si es el último
                    // Asignamos tail al nodo anterior de aux
                    tail = aux->prev;
                    // Asignamos a nulos el apuntador next del nuevo tail
                    tail->next = nullptr;
                    // Borramos aux
                    delete aux;
                } else {
                    // Apuntamos el apuntador next del nodo anterior al apuntador next de aux
                    aux->prev->next = aux->next;
                    // Apuntamos el apuntador prev del nodo que sigue de aux al apuntador prev de aux
                    aux->next->prev = aux->prev;
                    // borramos aux
                    delete aux;
                }
                // decrementamos size
                size--;
                // Nos salimos de la función
                return;
            } else {
                // Recorremos aux
                aux = aux->next;
            }
        }
        // Si llego al final del ciclo quiere decir que no encontré el elemento
        throw out_of_range("El dato no se encuentra");
    }
}

// Buscamos un elemento dado
template<class T>
int DoublyLinkedList<T>::findData(T data) {
    // Creamos un nodo auxiliar igual a head
    NodeD<T>* aux = head;
    // Creamos un índice auxiliar igual a 0
    int auxIndex = 0;
    // Recorremos la lista nodo por nodo para buscar el elemento
    while (aux != nullptr) {
        // Validamos si el el valor de aux es el valor buscado
        if (aux->data == data) {
            // Encontramos el valor buscado
            // Regresamo el índice auxiliar
            return auxIndex;
        } else {
            // recorremos aux
            aux = aux-> next;
            // Incrementamos el índice auxiliar
            auxIndex++;
        }
    }
    // Si nos salimos del ciclo es que no enconrtamos el valor y genermoas una excepción
    throw out_of_range("El dato no se encuentra");
}


template<class T>
void DoublyLinkedList<T>::print() {
    // Recorrer la lista de head hasta que el puntador al siguiente nodo sea igual a nulo
    // imprimir nodo por nodo
    NodeD<T>* aux = head;
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
void DoublyLinkedList<T>::printReverse() {
    // Recorrer la lista de head hasta que el puntador al siguiente nodo sea igual a nulo
    // imprimir nodo por nodo
    NodeD<T>* aux = tail;
    // ciclo mientras el puntador next de aux sea diferente de nulo
    while (aux != nullptr) {
        // Imprimimos el valor del nodo
        cout << aux->data << " ";
        // Recorremos aux al nodo anterior
        aux = aux->prev;
    }
    // Saltamos una línea
    cout << endl;
}


template<class T>
bool DoublyLinkedList<T>::isEmpty() {
    return size == 0;
}


#endif