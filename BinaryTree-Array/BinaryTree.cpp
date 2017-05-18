#include <iostream>
using namespace std;

void insert_on(int * binArray, int size, int value, int index )
{
  if(binArray[index]==-1){
    binArray[index]=value;
    return;
  }
  int current = binArray[index];
  int left = index *2 + 1;
  int right = index *2 + 2;
  if(value<current && left < size){
    insert_on(binArray, size,value, left);
  }else{
    if(right < size)
      insert_on(binArray, size,value, right);
  }
}
void insert(int* binArray,int size, int value){
  if(binArray[0]==-1){
    binArray[0]=value;
    return;
  }

  int root = 0;
  int current =  binArray[root];
  int left = root *2 + 1;
  int right = root *2 + 2;
  if(value<current){
    insert_on(binArray, size, value, left);
  }else{
    insert_on(binArray, size, value, right);
  }
}
void printArray(int * array, int size, int pos, int tab){
  int left = pos *2 + 1;
  int right = pos *2 + 2;
  if(left<size &&array[left]!=-1)
    printArray(array,size,left,tab+1);

  if(array[pos] != -1){
    for(int i = 0; i< tab;i++){
      cout<<' ';
    }
    cout<<array[pos]<<endl;
  }
  if(right<size &&array[right]!=-1)
    printArray(array,size,right,tab+1);
}

int find_min_pos(int * array, int size, int index){
  int left = (index *2) +1;
  while(left< size && array[left]!= -1){
    left = (left *2) +1;
  }
  int parent = (left-1) /2;
  return parent;
}
int find_max_pos(int * array, int size, int index){
  int right = (index *2) +2;
  while(right< size && array[right]!= -1){
    right = (right *2) +2;
  }
  int parent = (right-2) /2;
  return parent;
}
int search(int * array, int size, int value, int index){
  int current = array[index];
  if(current == value)
    return index;
  if(value < current){
    int left = index *2 +1;
    if(left<size)
      return search(array, size,value, left);
    return -1;
  }else{
    int right = index *2 +2;
    if(right<size)
      return search(array, size,value, right);
    return -1;
  }
  return -1;
}

void remove(int * array, int size,int value){
  int index_value = search(array,size,value,0);
  if(index_value==-1)
    return;
  
  int left = index_value *2 +1;
  int right = index_value *2 +2;
  
  if((left < size && array[left]==-1) && (right < size && array[right]==-1) )
    array[index_value]=-1;
  else{
    if(left<size && array[left]!=-1){
      int index_child = find_max_pos(array,size,left);
      int child_value = array[index_child];
      remove(array,size,array[index_child]);
      array[index_value]= child_value;
    }else{
      int index_child = find_min_pos(array,size, right);
      int child_value = array[index_child];
      remove(array,size,child_value);
      array[index_value]=child_value;
    }
  }
}
int main(void *args[]){
  cout<<"hola"<<endl;
  int size =100;
  int binArray[size];
  for(int i =0; i<size;i++){
    binArray[i]=-1;
  }
  insert(binArray,size,10);
  insert(binArray,size,5);
  insert(binArray,size,15);
  insert(binArray,size,18);
  insert(binArray,size,8);
  insert(binArray,size,6);
  insert(binArray,size,7);
  printArray(binArray,size,0,0);
  cout<<"---------------"<<endl;
  /*int index = search(binArray, size, 8,0);
  cout<<"8 "<<binArray[index]<<" "<<index<<endl;
  index = search(binArray, size, 10,0);
 cout<<"10 "<<binArray[index]<<" "<<index<<endl;
   index = search(binArray, size, 5,0);
  cout<<"5 "<<binArray[index]<<" "<<index<<endl;
   index = search(binArray, size, 3,0);
  cout<<"3 "<<binArray[index]<<" "<<index<<endl;
  index = find_min_pos(binArray,size,0);
  cout<<"index "<<index<<endl;
  cout<<"min 0: "<<binArray[index]<<endl;
  index = find_max_pos(binArray,size,0);
  cout<<"index "<<index<<endl;
  cout<<"max 0: "<<binArray[index]<<endl;
*/
  remove(binArray,size, 5);
  printArray(binArray,size,0,0);
  
  return 0;
}
