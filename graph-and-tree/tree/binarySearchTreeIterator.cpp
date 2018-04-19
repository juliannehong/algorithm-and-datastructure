// still confusing!!
// https://leetcode.com/problems/binary-search-tree-iterator/description/
#include <iostream>
#include <stack>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;
  Node(int x):data(x), left(nullptr), right(nullptr){}
};

class BSTIterator {
  stack<Node*> stack;
public:
  BSTIterator(Node *root) {
    left_nodes(root);
  }
  
  /** @return whether we have a next smallest number */
  bool hasNext() {
    return !stack.empty();
  }
  
  /** @return the next smallest number */
  int next() {
    Node* top = stack.top();
    if (top->right != nullptr)
      left_nodes(top->right)
      
      return top->data;
  }
  
  void left_nodes(Node* root){
    if (root == nullptr)
      return ;
    stack.push(root);
    left_nodes(root->left);
    
  }
};
