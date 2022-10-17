#ifndef BST_H
#define BST_H

#include "NodeT.h"
#include "Queue.h"

template<class T>
class BST {
private:
    NodeT<T>* root;
    void printTree(NodeT<T>* aux, int level);
    int howManyChilds(NodeT<T>* aux);
    void preOrder(NodeT<T>* root);
    void inOrder(NodeT<T>* root);
    void postOrder(NodeT<T>* root);
    void preOrderConverse(NodeT<T>* root);
    void inOrderConverse(NodeT<T>* root);
    void postOrderConverse(NodeT<T>* root);
    void levelByLevel();
public:
    BST();
    void insert(T data);
    bool find(T data);
    void remove(T data);
    void print();
    bool isEmpty();
    void order(int type);
    int whatLevelIAm(T data); // Regresa el nivel donde se encuentra el dato (root es nivel 1)
};

template<class T>
BST<T>::BST() {
    root = nullptr;
}

template<class T>
int BST<T>::howManyChilds(NodeT<T>* aux) {
    if (aux->left == nullptr && aux->right == nullptr) {
        return 0;
    } else {
        if (aux->left != nullptr && aux->right != nullptr) {
            return 2;
        } else {
            return 1;
        }
    }
}

template<class T>
void BST<T>::insert(T data) {
    // Validamos si el arbol está vacío
    if (isEmpty()) {
        // Si esta vació
        // Apuntamos root a un nuevo nodo con el valor de data
        root = new NodeT<T>(data);
    // else
    } else {
        // Si no está vacío
        // Creamos un nodo auxiliar igual a root
        NodeT<T>* aux = root;
        // Recorremos el arbol hasta encontrar donde colocar el nodo nuevo (while aux != nullptr)
        while (aux != nullptr) {
            // Comparamos si data es menor el valor del nodo auxiliar
            if (data < aux->data) {
                // Si es menor
                // Revisamos si el apuntador left de aux es igual a nulo
                if (aux->left == nullptr) {
                    // si es nulo
                    // Creamos un nuevo nodo en el apuntador del lado izquierdo de aux
                    aux->left = new NodeT<T>(data);
                    // Nos salimos de la función
                    return;
                // else
                } else {
                    // Si no es nulo
                    // Recorremos aux al hijo del lado izquierdo de aux
                    aux = aux->left;
                }
            // else 
            } else {
                // No es menor
                // Revisamos si el apuntador right de aux es igual a nulo
                if (aux->right == nullptr) {
                    // si es nulo
                    // Creamos un nuevo nodo en el apuntador del lado derecho de aux
                    aux->right = new NodeT<T>(data);
                    // Nos salimos de la función
                    return;
                // else
                } else {
                    // Si no es nulo
                    // Recorremos aux al hijo del lado derecho de aux
                    aux = aux->right;
                }
            }
        }
    }
}

template<class T>
bool BST<T>::find(T data) {
    // Creamos un nodo auxiliar igual a root
    NodeT<T>* aux = root;
    // Recorremos el arbol mientras aux sea diferente de nulos
    while (aux != nullptr) {
        // Validamos si el valor buscado es igual al valor de aux
        if (aux->data == data) {
            // Si son iguales
            // YA LO ENCONTRAMOS y regresamos true
            return true;
        // else 
        } else {
            // No son iguales
            // Validamos si el valor buscado es menor que el valor de aux
            if (data < aux->data) {
                // Si es menor
                // Recorremos aux al apuntador del lado izquierdo de aux
                aux = aux->left;
            // else
            } else {
                // No es menor
                // Recorremos aux al apuntador del lado derecho de aux
                aux = aux->right;
            }   
        }
    }
    // cuando nos salimos del ciclo, quiere decir que no lo encontramos
    // NO LO ENCONTRAMOS y regresamos falso
    return false;
}

