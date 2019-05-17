#include "../include/DirectedGraph.h"

GrafoDirigido::GrafoDirigido()
{
    GrafoSimples();
    qtdArcos_ = 0;
}

GrafoDirigido::~GrafoDirigido(){}

// Implement superclass virtual method
int GrafoDirigido::ler(string fileName)
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
            if (myReadFile.eof())
                break;
            inserirArco(verticeOrigem, verticeDestino, peso);
        }
    }
    myReadFile.close();
    return 1;
}

void GrafoDirigido::inserirArco(int u, int v, float peso)
{
    adjs[u].emplace(v, peso);
    qtdArcos_ ++;
}

int GrafoDirigido::qtdArcos()
{
    return qtdArcos_;
}

int GrafoDirigido::grauEntrada(int v)
{
    return vizinhosEntrantes(v).size();
}

int GrafoDirigido::grauSaida(int v)
{
    return adjs[v].size();
}

vector<int> GrafoDirigido::vizinhosEntrantes(int v)
{
	int num_vertices = qtdVertices();
    vector<int> vizinhos = *(new vector<int>());

    for (int i = 1; i <= num_vertices; ++i) {
		if (adjs[i].find(v) != adjs[i].end())
			vizinhos.push_back(v);
	}

    return vizinhos;
}

vector<int> GrafoDirigido::vizinhosSaintes(int v)
{
    vector<int> vizinhos = *(new vector<int>());

    for (auto it : adjs[v])
        vizinhos.push_back(it.first);

    return vizinhos;
}

bool GrafoDirigido::haArco(int u, int v)
{
    return adjs[u].find(v) != adjs[u].end();
}
