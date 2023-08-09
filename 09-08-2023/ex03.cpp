/*
Autor: Daniel Sandoval
Fecha: 09-08-2023
Tema: Pointers
Objetivo: Learning Basic Data Structures
*/

// Incluyendo las bibliotecas necesarias
#include <iostream>
#include <vector>
using namespace std;


int main(){

    // initialize 2 vectors
    vector<int> v1, v2;

    //add elements to vectors
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
        v2.push_back(i + 2);
    }

    // initialize an iterator itr pointing to begining of vector v1
    vector<int>::iterator itr = v1.begin();
    // copy elements of v2 to v1 at the beginning
    copy(v2.begin(), v2.end(), v1.begin());

    // print all elements of v1
    cout << "Elements of v1 after copying from v2 are:";
    for (itr = v1.begin(); itr != v1.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;
    return 0;
}