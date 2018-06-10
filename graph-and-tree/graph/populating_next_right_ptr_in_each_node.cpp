// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
#include <iostream>
#include <queue>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  Node* next;
  Node(int x): data(x), left(nullptr), right(nullptr), next(nullptr){}
};


void populate_next_right_ptr_in_each_node(Node* root){
  int level = 0;
  int nodes_at_level = 2 ^ level;
  queue<Node*> q;
  q.push(root);
  while (!q.empty()){
    auto current = q.front();
    q.pop();
    if (current->left != nullptr)
      q.push(current->left);
    if (current->right != nullptr)
      q.push(current->right);
    if (--nodes_at_level == 0){
      current->next = nullptr;
      nodes_at_level = 2 ^ (++level);
    }
    else{
      current->next = q.front();
      nodes_at_level--;
    }
  }
}

int main(){
  Node* root = new Node(2);
  root->left = new Node(1);
  root->right = new Node(3);
  root->right->left = new Node(9);
  root->right->right = new Node(10);
  root->left->left = new Node(5);
  root->left->right = new Node(6);
  populate_next_right_ptr_in_each_node(root);
  
  cout << root->left->next->data << endl; // 3
  cout << root->left->left->next->data << endl; // 6
  cout << root->left->right->next->data << endl; //9
  cout << root->left->left->next->next->next->data << endl; //10
  return 0;
}
