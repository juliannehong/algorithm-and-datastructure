#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

Node* bst_search(Node* root, int key){
  if (root->data == key || root == nullptr)
    return root;
  else{
    if (root->data > key)
      return bst_search(root->left, key);
    else
      return bst_search(root->right, key);
  }
}

void bst_insert(Node* root, int key){
  Node* dummy = root;
  while (dummy != nullptr){
    dummy = (key < dummy->data) ? dummy->left : dummy->right;
    if (dummy != nullptr)
      cout << dummy->data << endl;
  }
  dummy = new Node {key, nullptr, nullptr}; // can i not do this?
}

void bst_print(Node* root){
  if (root == nullptr)
    return ;
  cout << root->data << endl;
  bst_print(root->left);
  bst_print(root->right);
}

int main(){
  Node* root = new Node{2, nullptr};
  root->left = new Node{1, nullptr};
  root->right = new Node{3, nullptr};
  root->right->right = new Node{4, nullptr};
  
  bst_insert(root, 5);
  bst_print(root); // it doesn't print 5
  return 0;
}

