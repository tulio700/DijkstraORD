#include "Heap.h"
#include <iostream>
#include <list>
#include <queue>

using namespace std;

Heap::Heap(){}

Heap::Heap(int n){
    vertNum = n;
    listaAdj = new list<pair <int,int> > [n];  //lista de adjacencias
}

void Heap::novaAresta(int vOrig,int vDest, int val){ //push nos valores do txt
    listaAdj[vOrig].push_back(make_pair(vDest, val));
}

int Heap::dijkstra(){
  int inicio = 0;
  int fim = (vertNum-1);
  priority_queue < pair<int, int>,vector<pair<int, int> >, greater<pair<int, int> > > fila; //fila de prioridade minima

  int distancia[vertNum];
  int visitado[vertNum];

  //printf("test1\n");
  for(int i = 0; i < vertNum; i++) {
  		distancia[i] = 5000000;
     	visitado[i] = 0; // 0 = nao visitado e 1 = visitado
	}
  //printf("test1\n");
  distancia[inicio] = 0;

  fila.push(make_pair(distancia[inicio], inicio));

  while(1){
    pair<int,int> p = fila.top();
    int u = p.second; //pega o vertice
    fila.pop();

    if(visitado[u] == 0){

        visitado[u] == 1;

        list<pair<int, int> >::iterator it;

        for(it = listaAdj[u].begin();it != listaAdj[u].end(); it++){
            int indice = (*it).first;
            int valAresta = (*it).second;

            //RELAX
            if(distancia[indice]>(distancia[u] + valAresta)){
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

// int Heap::pai(int i){
//   return (i-1)/2;
// }
//
// int Heap::esq(int i){
//   return 2*i+1;
// }
//
// int Heap::dir(int i){
//   return 2*i+2;
// }
//
// void Heap::maxHeapify(int i){
//     int maior = i;
//     int aux = 0;
//
//     int l = esq(i);
//     int r = dir(i);
//     //printf("L: %d , R: %d \n", v[l],v[r]);
//
//     if((l < tamanho) && (v[l] > v[i])){
//       maior = l;
//     }else{
//       maior = i;
//     }
//     if((r < tamanho) && (v[r] > v[maior])){
//       maior = r;
//     }
//
//     if(maior != i){
//       //printf("entrei i:%d, maior:%d\n", v[i],v[maior]);
//       aux = v[i];
//       v[i] = v[maior];
//       v[maior] = aux;
//       maxHeapify(maior);
//     }
// }
//
// void Heap::buildMaxHeap(int t)
// {
//   int i;
// 	for(i = t/2; i>=0; --i)
//   {
//     //printf("ASDASD: %d \n", i);
// 		maxHeapify(i);
// 	}
// }
//
// void Heap::minHeapify(int i){
//     int menor = i;
//     int aux = 0;
//
//     int l = esq(i);
//     int r = dir(i);
//     //printf("L: %d , R: %d \n", v[l],v[r]);
//
//     if((l < tamanho) && (v[l] < v[i])){
//       menor = l;
//     }else{
//       menor = i;
//     }
//     if((r < tamanho) && (v[r] < v[menor])){
//       menor = r;
//     }
//
//     if(menor != i){
//       //printHeap();
//       //printf("entrei i:%d, menor:%d\n", v[i],v[menor]);
//       aux = v[i];
//       v[i] = v[menor];
//       v[menor] = aux;
//       minHeapify(menor);
//     }
// }
//
// void Heap::buildMinHeap(int t)
// {
//   int i;
// 	for(i = t/2; i>=0; --i)
//   {
//     //printf("ASDASD: %d \n", i);
// 		minHeapify(i);
// 	}
// }
//
// void Heap::heapSort(){
//     buildMaxHeap(tamanho);
//
//     for(int i = (comprimento-1);i >= 0;--i){
//         //printf("SORTSORT: %d e %d  \n", v[0],v[i]);
//         int aux = v[0];
//         v[0] = v[i];
//         v[i] = aux;
//         tamanho -= 1;
//         maxHeapify(0);
//     }
// }
//
// void Heap::printHeap(){
//   for(int i = 0; i < comprimento;i++){
//       printf("%d ", v[i]);
//   }
//   printf("\n");
// }
//
// void Heap::printVector(int pos){
//   printf("%d \n", v[pos]);
// }
//
// int Heap::getComprimento(){
//
//     return comprimento;
// }
//
// void Heap::setComprimento(int val){
//     comprimento = val;
// }
//
// void Heap::freeVector(){
//       free(v);
// }
