#include <iostream>
#include <vector>
#include <chrono>
using namespace std;


void startTime(chrono::high_resolution_clock::time_point &begin)
{
    
    begin = std::chrono::high_resolution_clock::now();
}


void getTime(chrono::high_resolution_clock::time_point begin, chrono::high_resolution_clock::time_point end)
{
    end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    printf("Tiempo de ejecución: %.8f seconds.\n", elapsed.count() * 1e-9);
}


template <class T>
bool sequentialSearch(vector<T> list, T value, int &comparisons)
{
    
    comparisons = 0;
    for (auto el : list)
    {
        
        comparisons++;
        if (el == value)
        {
            return true;
        }
    }
    return false;
}


template <class T>
bool binarySearch(vector<T> list, T value, int &comparisons)
{
    
    comparisons = 0;
    
    int left = 0;
   
    int right = list.size() - 1;
    
    while (left <= right)
    {
        
        int mid = (left + right) / 2;
        
        comparisons++;
       
        if (list[mid] == value) 
        {
            
            return true;
        }
        else
        {
            
            if (value < list[mid])
            {
                
                right = mid - 1;
            }
            else
            {
               
                left = mid + 1;
            }
        }
    }
   
    return false;
}


template <class T>
void swap(vector<T> &list, int a, int b)
{
    if (a != b)
    {
        int aux = list[a];
        list[a] = list[b];
        list[b] = aux;
    }
}


template <class T>
void swapSort(vector<T> &list, int &comparisons, int &swaps)
{
    
    for (int step = 0; step < list.size() - 1; step++)
    {
       
        for (int index = step + 1; index < list.size(); index++)
        {
           
            comparisons++;
            if (list[step] > list[index])
            {
                
                swaps++;
                swap(list, step, index);
            }
        }
    }
}


template <class T>
void bubbleSort(vector<T> &list, int &comparisons, int &swaps)
{
    
    bool swapped = false;
   
    for (int step = 0; step < list.size() - 1; step++)
    {
      
        swapped = false;
       
        for (int index = 0; index < list.size() - step - 1; index++)
        {
           
            comparisons++;
           
            if (list[index] > list[index + 1])
            {
                
                
                swap(list, index, index + 1);
                
                swaps++;
                
                swapped = true;
            }
        }
        
        if (!swapped)
        {
            
            return;
        }
    }
}

template <class T>
void selectionSort(vector<T> &list, int &comparisons, int &swaps)
{
    
    for (int step = 0; step < list.size() - 1; step++)
    {
        
        int minor = step;
        
        for (int index = step + 1; index < list.size(); index++)
        {
            
            comparisons++;
            if (list[index] < list[minor])
            {
               
                minor = index;
            }
        }
        
        if (minor != step)
        {
            
            swap(list, minor, step);
           
            swaps++;
        }
    }
}

template <class T>
void insertionSort(vector<T> &list, int &comparisons, int &swaps)
{
   
    for (int step = 1; step < list.size(); step++)
    {
        
        int index = step;
        
        comparisons++;
        
        while (index > 0 && list[index] < list[index - 1])
        {
            
            swap(list, index, index - 1);
            
            swaps++;
            
            index--;
            
            comparisons++;
        }
    }
}

template <class T>
void merge(vector<T> &list, int inf, int mid, int sup)
{
    
    vector<T> left;
    
    for (int i = inf; i <= mid; i++)
    {
        
        left.push_back(list[i]);
    }
    
    vector<T> right;
    
    for (int i = mid + 1; i <= sup; i++)
    {
       
        right.push_back(list[i]);
    }

    
    int idxLeft = 0;
    
    int idxRight = 0;
    
    int idx = inf; 
    
    while (idxLeft < left.size() && idxRight < right.size())
    {
        
        if (left[idxLeft] < right[idxRight])
        {
            
            list[idx] = left[idxLeft];
            
            idx++;
            
            idxLeft++;
        }
        else
        {
            
            list[idx] = right[idxRight];
            
            idx++;
            
            idxRight++;
        }
    }
    
    while (idxLeft < left.size())
    {
        
        list[idx] = left[idxLeft];
        
        idx++;
        
        idxLeft++;
    }
    
    while (idxRight < right.size())
    {
        
        list[idx] = right[idxRight];
        
        idx++;
        
        idxRight++;
    }
}

template <class T>
void mergeSort(vector<T> &list, int inf, int sup)
{
    
    if (inf < sup)
    {
        
        int mid = (inf + sup) / 2;
        
        mergeSort(list, inf, mid);
        
        mergeSort(list, mid + 1, sup);

        
        merge(list, inf, mid, sup);
    }
}

