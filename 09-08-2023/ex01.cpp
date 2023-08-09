/*
Autor: Daniel Sandoval
Fecha: 09-08-2023
Tema: Stacks
Objetivo: Learning Basic Data Structures
*/

// Incluyendo las bibliotecas necesarias
#include <iostream>
#include <stack>  // Biblioteca para utilizar la estructura de datos 'stack'
using namespace std;

int main() {
    string program_name = "Stack";  // Nombre del programa
    cout << "\n\n -------------- \n" << program_name << "\n";  // Imprimiendo el título del programa

    stack<int> st;  // Declaración de una pila de enteros llamada 'st'

    // Agregando elementos a la pila
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    st.pop();  // Eliminando el elemento superior de la pila (40)
    st.pop();  // Eliminando el siguiente elemento superior de la pila (30)

    // Imprimiendo los elementos restantes en la pila usando un bucle while
    while (!st.empty()) {
        cout << " " << st.top() << endl;  // Imprimiendo el elemento superior de la pila
        st.pop();  // Eliminando el elemento superior de la pila para avanzar al siguiente
    }

    cout << "\n ...Fin!... \n";  // Imprimiendo un mensaje indicando el final del programa
}
