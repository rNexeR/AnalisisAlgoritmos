#include "Test.h"
#include <iostream>
using namespace std;


void insertOnHeap(int *array,int heap_size, int value)
{
  int j;
  if(heap_size ==0){
    array[0] = value;
    j = 0;
    return;
  }else{
    j = heap_size;
    array[j] = value;
  }

  int parent = (j%2==0? (j-2)/2 : (j-1)/2);
  while(parent >=0 && array[parent]<array[j]){
    int aux = array[parent];
    array[parent] = array[j];
    array[j]= aux;
    j = parent;
    parent = (j%2==0? (j-2)/2 : (j-1)/2);
  }
}

int main ()
{
    test();
    return 0;
}
