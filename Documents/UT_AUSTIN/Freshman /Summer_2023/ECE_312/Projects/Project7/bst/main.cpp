//
// EE 312 Fall 2020
//
// The BST should work for any data type or object.
// Other user created objects must have the << operator
// overloaded for output.
//

#include <iostream>
#include <fstream>
#include "BST312.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

using namespace std;

template <typename T>
void print(vector<T> vec){
    for(auto vecVal : vec){
        cout << vecVal << endl;;
    }
}

int main() {

    ifstream inFile;
    inFile.open("test.txt");

    BST_312<double> bst;

    double s;
    inFile >> s;
    while (inFile) {;
        cout << "inserting ... " << s << endl;
        bst.insertItem(s);
        inFile >> s;
    }

    cout << "postorder traversal is " << endl;
    print(bst.postOrderTraversal());
    cout << endl;

    cout << "preorder traversal is " << endl;
    print(bst.preOrderTraversal());
    cout << endl;

    cout << "inorder traversal is " << endl;
    print(bst.inOrderTraversal());
    cout << endl;

    cout << "Remove items " << endl;
    cout << "number of nodes in tree before delete is " << bst.countNodes() << endl;
    s = 2.2;
    bst.deleteItem(s);
    print(bst.postOrderTraversal());
    cout << endl;
    cout << "number of nodes in tree after delete is " << bst.countNodes() << endl;
    cout << endl;

}

