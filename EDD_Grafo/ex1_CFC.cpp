#include "include/UndirectedGraph.h"
#include "include/DirectedGraph.h"

#include <list>

using namespace std;

// Algoritmo auxiliar DFS-Visit
void DFS_Visit(GrafoDirigido* g, int v, int* a, bool* c, int* t, int* f, int tempo) {

	c[v] = true;
	tempo++;
	t[v] = tempo;

	vector<int> vizinhos = g->vizinhosSaintes(v);
	for (int u : vizinhos) {
		if (!c[u]) {
            a[u] = v;
			DFS_Visit(g, u, a, c, t, f, tempo);
        }
	}

	tempo++;
	f[v] = tempo;
}

// Algoritmo auxiliar DFS
void DFS(GrafoDirigido* g, int num_vertices, bool* c, int* t, int* f, int* a) {

	for (int i = 0; i < num_vertices; ++i) {
		c[i] = false;
		t[i] = INFINITE_INT;
		a[i] = -1;
		f[i] = INFINITE_INT;
	}

    int tempo = 0;

	for (int u = 1; u < num_vertices; ++u) {
		if (!c[u])
			DFS_Visit(g, u, a, c, t, f, tempo);
	}
}

// Algoritmo auxiliar DFSAlterado
void DFSAlterado(GrafoDirigido* g, int num_vertices, bool* c, int* t, int* f, int* a) {

	for (int i = 0; i < num_vertices; ++i) {
		c[i] = false;
		t[i] = INFINITE_INT;
		f[i] = INFINITE_INT;
		a[i] = -1;
	}

    int tempo = 0;

	//pegar em ordem decrescente de T
	bool tst = true;
	while (tst) {
		tst = false;
		int maior = -1;
		int maior_idx = -1;
		for (size_t i = 1; i < num_vertices; ++i) {
			if (f[i] > maior && !c[i]) {
				tst = true;
				maior = f[i];
				maior_idx = i;
			}
		}
		if (maior_idx != -1) {
			DFS_Visit(g, maior_idx, a, c, t, f, tempo);
		}
	}
}

/////////////////// MAIN /////////////////////////////////
int main(int argc, char** argv) {
    GrafoDirigido* grafo = new GrafoDirigido();

    // Checagem do arquivo passado por parametro
    if (argc < 2) {
        cout << "Insira o nome do arquivo" << '\n';
        return 1;
    }

    if (!grafo->ler(argv[1])) {
        cout << "Arquivo inexistente" << '\n';
        return 1;
    }

	////////////// CFC ///////////////////////

	// Inicializacao
	int num_vertices = grafo->qtdVertices()+1;
	bool* c = new bool[num_vertices];
	int* t = new int[num_vertices];
	int* a = new int[num_vertices];
	int* f = new int[num_vertices];

	DFS(grafo, num_vertices, c, t, f, a);

    GrafoDirigido* grafo_transp = new GrafoDirigido();
	for (int i = 0; i < num_vertices; ++i) {
		grafo_transp->inserirVertice(grafo->rotulo(i));
	}
	for (int i = 1; i < num_vertices; ++i) {
		vector<int> vizinhos = grafo->vizinhosSaintes(i);
		for (int u : vizinhos) {
			grafo_transp->inserirArco(u, i, grafo->peso(i, u));
		}
	}

	DFSAlterado(grafo_transp, num_vertices, c, t, f, a);

	// saida
	for (int u = 1; u < num_vertices; u++) {
		if (a[u] == -1)
			cout << "\n" << u << ", ";
		else 
			cout << u << ", ";
	}
	cout << "\n";

    return 0;
}
