#include <iostream>
#include <stdlib.h>
#include <list>
#include <queue>
#include "Heap.h"

using namespace std;

int main(int argc, char* argv[]){
  //int n = 5;
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
  
  // grafo.novaAresta(0, 1, 4);
  // grafo.novaAresta(0, 2, 2);
  // grafo.novaAresta(0, 3, 5);
  // grafo.novaAresta(1, 4, 1);
  // grafo.novaAresta(2, 1, 1);
  // grafo.novaAresta(2, 3, 2);
  // grafo.novaAresta(2, 4, 1);
  // grafo.novaAresta(3, 4, 1);

  cout << grafo.dijkstra() << endl;

  //teste.dijkstra(0,5);
  //jambo.setComprimento(22);
  //printf("%d", jambo.getComprimento());
  //jambo.printHeap();
  //jambo.maxHeapify(1);
  //jambo.buildMinHeap(n);
  //printf("Min heapify: ");
  //jambo.printHeap();
  //jambo.maxHeapify(5);
  //printf("Max heapify: ");
  //jambo.printHeap();
  //jambo.heapSort();
  //jambo.printHeap();
  //jambo.printVector(0);
  //printf("bumba meu boi\n");
  //jambo.freeVector();
  fclose(fp);
  return 0;
}
