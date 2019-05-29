#include "include/UndirectedGraph.h"
#include "include/DirectedGraph.h"

#include <list>

using namespace std;


// Algoritmo auxiliar DFS-Visit-OT
void DFS_Visit_OT(GrafoDirigido* g, int v, bool* c, int* t, int* f, int tempo, list<string>* o) {

	c[v] = true;
	tempo++;
	t[v] = tempo;

	vector<int> vizinhos = g->vizinhosSaintes(v);
	for (int u : vizinhos) {
		if (!c[u])
			DFS_Visit_OT(g, u, c, t, f, tempo, o);
	}

	tempo++;
	f[v] = tempo;
	o->push_front(g->rotulo(v));

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


	////////////// ORDENACAO TOPOLOGICA ///////////////////////

	// Inicializacao
	int num_vertices = grafo->qtdVertices()+1;
	bool* c = new bool[num_vertices];
	int* t = new int[num_vertices];
	int* f = new int[num_vertices];

	for (int i = 0; i < num_vertices; ++i) {
		c[i] = false;
		t[i] = INFINITE_INT;
		f[i] = INFINITE_INT;
	}

	int tempo = 0;

	list<string>* o = new list<string>();


	// laco principal
	for (int v = 1; v < num_vertices; ++v) {
		if (!c[v])
			DFS_Visit_OT(grafo, v, c, t, f, tempo, o);
	}


	// saida
	string out = "";
	for (auto it = o->begin(); it != o->end(); ++it) {
		if (it != o->begin())
			out += " -> ";
		out.append(*it);

	}
	out += ".";

	cout << out << endl;


    return 0;
}
