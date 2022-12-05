#ifndef HashMat_h
#define HashMat_h

#include <string>
#include <iostream>
using namespace std;

class HashMat {
private:
    string hashTable[99];
    bool status[99];
public:
    HashMat();
    int hashFunction(string matricula);
    bool findMatricula(string matricula);
    void addMatricula(string matricula);
    void deletee(string matricula);
    void print();
    string get(int index);
};

HashMat::HashMat() {

}

int HashMat::hashFunction(string matricula) {
    try {
        //Usamos los primeros 3 letras del string y los convertimos a su ASCII code y usamos eso como su índice
        string finales = to_string(matricula[0]) + to_string(matricula[1]) + to_string(matricula[2]);
        int numMatricula = stoi((finales));
        return numMatricula % 99;
    } catch (invalid_argument &e) {
        return -1;
    }   
}

bool HashMat::findMatricula(string matricula) {
    // Obtenmos la dirección base con la función hash
    int index = hashFunction(matricula);
    int baseIndex = index;
    if (index >= 0) {
        while (hashTable[index] != "" || status[index]) {
            // Validar si el elemento se encuentra en el índice base
            if (hashTable[index] == matricula) {
                // ya lo encontré
                return true;
            } else {
                index = (index + 1) % 99;
                // Validamos si ya le dimos la vuelta
                if (index == baseIndex) {
                    return false;
                }
            }
        }
        // no lo encontramos
        return false;
    } else {
        return false;
    }
}

void HashMat::addMatricula(string matricula) {
    // Obtenmos la dirección base con la función hash
    int index = hashFunction(matricula);
    int baseIndex = index;
    if (index >= 0) {
        while (hashTable[index] != "") {
            index = (index + 1) % 99;
            // Validamos si ya le dimos la vuelta
            if (index == baseIndex) {
                throw invalid_argument("La tabla esta llena");
                return;
            }
        }
        // Insertamos el dato
        hashTable[index] = matricula;
        // Actualizamos el status
        status[index] = false;
    } else {
        throw invalid_argument("La matrícula no es una matrícula");
    }
}

void HashMat::deletee(string matricula) {
    // Obtenmos la dirección base con la función hash
    int index = hashFunction(matricula);
    int baseIndex = index;
    if (index >= 0) {
        while (hashTable[index] != "" || status[index]) {
            // Validar si el elemento se encuentra en el índice base
            if (hashTable[index] == matricula) {
                // ya lo encontré
                // lo borro (inicializo con "")
                hashTable[index] = "";
                // Cambiar el status
                status[index] = true;
                // nos salimos
                return;
            } else {
                // La prueba lineal
                index = (index + 1) % 99;
                // Validamos si ya le dimos la vuelta
                if (index == baseIndex) {
                    throw invalid_argument("La matrícula no se encuentra");
                    return; 
                }
            }
        }
        throw invalid_argument("La matrícula no se encuentra");
    } else {
        throw invalid_argument("La matrícula no es una matrícula");
    }
}

void HashMat::print() {
    for (int i=0; i<99; i++) {
        cout << i << " " << hashTable[i] << endl;
    }
}

//Regresamos el valor en el índice especificado
string HashMat::get(int index) {
    return hashTable[index];
}


#endif