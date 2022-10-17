#include <iostream>
#include <vector>
#include <chrono>
// #include <ctime>
// #include <stdio.h>
// #include <sys/time.h>
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

int main()
{
    // Variables para calcular el tiempo de ejecución
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;
    int comparisons;
    vector<int> list = {5,7,10,20,35,42,63,70,93,100,120,130,140,150,155,167,168,169,200};

    // Solicita al usuario un número entero entre 1 y 100
    // Despliega un mensaje que indique si el número tecleado por el usuario existe en la lista
    // Despliega "Si existe" en caso de que si exista
    // Despliega "No existe" en caso de que no exist
    // Utiliza el argoritmo de búsqueda secuencial
    int n = 0;
    while (n<1 || n>200) {
        cout << "Teclea un número entero entre 1 y 200" << endl;
        cin >> n;
        if (n<1 || n>200) {
            cout << "Error: El número debe de estar entre 1 y 200" << endl;
        }
    }
    getTime(begin, end);
    cout << "Búsqueda Secuencial" << endl;
    // startTime(begin);
    startTime(begin);
    if (sequentialSearch(list, n, comparisons)) {
        cout << "Si existe" << endl;
    } else {
        cout << "No existe" << endl;
    }
    getTime(begin, end);
    cout << "Comparaciones: " << comparisons << endl << endl;
    cout << "Búsqueda Binaria" << endl;
    // startClock(start);
    startTime(begin);
    
    if (binarySearch(list, n, comparisons)) {
        cout << "Si existe" << endl;
    } else {
        cout << "No existe" << endl;
    }
    getTime(begin, end);
    cout << "Comparaciones: " << comparisons << endl;
    

    
    
    return 0;
}
