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

int tree_max_depth(TreeNode* node){
  if (node == nullptr)
    return 0;
  return max(tree_max_depth(node->left), tree_max_depth(node->right)) + 1;
}

