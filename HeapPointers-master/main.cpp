#include "Test.h"
#include <iostream>
using namespace std;

bool isMaxHeap(BinaryTreeNode* root)
{
    if(root->left){
        if(root->left->value <= root->value){
            if(!isMaxHeap(root->left)){
                return false;
            }
        }else{
            return false;
        }
        
    }

    if(root->right){
        if(root->right->value <= root->value){
            if(!isMaxHeap(root->right)){
                return false;
            }
        }else{
            return false;
        }
        
    }

    return true;
}

int main ()
{
    test();
    return 0;
}
