#include <iostream>
#include <algorithm> //max
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;
  Node(int x):data(x), left(nullptr), right(nullptr){}
};

void printInOrder(Node* node){
  if (node == nullptr)
    return ;
  printInOrder(node->left);
  cout << node->data << " ";
  printInOrder(node->right);
  
}

Node* clone_tree(const Node*& original){
  return original ? new Node{original->data, clone_tree(original->left), clone_tree(original->right)} : nullptr;
}


void BFS (Node* root){
  queue<Node*> q;
  q.push(root);
  while (!q.empty()){
    auto current = q.front();
    cout << current->data << endl;
    q.pop();
    if(current->left)
      q.push(current->left);
    if (current->right)
      q.push(current->right);
  }
}

int main(){
  Node* root = new Node(8);
  root->left = new Node(3);
  root->left->left = new Node(1);
  root->left->right = new Node(6);
  root->left->right->left = new Node(4);
  root->left->right->right = new Node(7);
  root->right = new Node(10);
  root->right->right = new Node(14);
  root->right->right->left = new Node(13);
  
  printInOrder(root);
  
  return 0;
}
