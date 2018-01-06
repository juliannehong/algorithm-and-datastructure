// https://leetcode.com/problems/validate-binary-search-tree/description/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool is_valid_BST(TreeNode* root) {
  if (root == nullptr)
    return true;
  if (root->left == nullptr || root->right == nullptr)
    return true;
  else if (root->val > root->left->val && root->val < root->right->val){
    return (is_valid_BST(root->left) && is_valid_BST(root->right));
  }
  else{
    return false;
  }
}

int main(){
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->right = new TreeNode(6);
  root->right->right = new TreeNode(7);
  
  cout << is_valid_BST(root) << endl;
  
  return 0;
}