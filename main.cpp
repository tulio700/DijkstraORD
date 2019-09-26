#include <iostream>
#include <stdlib.h>
#include <list>
#include <queue>
#include "Heap.h"

using namespace std;

int main(int argc, char* argv[]){
	//leitura do arquivo
  FILE *fp;
  fp = fopen("dij20.txt", "r");
  char line[1024];
  int v = 0;
  fgets(line, sizeof(line), fp); //captura primeira linha
  v = stoi(line); //numero de vertices
  printf("\n num vert: %d\n\n", v);
  Heap grafo(v);
  int numberArray[(v*v)/2];
  int j;
	//  criando os caminhos com as arestas
  for (j = 0; j < ((v*(v-1))/2); j++){
      fscanf(fp, "%d ", &numberArray[j] );
      //printf("Number is: %d\n\n", numberArray[j]);
  }
  int i = 0;
  j = 0;
  int aux = 0;
  int auxnum = 0;
  for(int i = 0; i<(v-1); i++){
    aux++;
    for(j=aux;j<v;j++){
      grafo.novaAresta(i,j,numberArray[auxnum]);
      printf("aresta add: %d , %d , %d\n", i,j,numberArray[auxnum]);
      auxnum++;
    }
  }

  cout << grafo.dijkstra() << endl;

  fclose(fp);
  return 0;
}
