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

    if(decodeHuffman("001011",n1) == "aabc"
       && decodeHuffman("110101111",n1) == "cabcc"
       && decodeHuffman("11",n1) == "c"
       && decodeHuffman("",n1) == ""

       && decodeHuffman("101100110111",nx1) == "dron"
       && decodeHuffman("1000111101",nx1) == "rana"
       && decodeHuffman("00011000110111011101",nx1) == "maradona"
       && decodeHuffman("000110001",nx1) == "mara"
       && decodeHuffman("0001100",nx1) == "mar"
       )
    {
        cout<<"Test: Pass"<<endl;
    }else
    {
        cout<<"Test: Fail"<<endl;
    }

}
