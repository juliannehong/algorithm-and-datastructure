// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
#include <iostream>
#include <algorithm> //max
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x)  : val(x), left(nullptr), right(nullptr){}
};

int maxDepth(TreeNode* node){
  // basecase
  if (node == nullptr)
    return 0;
  return max(maxDepth(node->left), maxDepth(node->right)) + 1;
}