template<class T>
void BST<T>::remove(T data) {
    // Validar si el arbol no esta vacío
    if (!isEmpty()) {
        // El arbol no está vacío
        // Encontrar el valor a borrar
        // Crear un nodo auxiliar que apunte a root
        NodeT<T>* aux = root;
        // Validar si el nodo a borrar es root
        if (data == root->data) {
            // El nodo a borrar es root
            // Validar cuantos hijos tiene root
            switch (howManyChilds(root)) {
            case 0: // No tiene hijos
                // Hacemos root igual a nulos
                root = nullptr;
                // Borramos aux
                delete aux;    
                break;
            case 1: // tiene 1 hijo
                // Movemos root al hijo existente
                root->right == nullptr ? root = root->left : root = root->right;
                // if (aux->right == nullptr) {
                //     root = aux->left;
                // } else {
                //     root = aux->right;
                // }
                // Borramos aux
                delete aux;   
                break; 
            case 2: // tiene 2 hijos
                // Vamos a buscar el nodo más grande del lado izquierdo
                // Creamos un apuntador auxiliar que apunte al lado izquierdo de aux
                NodeT<T>* auxBigLeft = aux->left;
                // Validamos si el apuntador del lado derecho de auxBigLeft es nulo
                if (auxBigLeft->right == nullptr) {
                    // auxBigLeft es el más grande del lado izquierdo de aux
                    // Hacer el cambio de auxBigLeft con aux
                    aux->data = auxBigLeft->data;
                    // Apuntamos el apuntador del lado izquierdo de aux al lado izquierdo de auxBigLeft
                    aux->left = auxBigLeft->left;
                    // borramos AuxBigLeft
                    delete auxBigLeft;
                } else {
                    // Creamos un apuntado auxliar que va a ser el papa de auxBigLeft
                    NodeT<T>* auxPa = aux;
                    // Recorremos hacia la derecha los hijos de auxBigLeft mientras que el apuntador del lado derecho no sea nulo
                    while (auxBigLeft->right != nullptr) {
                        // Recorremos el papa de auxBigLeft
                        auxPa = auxBigLeft;
                        // Recorremos a la derecha auxBigLeft
                        auxBigLeft = auxBigLeft->right;
                    }
                    // auxBigLeft va a ser el más grande del lado izquiedo
                    // Hacer el cambio de auxBigLeft con aux
                    aux->data = auxBigLeft->data;
                    // Apuntamos el apuntador del lado derecho de auxPa al lado izquierdo de auxBigLeft
                    auxPa->right = auxBigLeft->left;
                    // borramos AuxBigLeft
                    delete auxBigLeft;
                }
                break;
            }
        } else {
            // El nodo que voy a remover no es root
            // Creamos un nodo que va apuntar al papá del nodo auxiliar
            NodeT<T>* auxPa = root;
            // Apuntamos aux al lado correspondiente de root
            data < root->data ? aux = root->left : aux = root->right;
            // Recorrer el arbol hasta encontrar el valor a remover
            while (aux != nullptr) {
                // Validamos si el valor buscado es igual al valor de aux
                if (aux->data == data) {
                    // Si son iguales
                    // Vamos a removerlos
                    switch (howManyChilds(aux)) {
                    case 0: // No tiene hijos
                        // Le asignamos nulos al lado correpondiente del papá de aux
                        data < auxPa->data ? auxPa->left = nullptr : auxPa->right = nullptr; 
                        // Removemos aux
                        delete aux;
                        break;               
                    case 1: // Tiene 1 hijo
                        // Asignamos el lado correspondiente del papá de aux al hijo de aux
                        if (data < auxPa->data) {
                            aux->left != nullptr ? auxPa->left = aux->left : auxPa->left = aux->right;
                        } else {
                            aux->left != nullptr ? auxPa->right = aux->left : auxPa->right = aux->right;
                        }
                        // Removemos aux
                        delete aux;
                        break; 
                    case 2: // Tiene 2 hijos
                        // Vamos a buscar el nodo más grande del lado izquierdo
                        // Creamos un apuntador auxiliar que apunte al lado izquierdo de aux
                        NodeT<T>* auxBigLeft = aux->left;
                        // Validamos si el apuntador del lado    derecho de auxBigLeft es nulo
                        if (auxBigLeft->right == nullptr) {
                            // auxBigLeft es el más grande del lado izquierdo de aux
                            // Hacer el cambio de auxBigLeft con aux
                            aux->data = auxBigLeft->data;
                            // Apuntamos el apuntador del lado izquierdo de aux al lado izquierdo de auxBigLeft
                            aux->left = auxBigLeft->left;
                            // borramos AuxBigLeft
                            delete auxBigLeft;
                        } else {
                            // Creamos un apuntado auxliar que va a ser el papa de auxBigLeft
                            NodeT<T>* auxPa = aux;
                            // Recorremos hacia la derecha los hijos de auxBigLeft mientras que el apuntador del lado derecho no sea nulo
                            while (auxBigLeft->right != nullptr) {
                                // Recorremos el papa de auxBigLeft
                                auxPa = auxBigLeft;
                                // Recorremos a la derecha auxBigLeft
                                auxBigLeft = auxBigLeft->right;
                            }
                            // auxBigLeft va a ser el más grande del lado izquiedo
                            // Hacer el cambio de auxBigLeft con aux
                            aux->data = auxBigLeft->data;
                            // Apuntamos el apuntador del lado derecho de auxPa al lado izquierdo de auxBigLeft
                            auxPa->right = auxBigLeft->left;
                            // borramos AuxBigLeft
                            delete auxBigLeft;
                        }
                        break; 
                    }
                    // nos salimos de la función
                    return;
                // else 
                } else {
                    // No son iguales
                    // Recorremos el nodo auxiliar que apunta al papa de aux
                    auxPa = aux;
                    // Validamos si el valor buscado es menor que el valor de aux
                    data < aux->data ? aux = aux->left : aux = aux->right;
                } 
            }
            // Quiere decir que no lo encontré 
            throw invalid_argument("El valor a borra no se encuentra en el BST");
        }
    } else {
        throw invalid_argument("El valor a borra no se encuentra en el BST");
    }
}

