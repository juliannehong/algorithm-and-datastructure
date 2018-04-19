//https://leetcode.com/problems/symmetric-tree/description/
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* right;
  TreeNode* left;
  TreeNode(int x) : val(x), right(nullptr), left(nullptr) {}
};

bool is_mirror(TreeNode* root1, TreeNode* root2) {
  if (root1 == nullptr && root2 == nullptr)
    return true;
  if (root1 == nullptr || root2 == nullptr)
    return false;
  return (root1->val == root2->val && is_mirror(root1->right, root2->left) && is_mirror(root1->left, root2->right));
}

bool is_symmetric_recursion(TreeNode* root) {
  return is_mirror(root, root);
}

bool is_symmetric_iteration(TreeNode* root) {
  queue<TreeNode*> q;
  q.push(root);
  q.push(root);
  while (!q.empty()) {
    TreeNode* n1 = q.front();
    q.pop();
    TreeNode* n2 = q.front();
    q.pop();
    if (n1 == nullptr && n2 == nullptr)
      continue;
    else if (n1 == nullptr || n2 == nullptr)
      return false;
    else {
      if (n1->val != n2->val)
        return false;
      q.push(n1->left);
      q.push(n2->right);
      q.push(n1->right);
      q.push(n2->left);
    }
  }
  return true;
}

int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(3);

  cout << is_symmetric_iteration(root) << endl;
  cout << is_symmetric_recursion(root) << endl;

  return 0;
}
