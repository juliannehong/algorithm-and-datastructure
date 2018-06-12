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
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* convert_vector_to_tree(const vector<int>& v){
  
  queue<TreeNode*> q;
  if (v[0] == 0)
    return nullptr;
  TreeNode* root = new TreeNode(v[0]);
  TreeNode* dummy = root;
  q.push(dummy);
  int it = 1;
  while (!q.empty() && it < v.size()){
    dummy = q.front();
    q.pop();
    if (v[it] != 0){
      dummy->left = new TreeNode(v[it++]);
      q.push(dummy->left);
    }

    if (v[it] != 0){
      dummy->right = new TreeNode(v[it++]);
      q.push(dummy->right);
    }
  }
  return root;
}


void print_tree(TreeNode* root){
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()){
    TreeNode* temp = q.front();
    q.pop();
    cout << temp->val << " ";
    if (temp->left != nullptr)
      q.push(temp->left);
    if (temp->right != nullptr)
      q.push(temp->right);
  }
}