// https://leetcode.com/problems/toeplitz-matrix/description/
#include <iostream>
#include <vector>
using namespace std;

bool is_valid(const vector<vector<int>>& matrix, int r, int c){
  return (r >= 0 && r < matrix.size() && c >= 0 && c < matrix[0].size());
}

bool is_toeplitz_matrix(const vector<vector<int>>& matrix){
  int R = matrix.size(), C = matrix[0].size();
  for (int i = 0; i < R; i++){
    for (int j = 0; j < C; j++){
      if (is_valid(matrix, i + 1, j + 1)){
        if (matrix[i][j] != matrix[i+1][j+1])
          return false;
      }
    }
  }
  return true;
}