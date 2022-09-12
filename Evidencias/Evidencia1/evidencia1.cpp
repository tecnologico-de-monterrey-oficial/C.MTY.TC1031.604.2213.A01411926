#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#include "Log.h"

template <class T> void swap(vector<T> &list, int a, int b) {
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

template <class T> int getPivot(vector<T> &list, int start, int end) {

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

template <class T> void quickSort(vector<T> &list, int start, int end) {

  if (start < end) {

    int pivot = getPivot(list, start, end);

    quickSort(list, start, pivot - 1);

    quickSort(list, pivot + 1, end);
  }
}

int getPivotDate(vector<Log> &list, int start, int end) {

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

void quickSortDate(vector<Log> &list, int start, int end) {

  if (start < end) {

    int pivot = getPivotDate(list, start, end);

    quickSortDate(list, start, pivot - 1);

    quickSortDate(list, pivot + 1, end);
  }
}

vector<Log> binarySearch(vector<Log> list, string n) {

  vector<Log> resultado;

  int limsup = list.size() - 1;
  int liminf = 0;

  while (liminf <= limsup) {

    int mid = (liminf + (limsup - liminf) / 2);
    string item;
    for (int i = 0; i <= 2; i++) {
      item = item + list[mid].ubi[i];
    }

    if (n == item) {
      resultado.push_back(list[mid]);
      list[mid].ubi = "";
      liminf = liminf - 4;
      limsup = limsup + 4;
    }

    else if (n < item) {
      limsup = mid - 1;
    }

    else if (n > item) {
      liminf = mid + 1;
    } else {
      break;
    }
  }
  return resultado;
}

int main() {
  ifstream file;

  file.open("canalsuez.txt");

  string date;
  string time;
  string entry;
  string ubi;

  vector<Log> logs;

  while (file >> date >> time >> entry >> ubi) {
    string newdate;
    newdate = date;
    char item = newdate[0];
    newdate[0] = newdate[7];
    newdate[7] = item;
    item = newdate[1];
    newdate[1] = newdate[8];
    newdate[8] = item;

    Log log(date, newdate, time, entry, ubi);
    logs.push_back(log);
  }

  quickSort(logs, 0, logs.size() - 1);
  printLogs(logs);

  string numeroBuscar;
  cout << "Ingresa los tres primeros caracteres de la UBI" << endl;
  cin >> numeroBuscar;

  vector<Log> resultado = binarySearch(logs, numeroBuscar);
  quickSortDate(resultado, 0, resultado.size() - 1);
  printLogs(resultado);

  return 0;
}