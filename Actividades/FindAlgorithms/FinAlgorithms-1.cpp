#include <iostream>
#include <vector>
#include <ctime>
#include <stdio.h>
#include <sys/time.h>
using namespace std;

// Obtiene el tiempo inicial para calcular el tiempo transcurrido por un algoritmo
void startTime(struct timeval &begin)
{
  // start time
  gettimeofday(&begin, 0);
}

// Imprime el tiempo transcurrido desde el valor de start hasta el momento que se ejecuta la función
void getTime(struct timeval begin, struct timeval end)
{
  long seconds, microseconds;
  double elapsed;
  // end time
  gettimeofday(&end, 0);
  seconds = end.tv_sec - begin.tv_sec;
  microseconds = end.tv_usec - begin.tv_usec;
  elapsed = seconds + microseconds * 1e-6;
  printf("Tiempo de ejecución: %.8f seconds.\n", elapsed);
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
  // Variables para calcular el tiempo de ejecución
  struct timeval begin, end;
  

  return 0;
}
