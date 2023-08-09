/*
Autor: Daniel Sandoval
Fecha: 09-08-2023
Tema: Lists
Objetivo: Learning Basic Data Structures
*/

// Incluyendo las bibliotecas necesarias
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int main(){

    string program_name = "List";  // Nombre del programa
    cout << "\n\n -------------- \nPrograma: " << program_name << "\n";  // Imprimiendo el título del programa

    list <int> lista00 = {12,5,10,9,0,-1};
    lista00.push_front(11);
    lista00.push_back(18);
    auto it = std::find(lista00.begin(), lista00.end(), 10);

    if (it != lista00.end()) {
        lista00.insert(it, 21);
    } 
    for(int x: lista00) {
        cout << x << "\n";
    }
}
