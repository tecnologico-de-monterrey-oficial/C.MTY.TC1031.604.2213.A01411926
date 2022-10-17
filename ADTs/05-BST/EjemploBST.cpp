#include <iostream>
using namespace std;

#include "BST.h"

int main()
{
    BST<int> bst;    

    bst.insert(40);
    bst.insert(20);    
    bst.insert(60); 
    bst.insert(10);
    bst.insert(30);
    bst.insert(15);   
    bst.insert(25);
    bst.insert(12);
    bst.print();
    // try {
    //     bst.remove(40);
    // } catch(invalid_argument &error) {
    //     cout << error.what() << endl;
    // }
    bst.order(7); // InOrder Converso
    return 0;
}
