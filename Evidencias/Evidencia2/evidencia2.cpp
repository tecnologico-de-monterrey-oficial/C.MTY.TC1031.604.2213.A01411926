#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#include "dlinkedlist.h"
#include "Log.h"

template <class T> void swap(dlinkedlist<T> &list, int a, int b) {
  if (a != b) {
    T aux = list[a];
    list[a] = list[b];
    list[b] = aux;
  }
}

void printLogs(vector<Log> logs) {
  for (auto log : logs) {
    cout << log << endl;
  }
}

template <class T> int getPivot(dlinkedlist<T> &list, int start, int end) {
  T pivot = list[end];
  int auxIndex = start - 1;
  for (int index = start; index <= end - 1; index++) {
    if (list[index] < pivot) {
      auxIndex++;
      swap(list, auxIndex, index);
    }
  }
  auxIndex++;
  swap(list, auxIndex, end);
  return auxIndex;
}

template <class T>
void quickSort(dlinkedlist<T> &list, int start, int end) {
  if (start < end) {
    int pivot = getPivot(list, start, end);
    quickSort(list, start, pivot - 1);
    quickSort(list, pivot + 1, end);
  }
}

int getPivotF(dlinkedlist<Log> &list, int start, int end) {
  string pivot = list[end].newdate;
  int auxIndex = start - 1;
  for (int index = start; index <= end - 1; index++) {
    if (list[index].newdate < pivot) {
      auxIndex++;
      swap(list, auxIndex, index);
    }
  }
  auxIndex++;
  swap(list, auxIndex, end);
  return auxIndex;
}

template <class T>
void quickSortF(dlinkedlist<T> &list, int start, int end) {
  if (start < end) {
    int pivot = getPivotF(list, start, end);
    quickSortF(list, start, pivot - 1);
    quickSortF(list, pivot + 1, end);
  }
}

int binarySearch(dlinkedlist<Log> list, string serie) {
  int left = 0;
  int right = list.getSize() - 1;
  while (left <= right) {
    
    int mid = (left + right) / 2;
    if (list[mid].serie == serie)
    {
      if (mid == 0) {
        return mid;
      } else {
        if (list[mid - 1].serie == serie) {
          right = mid - 1;
        } else {
          return mid;
        }
      }
    } else {
      if (serie < list[mid].serie) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
  }
  return -1;
}

int main() {
  ifstream file;

  file.open("canalsuez2.txt");

  string date;
  string time;
  string entry;
  string ubi;

  dlinkedlist<Log> logs;

  while (file >> date >> time >> entry >> ubi) {

    string newdate = "";
    for (int i = 3; i < date.size(); i++) {
      newdate += date[i];
    }

    Log log(date, time, entry, ubi, newdate);
    logs.append(log);
  }

  quickSort(logs, 0, logs.getSize() - 1);

  cout << "Ingresa los tres primeros caracteres de la "
          "UBI"
       << endl;
  cin >> ubi;

  int index = binarySearch(logs, ubi);
  cout << "Posición del primer elemento con ese UBI: " << index << endl;
  dlinkedlist<Log> elementosEncontrados;

  if (index >= 0) {
    while (logs[index].serie == ubi) {
      elementosEncontrados.append(logs[index]);
      if (index == logs.getSize() - 1) {
        ubi = "";
      } else {
        index++;
      }
    }
  } else {
    cout << "No hay elementos con ese UBI" << endl;
  }

  quickSortF(elementosEncontrados, 0, elementosEncontrados.getSize() - 1);
  elementosEncontrados.print();

  return 0;
}