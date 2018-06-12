// https://leetcode.com/problems/unique-binary-search-trees-ii/description/
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode (int n) : val(n), left(nullptr), right(nullptr) {}
};

vector<TreeNode*> generate_trees_helper(int low, int up){
  vector<TreeNode*> result;
  if (low > up)
    result.push_back(nullptr);
  for (int i = low; i <= up; i++){
    vector<TreeNode*> left_subs = generate_trees_helper(low, i - 1);
    vector<TreeNode*> right_subs = generate_trees_helper(i + 1, up);
    for (auto left_s : left_subs){
      for (auto right_s : right_subs){
        TreeNode* root = new TreeNode(i);
        root->left = left_s;
        root->right = right_s;
        result.push_back(root);
      }
    }
  }
  return result;
}

vector<TreeNode*> generate_trees(int n){

  return generate_trees_helper(1, n);
}

int main(){
  auto trees = generate_trees(4);
  cout << trees.size() << endl;

  return 0;
}