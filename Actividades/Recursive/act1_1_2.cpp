#include <iostream>
using namespace std;



int fibonacciRecursivo(int n) {
  if (n==1 || n==2) {
      return 1;
  } else {
      return fibonacciRecursivo(n-1) + fibonacciRecursivo(n-2);
  }
}

int bacteriasIterativo(int dias) {
  int bacterias = 1;
  for (int d=1; d<=dias; d++) {
    bacterias = bacterias * (1 + (3.78 - 2.34));
  }
  return bacterias;
}

int bacteriasRecursivo(int dias) {
  if (dias == 0) {
    return 1;
  } else {
    return bacteriasRecursivo(dias-1) * (1 + (3.78 - 2.34));
  }
}

double interesIterativo(int meses, double saldo) {

  // Iterar desde 1 hasta la cantidad de meses
  // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
  // Por cada iteración vamos a ejecutar 
  // saldo = saldo * (1 + .1875); 
  for (int i=1; i<=meses; i++) {
    saldo = saldo * (1 + .1875);  
  }
  return saldo;
}

// Iterar de meses hasta 0
// 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
// meses = 0 -> saldo
// Se va ejecutar la función 
// saldo = saldo * (1 + .1875); 
// empezando con 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
double interesRecursivo(int meses, double saldo) {
  // condición de control
  if (meses==0) {
    return saldo;
  } else {
    return interesRecursivo(meses-1, saldo) * (1 + .1875);
  }
}

int potenciaIterativa(int x, int y) {
  int potencia = x;
  for (int i=1; i<y; i++) {
    potencia = potencia * x;
  }
  return potencia;
}

int potenciaRecursiva(int x, int y) {
  if (y==1) {
    return x;
  } else {
    return x * potenciaRecursiva(x, y-1);
  }
}
/*
x = 1 -> x
x = 2 -> x * x
x = 3 -> x * x * x
x = 4 -> x * x * x * x


int main()
{
  // solicitar un número al usuario
  // int n;
  // cout << "Teclea un número entero" << endl;
  // cin >> n;
  int n=10;
  int saldo=1000;
  cout << "fibonacci iterativo: " << fibonacciIterativo(n) << endl;
  cout << "fibonacci recursivo: " << fibonacciRecursivo(n) << endl;
  cout << "bacterias iterativo: " << bacteriasIterativo(n) << endl;
  cout << "bacterias iterativo: " << bacteriasRecursivo(n) << endl;
  cout << "interes iterativo: " << interesIterativo(n, saldo) << endl;
  cout << "interes recursivo: " << interesRecursivo(n, saldo) << endl;
  int x = 2;
  int y = 8;
  cout << "potencia iterativo: " << potenciaIterativa(x, y) << endl;
  cout << "potencia recursiva: " << potenciaIterativa(x, y) << endl;
  return 0;
}
