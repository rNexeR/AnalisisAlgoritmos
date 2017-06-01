#include "Test.h"
#include <iostream>
using namespace std;

char decodeHuffman(string code, BinaryNode *tree, int *pos)
{

    if (code[*pos] == '0')
    {
        if (tree->left != 0)
        {
            (*pos)++;
            return decodeHuffman(code, tree->left, pos);
        }
        return tree->value;
    }
    else
    {
        if (tree->right != 0)
        {
            (*pos)++;
            return decodeHuffman(code, tree->right, pos);
        }
        return tree->value;
    }
}

string decodeHuffman(string code, BinaryNode *huffman_tree)
{
    string ret = "";

    int i = 0;
    for (i = 0; i < code.length(); )
        ret += decodeHuffman(code, huffman_tree, &i);

    cout << ret << endl;
    return ret;
}

int main()
{
    test();
    return 0;
}