template <class T>
int getPivot2(vector<T> &list, int start, int end)
{
    
    T pivot = list[end];
    
    vector<T> left;
    
    vector<T> right;
    
    for (int index = start; index <= end - 1; index++)
    {
        
        if (list[index] < pivot)
        {
            
            left.push_back(list[index]);
            
        }
        else
        {
            
            right.push_back(list[index]);
        }
    }
    
    int index = start;
    
    for (int i = 0; i < left.size(); i++)
    {
        
        list[index] = left[i];
        
        index++;
    }
    
    int pivotIndex = index;
    
    list[pivotIndex] = pivot;
    
    index++;
    
    for (int i = 0; i < right.size(); i++)
    {
        
        list[index] = right[i];
        
        index++;
    }
    
    return pivotIndex;
}

template <class T>
void quickSort2(vector<T> &list, int start, int end)
{
    
    if (start < end)
    {
        
        int pivot = getPivot2(list, start, end);
        
        quickSort2(list, start, pivot - 1);
       
        quickSort2(list, pivot + 1, end);
    }
}

template <class T>
int getPivot(vector<T> &list, int start, int end)
{
    
    T pivot = list[end];
    
    int auxIndex = start - 1;
    
    for (int index = start; index <= end - 1; index++)
    {
        
        if (list[index] < pivot)
        {
            
            auxIndex++;
            
            swap(list, auxIndex, index);
            
        }
    }
    
    auxIndex++;
    
    swap(list, auxIndex, end);
    
    return auxIndex;
}

template <class T>
void quickSort(vector<T> &list, int start, int end)
{
    
    if (start < end)
    {
        
        int pivot = getPivot(list, start, end);
        
        quickSort(list, start, pivot - 1);
        
        quickSort(list, pivot + 1, end);
    }
}

template <class T>
void printList(vector<T> list, int msg)
{
    if (msg == 0)
    {
        cout << "Lista Original" << endl;
    }
    else
    {
        cout << "Lista Ordenada" << endl;
    }
    for (auto el : list)
    {
        cout << el << " ";
    }
    cout << endl;
}


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
    
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;
    vector<int> listInt;
    vector<int> listIntBase;
    vector<char> listChar;
    vector<char> listCharBase;

    cout << "¿De qué tipo de dato quieres la lista (e -> Entero / c -> Caracter)?" << endl;
    char listType;
    cin >> listType;
    cout << "¿De cuántos elementos quieres la lista?" << endl;
    int qty;
    cin >> qty;

    if (listType == 'e')
    {
        createListInt(listIntBase, qty);
        printList(listIntBase, 0);
    }
    if (listType == 'c')
    {
        createListChar(listCharBase, qty);
        printList(listCharBase, 0);
    }
    char opc = 'a';
    while (opc != 's')
    {
        cout << "Selecciona la opción deseada:" << endl;
        cout << "a) Merge Sort" << endl;
        cout << "b) Quick Sort" << endl;
        cout << "s) Salir" << endl;
        cin >> opc;
        if (opc != 'a' && opc != 'b' && opc != 's')
        {
            cout << "Teclea una opción válida" << endl;
        }
        else
        {
            switch (opc)
            {
            case 'a':
                
                cout << "Merge Sort" << endl;
                if (listType == 'e')
                {
                    
                    listInt = listIntBase;
                    printList(listInt, 0);
                    startTime(begin);
                    mergeSort(listInt, 0, listInt.size() - 1);
                    getTime(begin, end);
                    printList(listInt, 1);
                }
                else
                {
                    
                    listChar = listCharBase;
                    printList(listChar, 0);
                    startTime(begin);
                    mergeSort(listChar, 0, listInt.size() - 1);
                    getTime(begin, end);
                    printList(listChar, 1);
                }
                break;
            case 'b':
                
                cout << "Quick Sort" << endl;
                if (listType == 'e')
                {
                    
                    listInt = listIntBase;
                    printList(listInt, 0);
                    startTime(begin);
                    quickSort(listInt, 0, listInt.size() - 1);
                    getTime(begin, end);
                    printList(listInt, 1);
                }
                else
                {
                    
                    listChar = listCharBase;
                    printList(listChar, 0);
                    startTime(begin);
                    quickSort(listChar, 0, listInt.size() - 1);
                    getTime(begin, end);
                    printList(listChar, 1);
                }
                break;
            default:
                break;
            }
            cout << endl << endl;
        }
    }

    return 0;
}