#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

// Obtiene el tiempo inicial para calcular el tiempo transcurrido por un algoritmo
void startTime(chrono::high_resolution_clock::time_point &begin)
{
  // start time
  begin = std::chrono::high_resolution_clock::now();
  
}

// Imprime el tiempo transcurrido desde el valor de start hasta el momento que se ejecuta la función
void getTime(chrono::high_resolution_clock::time_point begin, chrono::high_resolution_clock::time_point end) 
{
    end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    printf("Tiempo de ejecución: %.8f seconds.\n", elapsed.count() * 1e-9);
}

// Búsqueda Secuencial (O(n))
template <class T>
bool sequentialSearch(vector<T> list, T value, int &comparisons) {
    // Algoritmo de búsqueda secuencial
    // Iteramos en todos los elementos de la list con un for de 0 al tamaño de la lisrta
    // for (int i=0; i<list.size(); i++) {
    //     // Validamos si el valor de n es igual al elemento i de la lista
    //     if (list[i] == value) {
    //         return true;
    //     }
    // }
    // incializamos el número de comparaciones
    comparisons = 0;
    for (auto el : list) {
        // incrementamos el número de comparaciones
        comparisons++;
        if (el == value) {
            return true;
        }
    }
    return false;
}

// Búsqueda Binaria (O log2(n))
template <class T>
bool binarySearch(vector<T> list, T value, int &comparisons) {
    // incializamos el número de comparaciones
    comparisons = 0;
    // Definir el límite inferior
    int left = 0;
    // Definir el límite superior
    int right = list.size() - 1;
    // Iterar en la lista mientras el límite inferior <= limite superior
    while (left <= right) {
        // Calculo la posición del índice de en medio (limite inferior + limite superior) / 2
        int mid = (left + right) / 2;
        // incrementamos el número de comparaciones
        comparisons++;
        // Reviso si el valor búscado es igual el elemento de la posición del índice de en medio
        if (list[mid] == value) {
            // Si es igual
            // Regreso verdadero
            return true;
        } else {
            // Si no es igual
            // Reviso si valor buscado es menor al elemento de la posición del índice de en medio
            if (value < list[mid]) {
                // Si es menor
                // actualizo el límite superior con el valor del índice de en medio - 1
                right = mid -1;
            } else {
                // Si es mayor
                // actualizo el límite inferior con el valor del índice de en medio + 1
                left = mid + 1;
            }
        }
    }
    // Cuando me salga del ciclo
    // Regreso falso
    return false;
}

// Intercambio de dos elementos de la lista
template <class T>
void swap(vector<T> &list, int a, int b) {
    if (a != b) {
        int aux = list[a];
        list[a] = list[b];
        list[b] = aux;
    }
}

// Ordenamiento por Intercambio
template <class T>
void swapSort(vector<T> &list, int &comparisons, int &swaps) {
    // Recorremos la lista desde el primer el elemento hasta el penúltimo (step)
    for (int step=0; step < list.size()-1; step++) {
        // Recorremos la lista desde el valor de step + 1 hasta el último elemento (index)
        for (int index=step+1; index<list.size(); index++) {
            // Comparamos si valor del índice step es > al valor del índice index
            // Incrementar el número de comparaciones
            comparisons++;
            if (list[step] > list[index]) {
                // si es mayor
                // los intercambiamos
                // incrementar el número de intercambios
                swaps++;
                swap(list, step, index);
            }
        }
    }
}

// Ordenamiento de burbuja
template <class T>
void bubbleSort(vector<T> &list, int &comparisons, int &swaps) {
    // Definimos la variable swapped para revisar si hubo intercambios
    bool swapped = false;
    // Recorremos la lista desde el primer elemento hasta el penúltimo elemento (step)
    for (int step=0; step<list.size()-1; step++) {
        // Inicializamos una variable swapped en falso
        swapped = false;
        // Recorremos la lista desde primer elemento hasta el último elemento menos el valor del step menos 1 (index)
        for (int index=0; index<list.size()-step-1; index++) {
            // incrementamos el número de comparaciones
            comparisons++;
            // Comparamos el elemento del index con el siguiente elemento
            if (list[index]>list[index+1]) {
                // si es mayor el elemento anterior al index que el elemento del index
                // hacemos el intercambio
                swap(list, index, index+1);
                // incrementamos el número de intercambios
                swaps++;
                // cambiamos el valor de swapped a verdadero
                swapped = true;
            }
        }
        // Validamos si la variable swapped es falso
        if (!swapped) {
            // si es falso nos salimos de la función
            return;
        }
    }
}

