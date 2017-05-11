#include "Test.h"
#include <iostream>
using namespace std;

uint left_son(uint root){
    return (root*2)+1;
}

uint right_son(uint root){
    return (root*2)+2;
}

uint parent_pos(uint root){
    if(root%2 == 0)
        return (root -2)/2;
    else
        return (root-1)/2;
}

vector<int> orderHeap(vector<int> min_heap, uint current_pos){
    while(current_pos >= 0 && current_pos < min_heap.size()){
        int current = min_heap[current_pos];
        uint parent = parent_pos(current_pos);
        uint left = left_son(current_pos);
        uint right = right_son(current_pos);

        cout<<current_pos<<" "<<parent<<" "<<left<<" "<<right<<endl;

        // if(parent  < 0 || left >= min_heap.size() || right >= min_heap.size())
        //     break;

        if( parent >= 0 && parent < min_heap.size() && current < min_heap[parent]){
            // int aux = current;
            min_heap[current_pos] = min_heap[parent];
            min_heap[parent] = current;
            current_pos = parent;
        }else if( left >= 0 && left < min_heap.size() && current > min_heap[left] ){
            min_heap[current_pos] = min_heap[left];
            min_heap[left] = current;
            current_pos = left;
        }else if( right >= 0 && right < min_heap.size() && current > min_heap[right] ){
            min_heap[current_pos] = min_heap[right];
            min_heap[right] = current;
            current_pos = right;
        }else
            break;
    }
    for(int i = 0; i < min_heap.size(); i++)
        cout<<"["<<i<<"] "<<min_heap[i]<<endl;
    cout<<endl<<endl;
    return min_heap;
}

vector<int> replace(vector<int> min_heap, int replaced_value, int replacement)
{
    cout<<"replace "<<replaced_value<<" with "<<replacement<<endl;
    for(uint i = 0; i < min_heap.size(); i++){
        if(min_heap[i] == replaced_value){
            min_heap[i] = replacement;
            cout<<"Replaced at pos "<<i<<endl;
            return orderHeap(min_heap, i);
        }
    }
    return min_heap;
}

int main ()
{
    test();
    return 0;
}
