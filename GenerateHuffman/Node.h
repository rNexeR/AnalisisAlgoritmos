#include <iostream>
using namespace std;
class Node
{
public:
  char character;
  int frequency;
  Node *left;
  Node *right;

  Node()
  {
    this->character = (char)NULL;
    this->frequency = 0;
    this->left = NULL;
    this->right = NULL;
  }

  Node(char character, int frequency)
  {
    this->character = character;
    this->frequency = frequency;
    this->left = NULL;
    this->right = NULL;
  }
};