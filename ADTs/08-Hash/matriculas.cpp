#include <iostream>
#include <fstream>
using namespace std;

#include "HashMat.h"
#include "HashMatV.h"


int main() {

    HashMat mat;
    fstream file("matriculas.txt");
    string matricula;
    while (file >> matricula) {
        mat.addMatricula(matricula);
    }

    mat.print();
    try {
        mat.deleteMatricula("A01198211");
    } catch(invalid_argument &e) {
        cout << e.what() << endl;
    }
    if (mat.findMatricula("A00829931")) {
        cout << "Si la encontramos" << endl;
    } else {
        cout << "No la encontramos" << endl;
    }
    
    try {
        mat.addMatricula("A01198211");
    } catch(invalid_argument &e) {
        cout << e.what() << endl;
    }
    mat.print();
    return 0;
}
