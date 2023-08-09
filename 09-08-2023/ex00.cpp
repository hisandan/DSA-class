/*
Autor: Daniel Sandoval
Fecha: 09-08-2023
Tema: Arrays
Objetivo: Learning Basic Data Structures
*/

#include <iostream>
using namespace std;

// Clase de plantilla Exp con dos parámetros de plantilla: T (tipo de dato) y element (tamaño del arreglo)
template <class T, int element>
class Exp {
public:
    T a[element]; // Arreglo de tipo T con 'element' cantidad de elementos

    // Función para llenar el arreglo con valores consecutivos comenzando desde 1
    void put() {
        int x = 1;
        for (int j = 0; j < element; j++) {
            a[j] = x;
            x++;
        }
    }

    // Función para imprimir elementos en el arreglo desde el índice 6 hasta el final
    void print() {
        for (int x = 6; x < element; x++) {
            cout << a[x] << " "; // Imprimir el valor en el índice x del arreglo
        }
        cout << "\n ...Fin!... \n"; // Imprimir un mensaje indicando el final de la impresión
        cout << endl; // Imprimir un salto de línea para el formato
    }
};

int main() {
    string program_name = "Basic Array";
    cout << "\n\n -------------- \nProgram: "<< program_name << "\n";


    Exp<int, 16> obj; // Crear una instancia de la clase Exp con int como tipo de dato y un tamaño de arreglo de 16
    obj.put(); // Llamar a la función put para llenar el arreglo con valores
    obj.print(); // Llamar a la función print para imprimir valores en el arreglo
    return 0; // Indicar una ejecución exitosa al retornar 0
}
