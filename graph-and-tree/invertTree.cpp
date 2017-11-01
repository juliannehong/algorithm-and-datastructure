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

TreeNode* invertTree(TreeNode* node){
  // basecase
  if (node == nullptr)
    return nullptr;
  TreeNode* newNode = new TreeNode(node->val);
  newNode->left = invertTree(node->right);
  newNode->right = invertTree(node->left);
  return newNode;
}

