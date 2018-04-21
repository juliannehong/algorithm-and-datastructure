// https://leetcode.com/problems/same-tree/description/
#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


bool is_same_tree(TreeNode* r1, TreeNode* r2){
  if (r1 == nullptr && r2 == nullptr)
    return true;
  if (r1 == nullptr || r2 == nullptr)
    return false;
  return (r1->val == r2->val && is_same_tree(r1->left, r2->left) && is_same_tree(r1->right, r2->right));
}

int main(){
  TreeNode* p = new TreeNode(1);
  p->left = new TreeNode(2);
  p->right = new TreeNode(3);
  p->right->left = new TreeNode(4);
  
  TreeNode* q = new TreeNode(1);
  q->left = new TreeNode(2);
  q->right = new TreeNode(3);
  q->right->right = new TreeNode(4);
  cout << is_same_tree(p, q) << endl;
  
  return 0;
}


