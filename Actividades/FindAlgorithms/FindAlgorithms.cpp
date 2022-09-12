#include <iostream>
#include <vector>
using namespace std;



bool sequentialSearch(vector<int> list, int n){
    //Algoritmo de búsqueda secuencial
    //Iteramos en todos los elementos de la lista con un for de 0 al tamaño de la lista

    for(int i=0; i<list.size(); i++){
        //Validamos si el valor de n es igual al elemento i de la lsita
        if (list[i]==n){
            return true;
        }
    }
    return false; 
}



int main()
{
    vector<int> list = {5, 8, 20, 4, 100, 15};

    //Solicita al usuario un número entero entre 1 y 100
    //Despliega un mensaje que indique si el número tecleado por el usuario existe en la lista
    //Despliega "Sí existe" en caso de que sí exista
    //Despliega "No existe" en caso de que no exista
    //Utiliza el algoritmo de búsqueda secuencial
    int n=0;
    while (n<1 || n>100){
        cout<<"Teclea un número entre 1, y 100"<< endl;
        cin>>n;
        if (n<1 || n>100){
            cout<<"Error:  El número debe estar entre 1 y 100"<<endl;
            
        }
    }
    if (sequentialSearch(list, n)){
        cout<<"Sí existe"<<endl;
    }
    else{
        cout<<"No existe"<<endl;
    }

    
    system("pause");
    return 0;
}
