// Tree Treverse Summary (bst and non bst)
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode (int n) : val(n), left(nullptr), right(nullptr) {}
};

/* 
* inorder traverse *
* left->root->right; incrementally sorted with bst 
*/

// O(n); O(logn) ~ balanced, O(n) ~ skewed
void inorder_recursive(TreeNode* root){
  if (root == nullptr)
    return ;
  inorder_recursive(root->left);
  cout << root->val << " ";
  inorder_recursive(root->right);
}

// O(n); O(n)
void inorder_iterative(TreeNode* root){
  if (root == nullptr)
    return ;

  stack<TreeNode*> st;
  TreeNode* current = root;
  
  while (!st.empty() || current != nullptr){
    if (current != nullptr){
      st.push(current);
      current = current->left;
    }
    else{
      current = st.top();
      st.pop();
      cout << current->val << " ";
      current = current->right;
    }
  }
}

/* 
* preorder traverse *
* root->left->right; dfs 
*/

// O(n); O(logn) ~ balanced, O(n) ~ skewed
void preorder_recursive(TreeNode* root){
  if (root == nullptr)
    return ;
  cout << root->val << " "; // visit
  preorder_recursive(root->left);
  preorder_recursive(root->right);
}

// O(n); O(n)
void preorder_iterative(TreeNode* root){
  if (root == nullptr)
    return ;
  stack<TreeNode*> st;
  st.push(root);
  while (!st.empty()){
    TreeNode* current = st.top();
    st.pop();
    cout << current->val << " "; 
    if (current->right != nullptr) // push right first!!
      st.push(current->right);
    if (current->left != nullptr)
      st.push(current->left);
  }
}

/* 
* postorder traverse *
* left->right->root; 
*/

// O(n); O(logn) ~ balanced, O(n) ~ skewed
void postorder_recursive(TreeNode* root){
  if (root == nullptr)
    return ;
  postorder_recursive(root->left);
  postorder_recursive(root->right);
  cout << root->val << " ";
  }

// O(n); O(n)
void postorder_iterative(TreeNode* root){
  if (root == nullptr)
    return ;
  stack<TreeNode*> st;
  st.push(root);
  stack<int> values;

  while (!st.empty()){
    TreeNode* current = st.top();
    st.pop();
    values.push(current->val);
    if (current->left != nullptr)
      st.push(current->left);
    if (current->right != nullptr)
      st.push(current->right);
  }
  while (!values.empty()){
    cout << values.top() << " ";
    values.pop();
  }
}


void bfs_iterative_one_queue(TreeNode* root){ // can't track of the level
  if (root == nullptr)
    return ;
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()){
    TreeNode* current = q.front();
    q.pop();
    cout << current->val << " ";
    if (current->left != nullptr)
      q.push(current->left);
    if (current->right != nullptr)
      q.push(current->right);
  }
}

void bst_two_queues(TreeNode* root){ // can track of the level
  if (root == nullptr)
    return ;
  queue<TreeNode*> q1, q2;
  q1.push(root);
  while (!q1.empty() || !q2.empty()){
    while (!q1.empty()){
      TreeNode* temp = q1.front();
      q1.pop();
      cout << temp->val << endl;
      if (temp->left != nullptr)
        q2.push(temp->left);
      if (temp->right != nullptr)
        q2.push(temp->right);
    }
    
    while (!q2.empty()){
      TreeNode* temp = q2.front();
      q2.pop();
      cout << temp->val << endl;
      if (temp->left != nullptr)
        q1.push(temp->left);
      if (temp->right != nullptr)
        q1.push(temp->right);
    }
  }
}

int main(){
  TreeNode* non_bst_1 = new TreeNode(1);
  non_bst_1->left = new TreeNode(2);
  non_bst_1->left->left = new TreeNode(4);
  non_bst_1->right = new TreeNode(3);
  non_bst_1->right->left = new TreeNode(5);
  non_bst_1->right->right = new TreeNode(6);
  non_bst_1->right->left->left = new TreeNode(7);
  non_bst_1->right->left->right = new TreeNode(8);

  TreeNode* bst_1 = new TreeNode(8);
  bst_1->left = new TreeNode(3);
  bst_1->right = new TreeNode(10);
  bst_1->left->left = new TreeNode(1);
  bst_1->left->right = new TreeNode(6);
  bst_1->left->right->left = new TreeNode(4);
  bst_1->left->right->right = new TreeNode(7);
  bst_1->right->right = new TreeNode(14);
  bst_1->right->right->left = new TreeNode(13);

  inorder_recursive(non_bst_1);
  cout << endl;
  inorder_iterative(non_bst_1);
  cout << endl;
  preorder_recursive(non_bst_1);
  cout << endl;
  preorder_iterative(non_bst_1);
  cout << endl;
  postorder_recursive(non_bst_1);
  cout << endl;
  postorder_iterative(non_bst_1);
  cout << endl;
  bfs_iterative(non_bst_1);
  cout << endl;

  cout << "bst inorder traversal" << endl;
  inorder_iterative(bst_1);
  cout << endl;
  inorder_recursive(bst_1);
  cout << endl;
  return 0;
}