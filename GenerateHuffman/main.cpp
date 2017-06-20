#include "Test.h"
#include "MinHeap.h"
#include <iostream>
using namespace std;



void createHuffmanTree(std::vector<Node *> *v)
{
  while (v->size() > 1)
  {
    Node *left = removeTopFromHeap(v);
    Node *right = removeTopFromHeap(v);

    Node *top = new Node('$', left->frequency + right->frequency);
    top->left = left;
    top->right = right;
    insertOnHeap(v, top);
  }
}

void createTable(Node *current_node, string code, map<char, string> *codes)
{
  if (!current_node)
    return;

  if (current_node->character != '$')
  {
    (*codes)[current_node->character] = code;
  }

  createTable(current_node->left, code + "0", codes);
  createTable(current_node->right, code + "1", codes);
}

map<char, string> getHuffman(vector<char> characters, vector<int> frequencies)
{
  vector<Node *> min_heap;
  createHeap(&min_heap, characters, frequencies);

  createHuffmanTree(&min_heap);

  map<char, string> answer2;

  createTable(min_heap[0], "", &answer2);

  return answer2;
}

int main()
{
  test();
  return 0;
}
