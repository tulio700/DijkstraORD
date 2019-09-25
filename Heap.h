#ifndef HEAP_H
#define HEAP_H
#include <list>
#include <queue>
#include <iostream>

using namespace std;

class Heap{
    private:
      int vertNum;
      list <pair<int,int> > *listaAdj;
    public:
      Heap();
      Heap(int n);
      void novaAresta(int vOrig,int vDest, int val);
      int dijkstra();

      int pai(int i);
      int esq(int i);
      int dir(int i);

      void printHeap();

      // void maxHeapify(int i);   //MAXIMO
      // void buildMaxHeap(int t);
      //
      // void minHeapify(int i);  //MINIMO
      // void buildMinHeap(int t);
      //
      // void heapSort();
      //
      // void freeVector(); //libera mallocs
      // void printVector(int pos);
      //
      // int getComprimento();
      // void setComprimento(int val);
};
#endif
