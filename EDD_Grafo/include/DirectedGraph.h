#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H

#include "SimpleGraph.h"

using namespace std;


class GrafoDirigido : public GrafoSimples
{
private:
    int qtdArcos_;

public:
    GrafoDirigido();
    ~GrafoDirigido();

    // Implement superclass virtual method to read a file
    int ler(string fileName);

    //inserir novo arco
    void inserirArco(int u, int v, float peso);

    // retorna a quantidade de arestas do grafo
    int qtdArcos();

    // retorna o grau de entrada um vertice v
    int grauEntrada(int v);

	// retorna o grau de saida de um vertice v
    int grauSaida(int v);

    // retorna a lista de vizinhos entrantes de um vertice v
    vector<int> vizinhosEntrantes(int v);

	// retorna a lista de vizinhos saintes de um vertice v
    vector<int> vizinhosSaintes(int v);

    // retorna true caso exista uma aresta de u para v
    bool haArco(int u, int v);

};

#endif // DIRECTEDGRAPH_H
