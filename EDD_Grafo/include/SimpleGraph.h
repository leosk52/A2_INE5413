#ifndef SIMPLEGRAPH_H
#define SIMPLEGRAPH_H

#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
#include <limits>
#include <fstream>

#define INFINITE_FLOAT numeric_limits<float>::max()
#define INFINITE_INT numeric_limits<int>::max()

using namespace std;


class GrafoSimples
{
protected:
    vector< unordered_map<int, float> > adjs;
    vector<string> rotulos;

public:

    // Constructor
    GrafoSimples();

    // destructor
    virtual ~GrafoSimples();

    // le o arquivo (DIFERE)
    virtual int ler(string fileName);

    //retorna o id do vertice inserido
    int inserirVertice(string rotulo);

    // imprime o grafo
    void imprimir();

    // retorna a quantidade de vertices do grafo
    int qtdVertices();

    // retorna o rotulo de um vertice v
    string rotulo(int v);

    // retorna o peso do arco/aresta que liga u e v
    float peso(int u, int v);

};

#endif // SIMPLEGRAPH_H
