/*
Autor: Daniel Sandoval
Fecha: 09-08-2023
Tema: Queues
Objetivo: Learning Basic Data Structures
*/

// Incluyendo las bibliotecas necesarias
#include <iostream>
#include <queue> // Biblioteca para utilizar la estructura de datos 'queue'
using namespace std;

// Declaración de la función que se usará para trabajar con la cola
void tool_cola(queue<string> objeto);

int main() {
    string program_name = "Queue";  // Nombre del programa
    cout << "\n\n -------------- \nPrograma: " << program_name << "\n";  // Imprimiendo el título del programa

    // Creando una cola de cadenas
    queue<string> animales;
    animales.push("Gato");
    animales.push("Hormiga");
    animales.push("Perro");
    animales.push("Conejo");

    cout << "\n Cola inicial: \n";
    tool_cola(animales);  // Llamando a la función para trabajar con la cola

    // Eliminando un elemento de la cola
    animales.pop();
    cout << "\n Cola despues de remover un elemento: \n";
    tool_cola(animales);  // Llamando a la función nuevamente para mostrar la cola modificada
    return 0;
}

// Definición de la función para trabajar con la cola
void tool_cola(queue<string> objeto) {
    cout << "\n Tamaño de la cola: " << objeto.size() << endl;

    // Imprimiendo y eliminando elementos de la cola usando un bucle while
    while (!objeto.empty()) {
        cout << objeto.front() << ", "; // Imprimiendo el elemento en frente de la cola
        objeto.pop();  // Eliminando el elemento en frente para avanzar al siguiente
    }
    cout << "\n ...Fin!... \n";  // Imprimiendo un mensaje indicando el final
}
