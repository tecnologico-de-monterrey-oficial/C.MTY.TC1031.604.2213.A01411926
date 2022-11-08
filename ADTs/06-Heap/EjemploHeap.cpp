#ifndef Heap_h
#define Heap_h

template <class T>
class Heap
{
private:
    vector<T> heap;
    void swap(int a, int b);
    void downSort(int father);
public:
    Heap();
    Heap(vector<T> list);
    Heap(initializer_list<T> list);
    T getTop();
    void pop();
    void push(T data);
    void print();
    bool isEmpty();
};

template <class T>
Heap<T>::Heap()
{
}

template <class T>
void Heap<T>::swap(int a, int b)
{
    T aux = heap[a];
    heap[a] = heap[b];
    heap[b] = aux;
}

template <class T>
void Heap<T>::downSort(int father)
{
    // Declaramos una variblae auxziliar para determinar el mayor de los hijos
    int bigSon;
    // ciclo para el reacomodo de cada padre (mientras el hijo menor sea menor al tamaño de la lista)
    while ((father * 2 + 1) < heap.size())
    {
        // Obtenemos cual de los hijos es el de mayor prioridad
        // creamos una variable con el valor del índice del primer hijo
        int son1 = father * 2 + 1;
        // Validamos si el auxFather tiene 2 hijos
        if ((father * 2 + 2) < heap.size())
        {
            // si tenie 2 hijos
            int son2 = father * 2 + 2;
            // Comparamos cual de los 2 hijos es mayor
            (heap[son1] > heap[son2]) ? bigSon = son1 : bigSon = son2;
        }
        else
        {
            // solo tiene 1 hijo
            bigSon = son1;
        }
        // comparamos el nodo padre con el hijo de mayor prioridad
        if (heap[father] > heap[bigSon])
        {
            // el nodo padre es de mayor prioridad que el mayor de los hijos
            // Se acaba el proceso de reacomodo para ese padre
            father = heap.size(); // para forzar que se salga del ciclo
        }
        // else
        else
        {
            // el nodo padre es de menor priridad que el mayo de los hijos
            // Intercambiamos el padre con el hijo de mayor prioridad
            swap(father, bigSon);
            // Volvemos al ciclo a hacer lo mismo con los hijos del hijo de mayor prioridad
            // Actualizamos auxFather igual a bigSon
            father = bigSon;
        }
    }
}

template<class T>
void Heap<T>::pop() {
    // Intercambiamos el primer elemento de la lista con el último
    swap(0,heap.size()-1);
    // Borramos el último elemento de la lista
    heap.pop_back();
    // downSort con el elemento raíz del heap
    downSort(0);
}

template<class T>
T Heap<T>::getTop() {
    if (!isEmpty()) {
        return heap[0];
    } else {
        throw out_of_range("El heap esta vacío");
    }
}

template<class T>
void Heap<T>::push(T data) {
    // Agregamos el elemento al final del heap
    heap.push_back(data);
    // UpSort
    // Creamos un índice auxiliar que sea igual hijo
    int son = heap.size()-1;
    // Creamos una variable auxiliar para validar si nos tenemos que salir del ciclo
    // bool validate = true;
    // Recorrer el arbol desde el elemento agregado hasta el primer elemento del arbol 
    // o que encontremo que un hijo no es de mayor prioridad que el padre
    // while (son != 0 && validate == true) {
    while (son != 0) {
        // Encontramos el padre 
        int father = (son - 1) / 2;
        // Validamos si el hijo es de mayor prioridad que el padre
        if (heap[son] > heap[father]) {
            // si es de mayor prioridad
            // Los intercambiamos
            swap(son, father);
            // el nuevo hijo va a ser el padre
            son = father;
        // else
        } else {
            // no es de mayor prioridad
            // no salimos del ciclo
            // validate = false;
            son = 0;
        }
    }

}

template<class T>
bool Heap<T>::isEmpty() {
    return heap.size() == 0;
}

template <class T>
Heap<T>::Heap(vector<T> list)
{
    // copiar la lista actualizada al heap
    heap = list;
    // Encontrar cual es el primer nodo padre (((list.size()-1)-1)/2)
    int father = (list.size() - 2) / 2;
    // Recorremos todos los padres desde el primero de los padres hasta el nodo raíz
    // Recorrer desde el primer nodo padre hasta el nodo raíz
    while (father >= 0)
    {
        // Hacemos el downSort del father
        downSort(father);
        // Decrementamos el valor de father
        father--;
    }
}

template <class T>
Heap<T>::Heap(initializer_list<T> list)
{
    // copiar la lista actualizada al heap
    heap = list;
    // Encontrar cual es el primer nodo padre (((list.size()-1)-1)/2)
    int father = (list.size() - 2) / 2;
    // Recorremos todos los padres desde el primero de los padres hasta el nodo raíz
    // Recorrer desde el primer nodo padre hasta el nodo raíz
    while (father >= 0)
    {
        // Hacemos el downSort del father
        downSort(father);
        // Decrementamos el valor de father
        father--;
    }

}

template <class T>
void Heap<T>::print()
{
    for (auto el : heap)
    {
        cout << el << " ";
    }
    cout << endl;
}

#endif