/*
Autor: Daniel Sandoval
Fecha: 09-08-2023
Tema: Listas
Objetivo: Aprender Estructuras de Datos Básicas
*/

// Incluyendo las bibliotecas necesarias
#include <iostream>
#include <algorithm>  // Biblioteca para utilizar la función 'find'
#include <list>       // Biblioteca para utilizar la estructura de datos 'list'
using namespace std;

int main() {

    string program_name = "List";  // Nombre del programa
    cout << "\n\n -------------- \nPrograma: " << program_name << "\n";  // Imprimiendo el título del programa

    list<int> lista00 = {12, 5, 10, 9, 0, -1};  // Creación de una lista de enteros llamada 'lista00'
    lista00.push_front(11);  // Agregando el valor 11 al principio de la lista
    lista00.push_back(18);   // Agregando el valor 18 al final de la lista

    // Encontrando el valor 10 en la lista usando la función 'find'
    auto it = std::find(lista00.begin(), lista00.end(), 10);

    // Insertando el valor 21 antes de la posición donde se encontró el valor 10
    if (it != lista00.end()) {
        lista00.insert(it, 21);
    }

    // Imprimiendo los elementos de la lista usando un bucle for-each
    for (int x : lista00) {
        cout << x << "\n";  // Imprimiendo el valor y saltando a la siguiente línea
    }
}
