#include "../include/SimpleGraph.h"


GrafoSimples::GrafoSimples()
{
    adjs = *(new vector< unordered_map<int, float> >());
    rotulos = *(new vector<string>());
    inserirVertice("NULL");  // vertice nulo para normalizar id dos vertices com posicao no vetor
}

GrafoSimples::~GrafoSimples(){}

int GrafoSimples::ler(string fileName){return 0;}

int GrafoSimples::inserirVertice(string rotulo)
{
    adjs.push_back( unordered_map<int, float>() );
    rotulos.push_back( rotulo );

    return adjs.size()-1;
}


int GrafoSimples::qtdVertices()
{
    return adjs.size()-1;
}


string GrafoSimples::rotulo(int v)
{
    return rotulos[v];
}


float GrafoSimples::peso(int u, int v)
{
    if (u == v)
        return 0;

    auto it = adjs[u].find(v);
    if (it == adjs[u].end())
        return INFINITE_FLOAT;
    else
        return adjs[u][v];

}


void GrafoSimples::imprimir()
{
    for (size_t i = 1; i < rotulos.size(); i++)
        cout << i <<": " << rotulos[i] << "\n";

    cout << endl;

    for(int v = 1; v < adjs.size(); v++) {
        cout << v << ": ";
        for (auto pr: adjs[v])
            cout << "(" << pr.first << ", " << pr.second << "), ";

        cout << "\n";
    }
}