template <class T>
void selectionSort(vector<T> &list, int &comparisons, int &swaps) {
    // Recorremos la lista desde el primer elemento hasta el penúltimo (step)
    for (int step=0; step<list.size()-1; step++) {
        // creamos una variable con el índice del elemento más chico
        int minor = step;
        // Recorremos la lista desde el valor del step + 1 hasta el último elemento
        for (int index=step+1; index<list.size(); index++) {
            // validamos que el valor de la lista en index es menor al valor de la lista en minor
            // incrementamos el valor de las comparaciones
            comparisons++;
            if (list[index]<list[minor]) {
                // si es menor
                // actualizamos el valor de minor
                minor = index; 
            }
        }
        // Revisamos si el valor del step es diferente al valor de indice del número más chico
        if (minor != step) {
            // si es diferente
            // lo intercambiamos
            swap(list, minor, step);
            // incrementamos los intercambios
            swaps++;
        }
    }
}

template <class T>
void insertionSort(vector<T> &list, int &comparisons, int &swaps) {
    // Recorremos la lista desde el primer elemento hasta el penúltimo (step)
    for (int step=1; step<list.size(); step++) {
        // Recorremos hacia atrás la lista desde el valor de step hasta el inicio de la lista o 
        // hasta que encontremos el lugar donde debe de ir ese valor
        // creamos la variable index con valor igual a step
        int index = step;
        // creamos una variable auxiliar con el valor de la posición de step
        // T aux = list[index];
        // Incrementamos las compraciones
        comparisons++;
        // Recorremos hacia atras mientras index > 0 && aux < list[index-1]
        while (index > 0 && list[index] < list[index-1]) {
            // Intercambiamos los valores
            swap(list, index, index-1);
            // incrementamos los intercambios
            swaps++;
            // decrementamos el valor de index
            index--; 
            // Incrementamos las compraciones
            comparisons++;
        }
    }
}

template<class T>
void merge(vector<T> &list, int inf, int mid, int sup) {
    // crear la lista temporal del lado izquierdo
    // crear un vector vacío (left)
    vector<T> left;
    // recorremos la lista desde inf hasta mid
    for (int i=inf; i<=mid; i++) {
        // agregamos el elemento a la lista izquierda (left)
        left.push_back(list[i]);
    }
    // crear la lista temporal del lado derecho
    // crear un vector vacío (right)
    vector<T> right;
    // recorremos la lista desde mid+1 hast sup
    for (int i=mid+1; i<=sup; i++) {
        // agregamos el elemento a la lista derecha (right)
        right.push_back(list[i]);
    }

    // Merge
    // creamos el índice de la izquierda igual a 0 (idxLeft)
    int idxLeft = 0;
    // creamos el índice de la derecha igual a 0 (idxRight)
    int idxRight = 0;
    // creamos el indice de la lista igual a índice inf (idx)
    int idx = inf; // Ojo que sea igual a inf
    // Hacemos un ciclo mientras el índice de la izquierda < al tamaño de la lista izquierda y (&&)
    // el índice de la derecha < al tamaño de la lista derecha
    while (idxLeft < left.size() && idxRight < right.size()) {
        // Comparamos si el valor que se encuentra en el índice de la izquierda (idxLeft) es menor 
        // al valor que se encuentra en el índice de la derecha (idxRight)
        if (left[idxLeft] < right[idxRight]) {
        // Si es menor
            // asignamos el valor de la lista izquierda que se encuentra en la posición del índice izquierdo (idxLeft) 
            // en la posición de índice de la lista (idx)
            list[idx] = left[idxLeft];
            // incrementar el índice de la lista (idx)
            idx++;
            // incrementar el índice de la lista izquierda (idxLeft)
            idxLeft++;
        } else {
        // No es menor
            // asignamos el valor de la lista derecha que se encuentra en la posición del índice derecho (idxRight) 
            // en la posición de índice de la lista (idx)
            list[idx] = right[idxRight];
            // incrementar el índice de la lista (idx)
            idx++;
            // incrementar el índice de la lista derecha (idxRight)
            idxRight++;
        }
    }
    // Hacemos un ciclo mientras el índice de la izquierda < al tamaño de la lista izquierda
    while (idxLeft < left.size()) {
        // asignamos el valor de la lista izquierda que se encuentra en la posición del índice izquierdo (idxLeft) 
        // en la posición de índice de la lista (idx)
        list[idx] = left[idxLeft];
        // incrementar el índice de la lista (idx)
        idx++;
        // incrementar el índice de la lista izquierda (idxLeft)
        idxLeft++;
    }
    // Hacemos un ciclo mientras el índice de la derecha < al tamaño de la lista derecha
    while (idxRight < right.size()) {
        // asignamos el valor de la lista derecha que se encuentra en la posición del índice derecho (idxRight) 
        // en la posición de índice de la lista (idx)
        list[idx] = right[idxRight];
        // incrementar el índice de la lista (idx)
        idx++;
        // incrementar el índice de la lista derecha (idxRight)
        idxRight++;
    }
}

