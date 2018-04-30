// https://leetcode.com/problems/toeplitz-matrix/description/
#include <iostream>
#include <vector>
using namespace std;

bool is_valid(const int r, const int c, int i, int j){
  return (i >= 0 && j >= 0 && i < r && j < c);
}

bool is_toeplitz_matrix(vector<vector<int>>& matrix){
  const int R = matrix.size(), C = matrix[0].size();
  for (int i = 0; i < R; i++){
    for (int j = 0; j < C; j++){
      if (is_valid(R,C,i,j) && is_valid(R,C,i+1,j+1)){
        if (matrix[i][j] != matrix[i+1][j+1])
          return false;
      }
    }
  }
  return true;
}

int main(){
  vector<vector<int>> matrix1{
    {1,2,3,4},
    {5,1,2,3},
    {9,5,1,2},
    {4,9,5,1}
  };
  vector<vector<int>> matrix2{
    {1,2},
    {2,2}
  };
  cout << is_toeplitz_matrix(matrix1) << endl;
  return 0;
}