#include "Test.h"


void test()
{
    BinaryNode* n1 = new BinaryNode((char)NULL);
    BinaryNode* n2 = new BinaryNode((char)NULL);
    BinaryNode* na = new BinaryNode('a');
    BinaryNode* nb = new BinaryNode('b');
    BinaryNode* nc = new BinaryNode('c');

    n1->left = na;
    n1->right = n2;
    n2->left = nb;
    n2->right = nc;

    BinaryNode* nx1 = new BinaryNode((char)NULL);
    BinaryNode* nx2 = new BinaryNode((char)NULL);
    BinaryNode* nx3 = new BinaryNode((char)NULL);
    BinaryNode* nx4 = new BinaryNode((char)NULL);
    BinaryNode* nx5 = new BinaryNode((char)NULL);
    BinaryNode* nxm = new BinaryNode('m');
    BinaryNode* nxa = new BinaryNode('a');
    BinaryNode* nxr = new BinaryNode('r');
    BinaryNode* nxd = new BinaryNode('d');
    BinaryNode* nxo = new BinaryNode('o');
    BinaryNode* nxn = new BinaryNode('n');

    nx1->left = nx2;
    nx1->right = nx3;
    nx2->left = nxm;
    nx2->right = nxa;
    nx3->left = nx4;
    nx3->right = nx5;
    nx4->left = nxr;
    nx4->right = nxd;
    nx5->left = nxo;
    nx5->right = nxn;

    map<char,string> m = getHuffmanCodes(n1);

    if(getHuffmanCodes(n1)['a'] == "0"
        && getHuffmanCodes(n1)['b'] == "10"
        && getHuffmanCodes(n1)['c'] == "11"

       && getHuffmanCodes(nx1)['m'] == "00"
       && getHuffmanCodes(nx1)['a'] == "01"
       && getHuffmanCodes(nx1)['r'] == "100"
       && getHuffmanCodes(nx1)['d'] == "101"
       && getHuffmanCodes(nx1)['o'] == "110"
       && getHuffmanCodes(nx1)['n'] == "111"
       )
    {
        cout<<"Test: Pass"<<endl;
    }else
    {
        cout<<"Test: Fail"<<endl;
    }

}
