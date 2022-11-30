#ifndef HashMat_h
#define HashMat_h

class HashMat {
private:
    string hashTable[99];
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

void HashMat::deleteMatricula(string matricula) {
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


#endif