template <class T>
void mergeSort(vector<T> &list, int inf, int sup) {
    // Condición de control para validar que ya no puedo separar las sublistas
    // Si el indice inferior = indice superior
    if (inf < sup) {
    // Cuando el indice inferior sea menor al indice superior
        // Calcular el índice del medio ((inf+sup)/2)
        int mid = (inf + sup) / 2;
        // Volver a llamar a la función con la sublista del lado izquierdo (list,inf,mid)
        mergeSort(list,inf,mid);
        // Volver a llamar a la función con la sublista del lado derecho (list,mid+1,sup)
        mergeSort(list,mid+1,sup);

        // Ocurre la magia - Juntar la sublista izquierda con la sublista derecha que ya estan ordenadas
        merge(list, inf, mid, sup);
    }
}

template<class T>
int getPivot2(vector<T> &list, int start, int end) {
    // Opción 1 (Creamos dos listas temporales)
    // Identificamos el pivote (El último elemento de la lista)
    T pivot = list[end];
    // crear lista del lado izquierdo (left)
    vector<T> left;
    // crear lista del lado derecho (right)
    vector<T> right;
    // iteramos la lista desde start hasta end-1 (index)
    for (int index=start; index<=end-1; index++) {
        // Comparamos el valor del el elemento index de la lista (list[index]) con el valor del pivote
        if (list[index] < pivot) {
            // Si es menor 
            // Agregamos el valor del elemento index de la lista a la lista izquierda
            left.push_back(list[index]);
        // else
        } else {
            // Si mayor o igual
            // Agregamos el valor del elemento index de la lista a la lista derecha
            right.push_back(list[index]);
        }
    }
    // definimos un índice de la lista original que va a ser igual a start (index)
    int index = start;
    // recorremos toda la lista del lado izquierdo (i)
    // for (auto el : left) {
    for (int i=0; i<left.size(); i++) {
        // Asignamos el elemento de la lista izquierda en la posición i (left[i]) a la posición index de la lista (list[index])
        // list[index] = el;
        list[index] = left[i];
        // incrementamos el valor de índice
        index++;
    }
    // creamos un valor para el índice del pivote que sería igual a index (pivotIndex)
    int pivotIndex = index;
    // Asignamos el valor del pivote a list
    list[pivotIndex] = pivot;
    // incrementamos el valor del índice
    index++;
    // recorremos toda la lista del lado derecho (i)
    // for (auto el : right) {
    for (int i=0; i<right.size(); i++) {
        // Asignamos el elemento de la lista derecha en la posición i (right[i]) a la posición index de la lista (list[index])
        // list[index] = el;
        list[index] = right[i];
        // incrementamos el valor de índice
        index++;
    }
    // regresamos el índice del pivote (indexPivot)
    return pivotIndex;
}

template <class T>
void quickSort2(vector<T> &list, int start, int end) {
    // Condición de control mientras start < end
    if (start < end) {
        // Encontrar el pivote y hacer las dos listas
        int pivot = getPivot2(list, start, end);
        // Ordenamos la lista del lado izquierdo
        quickSort2(list, start, pivot - 1);
        // Ordenamos la lista del lado derecho
        quickSort2(list, pivot + 1, end);
    }
}

