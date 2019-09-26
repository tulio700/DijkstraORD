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

};
#endif
