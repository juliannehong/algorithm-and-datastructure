#include <iostream>
#include <vector>
using namespace std;

int num_tree_helper(int root, vector<bool>& visited){
  visited[root] = true;
  int left_subtree = 0, right_subtree = 0;
  // left
  for (int left = 0; left < root; ++left){
    if (!visited[left])
      left_subtree += num_tree_helper(left, visited);
  }
  // right
  for (int right = root + 1; right < visited.size(); ++right){
    if (!visited[right])
      right_subtree += num_tree_helper(right, visited);
  }
  cout << "root is " << root << " and the subtree count is " << 1+right_subtree + left_subtree << endl;
  return 1 + right_subtree + left_subtree;
}

int num_tree(int n){
  int re = 0;
  for (int i = 0; i < n; ++i){
    cout << "----- root " << i << "------" << endl; 
    vector<bool> visited(n, false);
    re += num_tree_helper(i, visited);
    cout << "----- new tree -----" << endl;
  }
  return re;
}

int main(){
  cout << num_tree(3) << endl;
  
  return 0;
}
