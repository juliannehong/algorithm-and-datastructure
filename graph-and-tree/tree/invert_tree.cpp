// https://leetcode.com/problems/invert-binary-tree/description/
#include <iostream>
#include <algorithm> //max
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x)  : val(x), left(nullptr), right(nullptr){}
};

TreeNode* invert_tree(TreeNode* node){
  // basecase
  if (node == nullptr)
    return nullptr;
  TreeNode* temp = node->left;
  node->left = invert_tree(node->right);
  node->right = invert_tree(temp);
  return node;
}


