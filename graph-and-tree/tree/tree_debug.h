#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> tree_to_vector(TreeNode* root){
  vector<int> res;
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()){
    TreeNode* temp = q.front();
    if (temp != nullptr){
      res.push_back(temp->val);
      q.push(temp->left);
      q.push(temp->right);
    }else{
      res.push_back(-1);
    }
    q.pop();
  }
  return res;
}

void print_vector(const vector<int>& v){
  for (auto elem : v)
    cout << elem << ", ";
}

void print_tree(TreeNode* root){
  print_vector(tree_to_vector(root));
}

