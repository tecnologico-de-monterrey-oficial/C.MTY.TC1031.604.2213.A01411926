#include<iostream>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include<vector>
using namespace std;
#include"List.h"

int sumInt(int n1, int n2, int n3) {
        return n1+n2+n3;
    }

double sumDouble(double n1, double n2, double n3){
        return n1+n2+n3;
    }

float sumFloat(float n1, float n2, float n3){
        return n1+n2+n3;
    }
string sumString(string n1, string n2, string n3){
    return n1+n2+n3;
}

template<class T>
T sumAnything(T a, T b, T c){
    return a+b+c;
}

int main() {
    
    setlocale(LC_CTYPE, "Spanish");
    //Act 1.0
    //Realiza 3 funciones para sumar 3 números
    //Vas a recibir los 3 números de parámetros
    //1 función con enteros, 1 función con double, 1 función punto flotante
    //sumInt, sumDouble, sumFloat
    /*
    int a = 1;
    int b = 2;
    int c = 3;
    double a2 = 1.5;
    double b2 = 2.5;
    double c2 = 3.5;
    float a3 = 1.3;
    float b3 = 2.3;
    float c3 = 3.3;
    string a4 = "Hola ";
    string b4 = "cómo ";
    string c4 = "estás";
    cout<<"La suma Int de a+b+c es: "<<sumInt(a,b,c)<<endl;
    cout<<"La suma Int Anything de a+b+c es: "<<sumAnything(a,b,c)<<endl;
    cout<<"La suma Double de a+b+c es: "<<sumDouble(a2,b2,c2)<<endl;
    cout<<"La suma Double Anything de a+b+c es: "<<sumAnything(a2,b2,c2)<<endl;
    cout<<"La suma Float de a+b+c es: "<<sumFloat(a3,b3,c3)<<endl;
    cout<<"La suma Float Anything de a+b+c es: "<<sumAnything(a3,b3,c3)<<endl;
    cout<<"La suma String de a+b+c es: "<<sumString(a4,b4,c4)<<endl;
    cout<<"La suma String Anything de a+b+c es: "<<sumAnything(a4,b4,c4)<<endl;

    */

   List<string> list;
   list.add("B");
   list.add("A");
   list.print();
    return EXIT_SUCCESS;
}