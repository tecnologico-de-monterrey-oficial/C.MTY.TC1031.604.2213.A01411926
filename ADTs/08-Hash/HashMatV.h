#ifndef HashMat_h
#define HashMat_h

#include<vector>

class HashMat {
private:
    vector<string> hashTable[99];
    bool status[99];
public:
    HashMat();
    int hashFunction(string matricula);
    bool findMatricula(string matricula);
    void addMatricula(string matricula);
    void deleteMatricula(string matricula);
    void print();
};

HashMat::HashMat() {

}

int HashMat::hashFunction(string matricula) {
    try {
        int numMatricula = stoi((matricula.substr(1,8)));
        return numMatricula % 99;
    } catch (invalid_argument &e) {
        return -1;
    }   
}

bool HashMat::findMatricula(string matricula) {
    // Obtenmos la dirección base con la función hash
    int index = hashFunction(matricula);
    if (index >= 0 && HashMat[index].find(matricula)!=HashMat[index].end) {
        return true;
    } else {
        return false;
    }
}

void HashMat::addMatricula(string matricula) {
    // Obtenmos la dirección base con la función hash
    int index = hashFunction(matricula);
    if (index >= 0) {
        if (HashMat[index].find(matricula)!= HashMat[index].end){
            return;
        }
        HashMat[index].push_back(matricula);
        return;
    } else {
        throw invalid_argument("La matrícula no es una matrícula");
    }
}

void HashMat::deleteMatricula(string matricula) {
    // Obtenmos la dirección base con la función hash
    int index = hashFunction(matricula);
    if (index >= 0) {
        if(HashMat[index].find(matricula) != HashMat[index].end){
            HashMat.delete(HashMat[index].find(matricula));
            return;
        }
        return;
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


#endif