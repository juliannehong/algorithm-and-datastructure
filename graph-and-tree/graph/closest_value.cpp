// https://leetcode.com/problems/closest-binary-search-tree-value/description/
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

double get_gap(int val, double target){
  return abs(target - val);
}

int closest_value(TreeNode* root, double target) {
  if (root->val > target){ // it's func(root->left) vs. root->val
    if (root->left != nullptr && get_gap(root->val, target) > get_gap(root->left->val, target)){
      return closest_value(root->left, target);
    }
  }
  
  if (root->val < target){ // it's func(root->left) vs. root->val
    if (root->right != nullptr && get_gap(root->val, target) > get_gap(root->right->val, target)){
      return closest_value(root->right, target);
    }
  }
  return root->val;
}


int main(){
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->right = new TreeNode(6);
  root->right->right = new TreeNode(7);
  
  cout << closest_value(root, 6.2) << endl;
  
  return 0;
}
