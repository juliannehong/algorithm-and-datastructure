// https://leetcode.com/problems/binary-tree-level-order-traversal/description/

#include "tree.h"
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> level_order(TreeNode* root){ 
  vector<vector<int>> result;
  queue<TreeNode*> q1, q2;
  if (root != nullptr)
    q1.push(root);
  while (!q1.empty() || !q2.empty()){
    vector<int> level;
    while(!q1.empty()){
      TreeNode* temp = q1.front();
      q1.pop();
      level.push_back(temp->val);
      if (temp->left != nullptr)
        q2.push(temp->left);
      if (temp->right != nullptr)
        q2.push(temp->right);
    }
    result.push_back(level);
    level.clear();
    while (!q2.empty()){
      TreeNode* temp = q2.front();
      q2.pop();
      level.push_back(temp->val);
      if(temp->left != nullptr)
        q1.push(temp->left);
      if(temp->right != nullptr)
        q1.push(temp->right);
    }

    result.push_back(level);
  }
  return result;
}

int main(){ 
  TreeNode* root = new TreeNode(4);
  root->left = new TreeNode(6);
  root->left->left = new TreeNode(9);
  root->left->left->left = new TreeNode(11);
  root->left->left->right = new TreeNode(10);
  root->left->right = new TreeNode(5);
  root->right = new TreeNode(7);
  root->right->left = new TreeNode(2);
  root->right->right = new TreeNode(8);

  vector<vector<int>> ans = level_order(root);
  for (auto v : ans){
    for (auto elem : v){
      cout << elem << " ";
    }
    cout << endl;
  }

  return 0;
}