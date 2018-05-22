//https://leetcode.com/problems/search-a-2d-matrix/description/
#include <iostream>
#include <vector>
using namespace std;

bool searchRecursive(vector<vector<int>>& matrix, int begin, int end, int target){
  if (begin > end)
    return false;
  int mid = (begin + end) / 2;
  //  matrix[mid/C][mid%c];
  int R = matrix.size();
  int C = matrix[0].size();
  int r_ = mid / C;
  int c_ = mid % C;
  
  if (matrix[r_][c_] == target)
    return true;
  else if (matrix[r_][c_] < target)
    return searchRecursive(matrix, mid + 1, end, target);
  else
    return searchRecursive(matrix, begin, mid - 1, target);
  
  return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
  int R = matrix.size();
  int C = matrix[0].size();
  int end = R*C-1;
  return searchRecursive(matrix, 0, end, target);
}

int main(){
  vector<vector<int>> v{
    {1,   3,  5,  7},
    {10, 11, 16, 20},
    {23, 30, 34, 50}
  };
  cout << searchMatrix(v, 34) << endl;
  
  return 0;
}
