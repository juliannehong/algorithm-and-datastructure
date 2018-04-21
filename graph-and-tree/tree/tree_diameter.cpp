// https://leetcode.com/problems/diameter-of-binary-tree/description/
#include <iostream>
#include <algorithm> //max
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x)  : val(x), left(nullptr), right(nullptr){}
};

int get_max_diameter(TreeNode* root, int& diameter){
  if (root == nullptr)
    return 0;
  int left_depth = get_max_diameter(root->left, diameter);
  int right_depth = get_max_diameter(root->right, diameter);
  diameter = max(diameter, left_depth + right_depth);
  return max(left_depth, right_depth) + 1;
}

int tree_diameter(TreeNode* root){
  int diameter = 0;
  get_max_diameter(root, diameter);
  return diameter;
}


//[1,2,3,4,5]
//[]
//[4]
int main(){
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  cout << tree_diameter(root) << endl;

  return 0;
}