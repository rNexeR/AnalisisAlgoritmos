#include "Test.h"
#include <iostream>
using namespace std;

uint left_son(uint root){
    return (root*2)+1;
}

uint right_son(uint root){
    return (root*2)+2;
}

bool isMaxHeap(int* array, int root){
    if(array[left_son(root)] != -1){
        if(array[left_son(root)] <= array[root]){
            if(!isMaxHeap(array, left_son(root))){
                return false;
            }
        }else{
            return false;
        }
        
    }

    if(array[right_son(root)] != -1){
        if(array[right_son(root)] <= array[root]){
            if(!isMaxHeap(array, right_son(root))){
                return false;
            }
        }else{
            return false;
        }
        
    }

    return true;
}

bool isMaxHeap(int *array)
{
    return isMaxHeap(array, 0);
}

int main ()
{
    test();
    return 0;
}
