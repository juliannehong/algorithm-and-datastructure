// https://leetcode.com/problems/same-tree/description/
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void tree_to_vector(TreeNode* t, vector<int>& tree_vector){
  //auto tree_vector = *tree_vector_ptr;
  if (t == nullptr){
    tree_vector.push_back(NULL);
    return ;
  }
  tree_vector.push_back(t->val);
  tree_to_vector(t->left, tree_vector);
  tree_to_vector(t->right, tree_vector);
}

bool is_same_tree(TreeNode* p, TreeNode* q){
  vector<int> p_vector;
  vector<int> q_vector;
  tree_to_vector(p, p_vector);
  tree_to_vector(q, q_vector);
  return p_vector == q_vector;
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


