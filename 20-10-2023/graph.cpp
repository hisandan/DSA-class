// graph.cpp

#include "graph.h"
#include <iostream>

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::agregarArista(int src, int dest) {
    adj[src].push_back(dest);
}

void Graph::mostrarGrafo() {
    for (int i = 0; i < V; i++) {
        std::cout << "Nodo " << i << " está conectado a:";
        for (int vecino : adj[i]) {
            std::cout << " " << vecino;
        }
        std::cout << std::endl;
    }
}

Graph Graph::obtenerTranspuesta() {
    Graph transpuesta(V);
    for (int i = 0; i < V; i++) {
        for (int vecino : adj[i]) {
            transpuesta.agregarArista(vecino, i);
        }
    }
    return transpuesta;
}

void Graph::BFS(int nodoInicio) {
    std::vector<bool> visitado(V, false);
    std::queue<int> cola;
    visitado[nodoInicio] = true;
    cola.push(nodoInicio);

    std::cout << "Recorrido BFS desde el nodo " << nodoInicio << ": ";

    while (!cola.empty()) {
        int actual = cola.front();
        std::cout << actual << " ";
        cola.pop();

        for (int vecino : adj[actual]) {
            if (!visitado[vecino]) {
                visitado[vecino] = true;
                cola.push(vecino);
            }
        }
    }
    std::cout << std::endl;
}
