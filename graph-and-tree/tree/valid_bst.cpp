// https://leetcode.com/problems/validate-binary-search-tree/description/
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool valid_bst_helper(TreeNode* root, int min, int max){
  if (root == nullptr)
    return true;
  
  if (root->val < max && root->val > min)
    return valid_bst_helper(root->left, min, root->val) && valid_bst_helper(root->right, root->val, max);
  else
    return false;
}

bool valid_bst(TreeNode* root){
  return valid_bst_helper(root, INT_MIN, INT_MAX);
}
