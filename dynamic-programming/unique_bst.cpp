#include <iostream>
#include <vector>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

Node* copy_tree(Node* tree){
  return tree ? new Node{tree->data, copy_tree(tree->left), copy_tree(tree->right)} : nullptr;
}

vector<Node*> get_trees(int n){
  vector<Node*> re;
  // base case 
  if (n == 0)
    re.push_back(nullptr);

  for (int left_node = 0; left_node < n; ++left_node){
    int right_node = n - left_node;
    auto left_subtrees(get_trees(left_node));
    auto right_subtrees(get_trees(right_node));
    for (auto left_tree : left_subtrees){
      for (auto right_tree : right_subtrees){
        re.push_back(new Node{0, copy_tree(left_tree), copy_tree(right_tree)});
      }
    }
  }
  return re;
}
