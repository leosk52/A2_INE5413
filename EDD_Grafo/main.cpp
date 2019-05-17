#include "include/UndirectedGraph.h"
#include "include/DirectedGraph.h"

using namespace std;


int main(int argc, char** argv) {

    GrafoNaoDirigido* grafoNaoDirigido = new GrafoNaoDirigido();
    GrafoDirigido* grafoDirigido = new GrafoDirigido();
    GrafoSimples* grafo = new GrafoSimples();

    // Checagem do arquivo passado por parametro
    if (argc < 2) {
        cout << "Insira o nome do arquivo" << '\n';
        return 1;
    }

    if (!grafoDirigido->ler(argv[1])) {
        cout << "Arquivo inexistente" << '\n';
        return 1;
    }


    grafo->imprimir();

    return 0;
}
