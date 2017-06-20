#include "Test.h"
#include <iostream>
#include <map>
using namespace std;

#define uint unsigned int 

uint left_son(uint index){
  return index*2 +1;
}

uint right_son(uint index){
    return left_son(index)+1;
}

bool exists(vector<int> avl_tree, int number)
{
  uint root = 0;
  while(root < avl_tree.size()){
    int current = avl_tree[root];
    if(current == number)
      return true;
    root = number > current ? right_son(root) : left_son(root);
  }
  return false;
}

BinaryNode* insertNode(vector<int>* max_heap, uint root_pos){
  BinaryNode* root = new BinaryNode((*max_heap)[root_pos]);
  uint lson = left_son(root_pos);
  uint rson = right_son(root_pos);

  uint correct_lson = lson;
  uint correct_rson = rson;

  if(lson < (*max_heap).size()){
    root->left_child = insertNode(max_heap, correct_lson);
  }

  if(rson < (*max_heap).size()){
    root->right_child = insertNode(max_heap, correct_rson);
  }

  return root;

}

BinaryNode* convertToLinkedTree(vector<int> max_heap)
{
  
  uint root_pos = 0;

  BinaryNode* root = insertNode(&max_heap, root_pos);

  return root;
}

int main ()
{
  test();
  return 0;
}
