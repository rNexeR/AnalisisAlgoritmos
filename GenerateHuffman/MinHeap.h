#include "Node.h"
#include <iostream>
using namespace std;

#define uint32 unsigned int

uint left_son(uint root)
{
  return (root * 2) + 1;
}

uint right_son(uint root)
{
  return left_son(root) + 1;
}

void insertOnHeap(std::vector<Node *> *v, Node *value)
{
  if (v->size() == 0)
  {
    v->push_back(value);
    return;
  }
  v->push_back(value);
  int j = v->size() - 1;

  int parent = (j % 2 == 0 ? (j - 2) / 2 : (j - 1) / 2);
  while (parent >= 0 && (*v)[parent]->frequency >= (*v)[j]->frequency)
  {
    Node *aux = (*v)[parent];
    (*v)[parent] = (*v)[j];
    (*v)[j] = aux;
    j = parent;
    parent = (j % 2 == 0 ? (j - 2) / 2 : (j - 1) / 2);
  }
}

void createHeap(std::vector<Node *> *v, vector<char> characters, vector<int> frequencies)
{
  for (uint32 i = 0; i < characters.size(); i++)
  {
    insertOnHeap(v, new Node(characters[i], frequencies[i]));
  }
}

Node *removeTopFromHeap(vector<Node *> *answer)
{

  Node *return_node = (*answer)[0];
  (*answer)[0] = (*answer)[answer->size() - 1];
  answer->pop_back();

  uint current = 0;
  while (current < answer->size())
  {
    uint lson = left_son(current);
    uint rson = right_son(current);
    if (lson < answer->size() && (*answer)[current]->frequency > (*answer)[lson]->frequency && (*answer)[lson]->frequency <= (*answer)[rson]->frequency)
    {
      Node *aux = (*answer)[current];
      (*answer)[current] = (*answer)[lson];
      (*answer)[lson] = aux;
      current = lson;
    }
    else if (rson < answer->size() && (*answer)[current]->frequency > (*answer)[rson]->frequency && (*answer)[rson]->frequency <= (*answer)[lson]->frequency)
    {
      Node *aux = (*answer)[current];
      (*answer)[current] = (*answer)[rson];
      (*answer)[rson] = aux;
      current = rson;
    }
    else
      break;
  }

  return return_node;
}