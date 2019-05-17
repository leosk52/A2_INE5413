echo "Compiling files..."

cd EDD_Grafo

# Objects creation
g++ -c src/SimpleGraph.cpp -std=c++17
g++ -c src/DirectedGraph.cpp -std=c++17
g++ -c src/UndirectedGraph.cpp -std=c++17


# Executables compiling
g++ -o ../runMain.o main.cpp SimpleGraph.o DirectedGraph.o UndirectedGraph.o -std=c++17


# Objects delete
if [ -f "./SimpleGraph.o" ]; then
	rm SimpleGraph.o
fi

if [ -f "./DirectedGraph.o" ]; then
	rm DirectedGraph.o
fi

if [ -f "./UndirectedGraph.o" ]; then
	rm UndirectedGraph.o
fi
