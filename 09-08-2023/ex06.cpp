/*
Autor: Daniel Sandoval
Fecha: 09-08-2023
Tema: Conjuntos
Objetivo: Aprender Estructuras de Datos Básicas
*/

#include <iostream>
#include <set>  // Incluyendo la biblioteca para utilizar la estructura de datos 'set'
using namespace std;

int main() {
    // Declaración y asignación de conjuntos con diferentes tipos de datos
    set<string> conjunto00 {"iphone", "android", "basic", "landline"};
    set<char> conjunto01 {'a', 'b', 'c', 'd'};
    set<int> conjunto02 {1, 3, 4, 5};
    int i = 5;

    // Iterando a través del conjunto00 e insertando elementos en conjunto02
    for (auto it = conjunto00.begin(); it != conjunto00.end(); it++, ++i) {
        conjunto02.insert('a' + i);  // Insertando valores en conjunto02
    }

    // Imprimiendo el tamaño de los conjuntos
    cout << "Tamaño del conjunto 00: " << conjunto00.size() << endl;
    cout << "Tamaño del conjunto 01: " << conjunto01.size() << endl;
    cout << "Tamaño del conjunto 02: " << conjunto02.size() << endl;

    return 0;
}
