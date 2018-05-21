// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode (int n) : val(n), left(nullptr), right(nullptr) {}
};

int kth_smallest_element(TreeNode* root){
  stack<TreeNode*> st;
  TreeNode* current = root;
  int count = 1;
  while (!st.empty() || current != nullptr){
    if (current != nullptr){
      st.push(current);
      current = current->left;
    }
    else{
      current = st.top();
      st.pop();
      if (count == k)
        return current->val;
      else
        count++;
      current = current->right;
    }
  }
}