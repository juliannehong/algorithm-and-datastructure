// https://leetcode.com/problems/binary-tree-pruning/description/
#include <iostream>
#include "tree_debug.h"
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// solution1: O(n^2) the worst
bool all_are_zero(TreeNode* root){
  if (root == nullptr)
    return true;
  if (root->val == 1)
    return false;
  return all_are_zero(root->left) && all_are_zero(root->right);
}

TreeNode* prune_tree(TreeNode* root){
  if (root == nullptr) ;
  else if (root->val == 0 && all_are_zero(root))
    root = nullptr;
  else{
    root->left = prune_tree(root->left);
    root->right = prune_tree(root->right);
  }
  return root;
}

// solution2: O(n)
bool all_are_zero_improved(TreeNode* root){
  if (root == nullptr)
    return true;
  bool temp_left = all_are_zero_improved(root->left);
  bool temp_right = all_are_zero_improved(root->right);
  if (temp_left)
    root->left = nullptr;
  if (temp_right)
    root->right = nullptr;
  return root->val == 0 && temp_left && temp_right;
}

TreeNode* prune_tree_improved(TreeNode* root){
  all_are_zero_improved(root);
  return root;
}

int main(){
  TreeNode* t1 = new TreeNode(1);
  t1->right = new TreeNode(0);
  t1->right->left = new TreeNode(0);
  t1->right->right = new TreeNode(1);
  prune_tree_improved(t1);
  print_tree(t1);

  return 0;
}