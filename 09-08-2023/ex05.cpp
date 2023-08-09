/*
Autor: Daniel Sandoval
Fecha: 09-08-2023
Tema: Listas
Objetivo: Aprender Estructuras de Datos Básicas
*/

#include <iostream>
#include <list>  // Incluyendo la biblioteca para utilizar la estructura de datos 'list'
using namespace std;

int main() {
    list<int> lista00;  // Declaración de una lista de enteros llamada 'lista00'
    list<int> lista01 = {10, 20, 30};  // Declaración y asignación de una lista con valores iniciales
    list<int> lista02(lista01.begin(), lista01.end());  // Declaración de una lista con los valores de otra lista
    list<int> lista03(move(lista01));  // Declaración de una lista moviendo los valores de otra lista

    cout << "Tamaño de la lista00: " << lista00.size() << endl;  // Imprimiendo el tamaño de la lista00

    cout << "Contenido de la lista02: " << endl;
    for (auto itr = lista02.begin(); itr != lista02.end(); itr++) {
        cout << *itr << " ";  // Imprimiendo el valor apuntado por el iterador
    }

    cout << "\nContenido de la lista03: " << endl;
    for (auto itr = lista03.begin(); itr != lista03.end(); itr++) {
        cout << *itr << " ";  // Imprimiendo el valor apuntado por el iterador
    }

    return 0;
}