template<class T>
int getPivot(vector<T> &list, int start, int end) {
    // Opción 2 (Sin listas temporales)
    // Identificamos el pivote (El último elemento de la lista)
    T pivot = list[end];
    // Creamos un indice auxiliar igual a start -1 (auxIndex)
    int auxIndex = start - 1;
    // Recorremos toda la lista desde start hasta end - 1 (index)
    for (int index=start; index<=end-1; index++) {
        // Validamos si el valor de la lista en index es menor al pivot
        if (list[index]<pivot) {
            // si es menor
            // incrementamos el valor de auxIndex
            auxIndex++;
            // intercambiamos en la lista auxIndex con index
            swap(list, auxIndex, index);
        // else
            // no vamos a hacer nada
        }
    }
    // incrementamos el valor de auxIndex
    auxIndex++;
    // intercambiamos auxIndex con el pivot(end)
    swap(list, auxIndex, end);
    // regresar el valor de auxIndex
    return auxIndex;
}

template <class T>
void quickSort(vector<T> &list, int start, int end) {
    // Condición de control mientras start < end
    if (start < end) {
        // Encontrar el pivote y hacer las dos listas
        int pivot = getPivot(list, start, end);
        // Ordenamos la lista del lado izquierdo
        quickSort(list, start, pivot - 1);
        // Ordenamos la lista del lado derecho
        quickSort(list, pivot + 1, end);
    }
}

template <class T>
void printList(vector<T> list, int msg) {
    if (msg == 0) {
        cout << "Lista Original" << endl;
    } else {
        cout << "Lista Ordenada" << endl;
    }
    for (auto el : list) {
        cout << el << " ";
    }
    cout << endl;
}

// Crea una lista aleatoria de enteros
void createListInt(vector<int> &list, int quantity)
{
  for (int i = 0; i < quantity; i++)
  {
    int num = rand() % 1000 + 1;
    list.push_back(num);
  }
}

void createListChar(vector<char> &list, int quantity)
{
  for (int i = 0; i < quantity; i++)
  {
    int num = 91;
    while (num >= 91 && num <= 96)
    {
      num = rand() % 58 + 65;
    }
    list.push_back(char(num));
  }
}

int main()
{
    srand(time(0));
    // Variables para calcular el tiempo de ejecución
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;
    
    vector<char> list;
    vector<char> listBase;
    int swaps;
    int comparisons;

    createListChar(listBase, 20000);
    
    // Swap Sort
    cout << "Swap Sort" << endl;
    list = listBase;
    swaps = 0;
    comparisons = 0;
    // printList(list,0);
    startTime(begin);
    swapSort(list, comparisons, swaps);
    getTime(begin, end);
    cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl;
    // printList(list,1);

    // Bluble Sort
    cout << "Bubble Sort" << endl;
    list = listBase;
    swaps = 0;
    comparisons = 0;
    // printList(list,0);
    startTime(begin);
    bubbleSort(list, comparisons, swaps);
    getTime(begin, end);
    cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl;
    // printList(list,1);
    
    // Selection Sort
    cout << "Selection Sort" << endl;
    list = listBase;
    swaps = 0;
    comparisons = 0;
    // printList(list,0);
    startTime(begin);
    selectionSort(list, comparisons, swaps);
    getTime(begin, end);
    cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl;
    // printList(list,1);
    
    // Insertion Sort
    cout << "Insertion Sort" << endl;
    list = listBase;
    swaps = 0;
    comparisons = 0;
    // printList(list,0);
    startTime(begin);
    insertionSort(list, comparisons, swaps);
    getTime(begin, end);
    cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl;
    // printList(list,1);
    
    // Merge Sort
    cout << "Merge Sort" << endl;
    list = listBase;
    swaps = 0;
    comparisons = 0;
    // printList(list,0);
    startTime(begin);
    mergeSort(list, 0, list.size()-1);
    getTime(begin, end);
    // printList(list,1);

    // Quick Sort
    cout << "Quick Sort" << endl;
    list = listBase;
    swaps = 0;
    comparisons = 0;
    // printList(list,0);
    startTime(begin);
    quickSort2(list, 0, list.size()-1);
    getTime(begin, end);
    // printList(list,1);

    // Quick Sort
    cout << "Quick Sort" << endl;
    list = listBase;
    swaps = 0;
    comparisons = 0;
    // printList(list,0);
    startTime(begin);
    quickSort(list, 0, list.size()-1);
    getTime(begin, end);
    // printList(list,1);

    return 0;
}
