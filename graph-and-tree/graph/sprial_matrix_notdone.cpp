// https://leetcode.com/problems/spiral-matrix/description/
#include <vector>
#include <iostream>
using namespace std;

vector<int> spiral_matrix(const vector<vector<int>>& matrix){
  vector<int> result;
  int r_total = matrix.size() - 1, c_total = matrix[0].size();
  int r = 0, c = 0;
  result.push_back(matrix[r][c]);
  while (r_total != 0 || c_total != 0){
    // go right
    for (int i = 0; i < c_total; i++){
      result.push_back(matrix[r][++c]);
    }
    c_total--;
    // go down
    for (int j = 0; j < r_total; j++){
      result.push_back(matrix[++r][c]);
    }
    r_total--;
    // go left
    for (int i = 0; i < c_total; i++){
      result.push_back(matrix[r][--c]);
    }
    c_total--;
    // go up
    for (int j = 0; j < r_total; j++){
      result.push_back(matrix[++r][c]);
    }
    r_total--;
  }
  return result;
}

int main(){
  vector<vector<int>> mat {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };
  vector<int> ans = spiral_matrix(mat);
  for (auto elem : ans){
    cout << elem << endl;
  }
  return 0;
}