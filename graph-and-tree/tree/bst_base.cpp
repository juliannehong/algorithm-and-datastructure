#include <iostream>
using namespace std;

vs

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

bool bst_insert(Node* root, int key){
  if (root == nullptr){
    root = new Node{key, nullptr, nullptr};
    return true;
  }
  Node* dummy = root;
  Node* parent = nullptr;
  while (dummy != nullptr){
    parent = dummy; // to keep track of dummy's parent
    if (key == dummy->data)
      return false;
    else if (key > dummy->data){
      dummy = dummy->right;
    }
    else{
      dummy = dummy->left;
    }
  }
  
  if (parent->data > key)
    parent->left = new Node{key, nullptr, nullptr};
  
  if (parent->data < key)
    parent->left = new Node{key, nullptr, nullptr};
  
  return true;
}

bool bst_delete(Node* root, int key){
  Node* del_parent = nullptr; // keep track of the parent node of to be deleted node
  Node* del_node = root; // pointer to the node that will be deleted
  while (del_node != nullptr && del_node->data != key){
    del_parent = del_node;
    del_node = (del_node->data > key) ? del_node->left : del_node->right;
  }
  if (del_node == nullptr)
    return false; // no corresponding key exists
  
  // now that we found node to be deleted, we will find node to be substitute
  
  // if the deleted node has right subtree, replace with the minimim key from right subtree
  if (del_node->right != nullptr){
    Node* sub = del_node->right;
    Node* sub_parent = del_node;
    while (sub->left != nullptr){ // remember why this isn't sub != nullptr;
      sub_parent = sub;
      sub = sub->left;
    }
    del_node->data = sub->data;
    if (sub_parent->right == sub){ // if sub didn't have any left subtree
      sub_parent->right = sub->right;
    }
    else{
      sub_parent->left = sub->right;
    }
  }
  
  // if the deleted node has NO right subtree, replace with
  else{
    if (del_node == root){
      root = root->left;
    }
    else{
      if (del_parent->right == del_node){
        del_parent->right = del_node->left;
      }
      else{
        del_parent->left = del_node->left;
      }
    }
  }
  return true;
}

void bst_print(Node* root){
  if (root == nullptr)
    return ;
  cout << root->data << endl;
  bst_print(root->left);
  bst_print(root->right);
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
  Node* root = new Node{2, nullptr};
  root->left = new Node{1, nullptr};
  root->right = new Node{3, nullptr};
  root->right->right = new Node{4, nullptr};
  
  bst_insert(root, 5);
  bst_print(root); // it doesn't print 5
  return 0;
}

