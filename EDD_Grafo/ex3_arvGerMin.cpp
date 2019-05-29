#include "include/UndirectedGraph.h"
#include <unordered_map>

using namespace std;


int main(int argc, char const *argv[]) {

	// Checagem do arquivo passado por parametro
    ifstream myReadFile;
    if (argc < 2) {
        cout << "Insira o nome do arquivo";
        return 1;
    }


    // criacao do grafo e leitura do arquivo de entrada para populacao
    GrafoNaoDirigido* grafo = new GrafoNaoDirigido();

    if (!grafo->ler(argv[1])) {
        cout << "Arquivo inexistente\n";
		return 1;
    }


	// Algoritmo de Prim
    // Inicializacao
	int r = 1;
    int num_vertices = grafo->qtdVertices()+1;

    float* k = new float[num_vertices];
    int* a = new int[num_vertices];

    for (int v = 0; v < num_vertices; ++v) {
        k[v] = INFINITE_FLOAT;
        a[v] = -1;
    }

    k[r] = 0;
    unordered_map<int, float> q;
	for (int i = 1; i < num_vertices; ++i)
		q.emplace(i, k[i]);


    while (!q.empty()) {
		auto argmin = q.begin();
		for (auto it = q.begin(); it != q.end(); ++it) {
			if ((*argmin).second > (*it).second)
				argmin = it;
		}

		q.erase(argmin);

		int u = (*argmin).first;
		vector<int> vizinhos = grafo->vizinhos(u);
		for (int v : vizinhos) {
			float peso = grafo->peso(u, v);
			if (q.find(v) != q.end() && peso < k[v]) {
				a[v] = u;
				k[v] = peso;
				q[v] = k[v];
			}
		}
	}


    // Saida
	// print a
	float peso_total = 0;
	string msg = "";
	for (int i = 2; i < num_vertices; ++i) {
		peso_total += grafo->peso(i, a[i]);
		if (i != 2)
			msg += ", ";

		msg += to_string(i) + "-" + to_string(a[i]);
	}

	cout << int(peso_total) << endl << msg << endl;

	return 0;
}
