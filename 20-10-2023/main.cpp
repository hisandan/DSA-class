#include "graph.h"
#include <iostream>

int main() {
    int V = 4; // Número de vértices en el grafo
    Graph g(V);

    // Agregar aristas
    g.agregarArista(0, 1);
    g.agregarArista(0, 2);
    g.agregarArista(1, 2);
    g.agregarArista(2, 3);

    // Mostrar el grafo original
    std::cout << "Grafo original:" << std::endl;
    g.mostrarGrafo();

    // Obtener la transpuesta del grafo
    Graph transpuesta = g.obtenerTranspuesta();
    std::cout << "Transpuesta del grafo:" << std::endl;
    transpuesta.mostrarGrafo();

    // Realizar el recorrido BFS desde diferentes nodos
    g.BFS(0);
    g.BFS(3);

    return 0;
}
