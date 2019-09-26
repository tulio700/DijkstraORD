#include "Heap.h"
#include <iostream>
#include <list>
#include <queue>

using namespace std;

Heap::Heap(){}

Heap::Heap(int n){
    vertNum = n; //número de vértices
    listaAdj = new list<pair <int,int> > [n];  //lista de adjacencias
}
	//adiciona uma aresta oa grafo de vOrig à VDest (val = custo)
void Heap::novaAresta(int vOrig,int vDest, int val){ //push nos valores do txt
    listaAdj[vOrig].push_back(make_pair(vDest, val));
}
 //algoritmo de dijkstra
int Heap::dijkstra(){
  int inicio = 0;
  int fim = (vertNum-1);
	//fila de prioridade minima, o primeiro elemento do par é a distancia e o segundo o vértice
  priority_queue < pair<int, int>,vector<pair<int, int> >, greater<pair<int, int> > > fila;

	//vetor de distâncias
  int distancia[vertNum];
	// vetor de visitados serve para caso o vértice já tenha sido expandido (visitado), não expandir mais
  int visitado[vertNum];

  //printf("test1\n");
	// inicia o vetor de distâncias e visitados
  for(int i = 0; i < vertNum; i++) {
  		distancia[i] = 5000000;
     	visitado[i] = 0; // 0 = nao visitado e 1 = visitado
	}
  //printf("test1\n");
  distancia[inicio] = 0;
	// insere na fila
  fila.push(make_pair(distancia[inicio], inicio));
	//loop do algoritmo
  while(1){
    pair<int,int> p = fila.top();// extrai o pair do topo
    int u = p.second;  // obtém o vértice do pair
    fila.pop(); // remove da fila

    if(visitado[u] == 0){
	//marca como visitado
        visitado[u] == 1;
	// percorre a lista dos adjacentes do objeto
        list<pair<int, int> >::iterator it;
	// percorre os vértices "v" (indice) adjacentes de "u"
        for(it = listaAdj[u].begin();it != listaAdj[u].end(); it++){
            int indice = (*it).first;
            int valAresta = (*it).second;

            // relaxamento (u, v) (verificação se a distancia do indice v é maior que a soma da distancia de u + o custo da aresta)
	// atualiza a distancia do indice v e insere na fila
              distancia[indice] = distancia[u] + valAresta;
              fila.push(make_pair(distancia[indice],indice));
            }
        }
    }
    if(fila.empty()){
      break;
    }
  }
  return distancia[fim];
}
