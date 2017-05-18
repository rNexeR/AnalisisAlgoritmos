#include "Test.h"
#include <iostream>
using namespace std;

vector<int> heap_sort(std::vector<int> numbers){
  vector<int>heap;
  for(int i =0; i<numbers.size();i++){
    heap.push_back(numbers[i]);
    int j = heap.size()-1;
    while(j>0){
      int parent;
      if(j%2==0)
        parent = (j-2)/2;
      if(j%2!=0)
          parent = (j-1)/2;
      if(parent<0)
        break;
      if(heap[parent]>heap[j]){
        int aux = heap[parent];
        heap[parent] = heap[j];
        heap[j] = aux;
        j = parent;
      }else
        break;
    }
  }
  std::vector<int> ordered_numbers;
  while(heap.size() != 0) {
    ordered_numbers.push_back(heap[0]);
    heap[0] = heap[heap.size()-1];
    heap.pop_back();
    int i =0;
    while(i<heap.size()){
      int left = i*2+1;
      int right = i*2+2;
      if(right < heap.size()
        && heap[right] < heap[i]
        && heap[right] <= heap[left]
      )
      {
        int aux = heap[i];
        heap[i] = heap[right];
        heap[right] = aux;
        i=right;
      } else if(left < heap.size()
          && heap[left] < heap[i]
          && (right >=heap.size() || heap[left] <= heap[right])
      )
      {
        int aux = heap[i];
        heap[i] = heap[left];
        heap[left] = aux;
        i=left;
      }else{
        break;
      }
    }
  }
  std::cout << "hola" << '\n';
  for(int i =0; i<ordered_numbers.size();i++){
    std::cout << ordered_numbers[i] <<endl;
  }
  return ordered_numbers;
}

void  quickSort(std::vector<int> *numbers, int left, int right){
  int i = left, j = right;
  int tmp;
  int pivot = (*numbers)[(left + right) / 2];

  while(i<=j){
    while((*numbers)[i]<pivot)
      i++;
    while((*numbers)[j]>pivot)
      j--;

    if(i<=j){
      tmp = (*numbers)[i];
      (*numbers)[i] = (*numbers)[j];
      (*numbers)[j] = tmp;
      i++;j--;
    }
  }
  if(left < j){
    quickSort(numbers, left,j);
  }
  if(i < right)
    quickSort(numbers,i,right);
}
vector<int> sort(vector<int> numbers)
{
  quickSort(&numbers, 0, numbers.size()-1);
  return numbers;
}

int main ()
{
    test();
    return 0;
}
