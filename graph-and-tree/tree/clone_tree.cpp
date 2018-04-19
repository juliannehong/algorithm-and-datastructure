// tree copy
#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
}

Node* clone_tree(const Node*& original){
  return original ? new Node{original->data, clone_tree(original->left), clone_tree(original->right)} : nullptr;
}