template<class T>
void BST<T>::printTree(NodeT<T>* aux, int level) {
    if (aux != NULL) {
        printTree(aux->right,level+1);
        for (int i=0;i<level;i++) {
            cout << "  ";
        }
        cout << aux->data << endl;
        printTree(aux->left,level+1);
    }
}

template<class T>
void BST<T>::preOrder(NodeT<T>* aux) {
    // Condición de control para salir de la recursividad
    if (aux != nullptr) {
        // visita el nodo raíz del arbol
        cout << aux->data << " ";
        // preOrder del arbol izquierdo
        preOrder(aux->left);   
        // preOrder del arbol derecho
        preOrder(aux->right);
    }
}

template<class T>
void BST<T>::inOrder(NodeT<T>* aux) {
    // Condición de control para salir de la recursividad
    if (aux != nullptr) {
        // inOrder del arbol izquierdo
        inOrder(aux->left);   
        // visita el nodo raíz del arbol
        cout << aux->data << " ";
        // inOrder del arbol derecho
        inOrder(aux->right);
    }
}


template<class T>
void BST<T>::postOrder(NodeT<T>* aux) {
    // Condición de control para salir de la recursividad
    if (aux != nullptr) {
        // inOrder del arbol izquierdo
        postOrder(aux->left);   
        // inOrder del arbol derecho
        postOrder(aux->right);
        // visita el nodo raíz del arbol
        cout << aux->data << " ";
    }
}
template<class T>
void BST<T>::preOrderConverse(NodeT<T>* aux) {
    // Condición de control para salir de la recursividad
    if (aux != nullptr) {
        // visita el nodo raíz del arbol
        cout << aux->data << " ";
        // preOrder del arbol derecho
        preOrderConverse(aux->right);
        // preOrder del arbol izquierdo
        preOrderConverse(aux->left);   
    }
}

template<class T>
void BST<T>::inOrderConverse(NodeT<T>* aux) {
    // Condición de control para salir de la recursividad
    if (aux != nullptr) {
        // inOrder del arbol derecho
        inOrderConverse(aux->right);
        // visita el nodo raíz del arbol
        cout << aux->data << " ";
        // inOrder del arbol izquierdo
        inOrderConverse(aux->left);   
    }
}


template<class T>
void BST<T>::postOrderConverse(NodeT<T>* aux) {
    // Condición de control para salir de la recursividad
    if (aux != nullptr) {
        // inOrder del arbol derecho
        postOrderConverse(aux->right);
        // inOrder del arbol izquierdo
        postOrderConverse(aux->left);   
        // visita el nodo raíz del arbol
        cout << aux->data << " ";
    }
}

template<class T>
void BST<T>::levelByLevel() {
    // Creamos una fila vacía de tipo NodeT<T>*
    Queue< NodeT<T>* > queue;
    // Agregamos a la fila el nodo raíz
    queue.push(root);
    // Iteramos hasta que la fila este vacía
    while (!queue.isEmpty()) {
        // Creamos un nodo auxliar para almacenar el valor del nodo a sacar de la fila
        NodeT<T>* aux = queue.pop();
        // Imprimimos el primer nodo de la fila
        cout << aux->data << " ";
        // Agregamos los hijos del elemento que acabamos de sacar
        if (aux->left != nullptr) {
            queue.push(aux->left);
        }
        if (aux->right != nullptr) {
            queue.push(aux->right);
        }
    }
}

template<class T>
void BST<T>::order(int type) {
    switch (type)
    {
    case 1: // 1 -> PreOrder
        preOrder(root);
        break;
    case 2: // 2 -> InOrder
        inOrder(root);
        break;
    case 3: // 3 -> PostOrder
        postOrder(root);
        break;
    case 4: // 4 -> PreOrder Converse
        preOrderConverse(root);
        break;
    case 5: // 5 -> InOrder Converse
        inOrderConverse(root);
        break;
    case 6: // 6 -> PostOrder Converse
        postOrderConverse(root);
        break;
    case 7: // 7 -> Level by level
        levelByLevel();
        break;
    
    default:
        break;
    }
}
template<class T>
void BST<T>::print() {
    if (!isEmpty()) {
        int level = 0;
        cout << endl;
        printTree(root, level);
        cout << endl;
    } else {
        cout << endl << "The BST is empty" << endl << endl;
    }
} 

template<class T>
bool BST<T>::isEmpty() {
    return root == nullptr;
}
#endif