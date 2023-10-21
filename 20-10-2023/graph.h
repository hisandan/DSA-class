// graph.h

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <queue>

class Graph {
public:
    Graph(int V);
    void agregarArista(int src, int dest);
    void mostrarGrafo();
    Graph obtenerTranspuesta();
    void BFS(int nodoInicio);

private:
    int V;
    std::vector<std::vector<int>> adj;
};

#endif
