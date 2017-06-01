#include "Test.h"
#include <iostream>
using namespace std;

void getHuffmanCodes(BinaryNode *tree, map<char, string> *answer, string current)
{

    if (tree->left != 0)
    {
        getHuffmanCodes(tree->left, answer, current + '0');
    }else{
        (*answer)[tree->value] = current;
    }

    if (tree->right != 0)
    {
        getHuffmanCodes(tree->right, answer, current + '1');
    }else{
        (*answer)[tree->value] = current;
    }
    
}

map<char, string> getHuffmanCodes(BinaryNode *huffman_tree)
{
    map<char, string> answer;
    getHuffmanCodes(huffman_tree, &answer, "");

    // for(map<char, string>::iterator i = answer.begin(); i != answer.end(); i++){
    //     cout<<"["<<(*i).first<<"]="<<(*i).second<<endl;
    // }

    // cout<<endl<<endl;

    return answer;
}

int main()
{
    test();
    return 0;
}
