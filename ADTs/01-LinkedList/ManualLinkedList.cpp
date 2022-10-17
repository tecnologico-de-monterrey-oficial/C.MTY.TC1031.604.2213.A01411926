#include <iostream>
using namespace std;

#include "Node.h"

int main()
{
    // Crear un apuntador a un espacio en memoria de tipo nodo
    Node<int>* head;
    head = new Node<int>(5);
    
    // El primer nodo
    cout << "Valor de head: " << head << endl;
    cout << "Valor de head->data: " << head->data << endl;
    cout << "Valor de head->next: " << head->next << endl;
    
    head->next = new Node<int>(10);
    // El primer nodo
    cout << "Primer nodo" << endl;
    cout << "Valor de head: " << head << endl;
    cout << "Valor de head->data: " << head->data << endl;
    cout << "Valor de head->next: " << head->next << endl;
    // El segundo nodo (primera opcion)
    cout << "Segundo nodo (primera opción)" << endl;
    cout << "Valor de head->next->data: " << head->next->data << endl;
    cout << "Valor de head->next->next: " << head->next->next << endl;
    // El segundo nodo (seguinda opcion)
    Node<int>* aux = head->next;
    cout << "Segundo nodo (segunda opción)" << endl;
    cout << "Valor de aux->data: " << aux->data << endl;
    cout << "Valor de aux->next: " << aux->next << endl;

    return 0;
}
