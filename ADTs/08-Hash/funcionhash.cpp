#include <iostream>
using namespace std;
 
int hashFunction(string matricula) {
    try {
        int numMatricula = stoi((matricula.substr(1,8)));
        return numMatricula % 99;
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
    }
    
    
}

int main() {
 
    cout << hashFunction("Alexandria") << endl;
    string a = "";
    if (a == "") {
        cout << "Es nulo" << endl;
    } 
    return 0;
}