#include "../include/UndirectedGraph.h"

GrafoNaoDirigido::GrafoNaoDirigido()
{
    GrafoSimples();
    qtdArestas_ = 0;
}

GrafoNaoDirigido::~GrafoNaoDirigido(){}

int GrafoNaoDirigido::ler(string fileName)
{
    ifstream myReadFile;
    myReadFile.open(fileName);
    if (myReadFile.fail()) {
        return 0;
    }
    // Leitura do arquivo e construcao do grafo
    string output;
    int vertices;

    if (myReadFile.is_open()) {
        myReadFile >> output; //descarta string *vertices
        myReadFile >> output; //pega a quantidade de vertices
        vertices = stoi(output);

        for (size_t i = 0; i < vertices; i++) {
            int vertice;
            string rotulo;
            myReadFile >> vertice;
            getline(myReadFile, rotulo);
            inserirVertice(rotulo);
        }

        myReadFile >> output; //descarta string *edges

        while (true) {
            int verticeOrigem, verticeDestino;
            float peso;
            myReadFile >> verticeOrigem >> verticeDestino >> peso;
            inserirAresta(verticeOrigem, verticeDestino, peso);
            if (myReadFile.eof())
              break;
        }
    }
    myReadFile.close();
    return 1;
}

void GrafoNaoDirigido::inserirAresta(int u, int v, float peso)
{
    adjs[u].emplace(v, peso);
    adjs[v].emplace(u, peso);
    qtdArestas_ ++;
}

int GrafoNaoDirigido::qtdArestas()
{
    return qtdArestas_;
}

int GrafoNaoDirigido::grau(int v)
{
    return adjs[v].size();
}

vector<int> GrafoNaoDirigido::vizinhos(int v)
{
    vector<int> vizinhos = *(new vector<int>());

    for (auto it : adjs[v])
        vizinhos.push_back(it.first);

    return vizinhos;
}

bool GrafoNaoDirigido::haAresta(int u, int v)
{
    return adjs[u].find(v) != adjs[u].end();
}
