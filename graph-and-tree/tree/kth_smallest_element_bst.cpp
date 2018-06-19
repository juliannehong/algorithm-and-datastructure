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


void inorder(TreeNode* root, int k, int& count, int& val){
  if (root == nullptr)
    return ;

  inorder(root->left, k, count, val);
    if (++count == k){
    val = root->val;
    return ;
  }
  inorder(root->right, k, count, val); 
}

int kthSmallest(TreeNode* root, int k){
  int count = 0;
  int val = INT_MAX;
  inorder(root, k, count, val);
  return val;
}

int main(){
  TreeNode* t1 = new TreeNode(3);
  t1->left = new TreeNode(1);
  t1->left->right = new TreeNode(2);
  t1->right = new TreeNode(4);
  cout << kthSmallest(t1, 1) << endl;

  TreeNode* t2 = new TreeNode(5);
  t2->left = new TreeNode(3);
  t2->left->left = new TreeNode(2);
  t2->left->right = new TreeNode(4);
  t2->left->left->left = new TreeNode(1);
  t2->right = new TreeNode(6);

  cout << kthSmallest(t2, 3) << endl;
  return 0;
}