/*
Autor: Daniel Sandoval
Fecha: 09-08-2023
Tema: Lists
Objetivo: Learning Basic Data Structures
*/

#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> lista00;
    list<int> lista01 = {10, 20, 30};
    list<int> lista02(lista01.begin(), lista01.end());
    list<int> lista03(move(lista01));

    cout << "Tamaño de la lista00: " << lista00.size() << endl;

    cout << "Contenido de la lista02: "<< endl;
    for (auto itr = lista02.begin(); itr != lista02.end(); itr++){
        cout << *itr << " ";
    }

    cout << "\nContenido de la lista03: "<< endl;
    for (auto itr = lista03.begin(); itr != lista03.end(); itr++){
        cout << *itr << " ";
    }

    return 0;
}