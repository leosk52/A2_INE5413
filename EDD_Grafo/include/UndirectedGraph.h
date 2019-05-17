#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include "SimpleGraph.h"

using namespace std;


class GrafoNaoDirigido : public GrafoSimples
{
private:
    int qtdArestas_;

public:
    GrafoNaoDirigido();
    ~GrafoNaoDirigido();

    // Implement superclass virtual method to read a file
    int ler(string fileName);

    //inserir nova aresta
    void inserirAresta(int u, int v, float peso);

    // retorna a quantidade de arestas do grafo
    int qtdArestas();

    // retorna o grau de um vertice v
    int grau(int v);

    // retorna a lista de vizinhos de um vertice v
    vector<int> vizinhos(int v);

    // retorna true caso exista uma aresta de u para v
    bool haAresta(int u, int v);

};

#endif // UNDIRECTEDGRAPH_H
