from grafo import Grafo

g = Grafo(True, False)

print(g.arestas)
print(g.transposta())

print("Hello World")

#  1-CFC

def vizinhos(d, v):
        return d[v]

def DFS_Visit(g, v, visitado, tempoVisita, antecessor, tempoFinal, tempo):
    print("ai")
    visitado[v] = True
    tempo = tempo + 1
    tempoVisita[v] = tempo
    print(g.arestas)
    if v in g.arestas.keys():
        for u in g.vizinhos(v): 
            print(visitado)
            if u in g.arestas.keys():
                if visitado[u] == False:
                    antecessor[u] = v
                    DFS_Visit(g, u, visitado, tempoVisita, antecessor, tempoFinal, tempo)
    
    
    tempo = tempo + 1
    tempoFinal[v] = tempo
#

def DFS(g, visitado, tempoVisita, antecessor, tempoFinal):
    # configurando todos os vértices
    print(visitado)
    visitado = {x:False for x in g.vertices} # Cv←false ∀v ∈ V
    tempoVisita = {x:float('inf') for x in g.vertices} # Tv ←∞ ∀v ∈ V
    tempoFinal = {x:float('inf') for x in g.vertices} # Fv ←∞ ∀v ∈ V
    antecessor = {x:None for x in g.vertices} # Av ←∞ ∀v ∈ V
    print(visitado)
    tempo = 0
    
    for u in g.vertices:
        if u in g.arestas.keys():
            if visitado[u] == False:
                DFS_Visit(g, u, visitado, tempoVisita, antecessor, tempoFinal, tempo)
                
    return(visitado, tempoVisita, antecessor, tempoFinal)
#

# algoritmo auxiliar DFS-Alterado
def DFS_Alterado(gTransposto, visitado, tempoVisita, antecessor, tempoFinal):
    visitado = {x:False for x in g.vertices} # Cv←false ∀v ∈ V
    tempoVisita = {x:float('inf') for x in g.vertices} # Tv ←∞ ∀v ∈ V
    tempoFinal = {x:float('inf') for x in g.vertices} # Fv ←∞ ∀v ∈ V
    antecessor = {x:None for x in g.vertices} # Av ←∞ ∀v ∈ V
    
    tempo = 0
    print("Hola manito")
    
    # pega em ordem decrescente de F
    teste = True
    while (teste):
        teste = False
        maior = -1
        maior_indice = -1
        print(g.vertices)
        for i in g.vertices:
            if tempoFinal[i] > maior and visitado[i] == False:
                teste = True
                maior = tempoFinal[i]
                maior_indice = i
        
        if maior_indice != -1:
            DFS_Visit(gTransposto, maior_indice, visitado, tempoVisita, antecessor, tempoFinal, tempo)

#

# Vetor C/Visitado
# Vetor T/tempo de visita
# Vetor A'/Antecessor 
# Vetor F/ tempo que é finalizado
    
vertices = g.vertices
visitado = {}
tempoVisita = {}
antecessor = {}
tempoFinal = {}
print("HelloWood2")
DFS(g, visitado, tempoVisita, antecessor, tempoFinal)
print("HelloWood9?")
auxiliar = g
auxiliar.arestas = g.transposta()
print("HelloWood1")
DFS_Alterado(auxiliar, visitado, tempoVisita, antecessor, tempoFinal)


print("HelloWood")
# Saida

for i in g.vertices:
    if (antecessor[i] == None):
        saida = str(i) + (", ")
    else:
        saida = str(i) + (": ")

print(saida)
