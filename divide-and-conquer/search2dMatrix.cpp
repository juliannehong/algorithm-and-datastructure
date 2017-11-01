// https://leetcode.com/problems/search-a-2d-matrix-ii/description/
// this solution doesn't work!!!!

#include <iostream>
#include <vector>

using namespace std;

bool findRecursive(const vector<vector<int>>& mat, int r_begin, int r_end, int c_begin, int c_end, int num){
  if (mat.empty() || r_begin > r_end || c_begin > c_end)
    return false;
  int mid_r = (r_begin + r_end) / 2;
  int mid_c = (c_begin + c_end) / 2;
  // if mat[mid_r][mid_c] > num --> search mat[0:mid_r][0:mid_c]
  // else --> search mat[mid_r:][mid_c:]
  if (mat[mid_r][mid_c] == num)
    return true;
  else if (mat[mid_r][mid_c] > num)
    return findRecursive(mat, 0, mid_r-1, 0, mid_c-1, num);
  else
    return findRecursive(mat, mid_r+1, int(mat.size()-1), mid_c+1, int(mat[0].size()-1), num);
}

bool searchMatrix(vector<vector<int>>& matrix, int target){
  if (matrix.empty())
    return false;
  return findRecursive(matrix, 0, int(matrix.size()-1), 0, int(matrix[0].size()-1), target);
}

int main(){
  
  vector<vector<int>> mat {
    {1,4,7,11,15},
    {1,5,8,12,19},
    {3,6,9,16,22},
    {10,13,14,17,24},
    {18,21,23,26,30}
  };
  cout << searchMatrix(mat, 13) << endl;
  
  return 0;
}
