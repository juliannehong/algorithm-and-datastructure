// https://leetcode.com/problems/spiral-matrix/description/
#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix){
  vector<int> result;
  int m = matrix.size();
  int n = matrix[0].size();
  int size = m*n;
  enum Directions { right, down, left, up };
  int m_begin(0);
  int n_begin(0);
  int m_end(m-1);
  int n_end(n-1);
  Directions d = right;
  int count = 0;
  while (count < size){
    if (d == right){
      for (int i = n_begin; i <= n_end; ++i){
        result.push_back(matrix[m_begin][i]);
        count++;
      }
      d = down;
      m_begin++;
    }
    else if (d == down){
      for (int i = m_begin; i <= m_end; ++i){
        result.push_back(matrix[i][n_end]);
        count++;
      }
      d = left;
      n_end--;
    }
    else if (d == left){
      for (int i = n_end; i >= n_begin; --i){
        result.push_back(matrix[m_end][i]);
        count++;
      }
      d = up;
      m_end--;
    }
    else{
      for (int i = m_end; i >= m_begin; --i){
        result.push_back(matrix[i][n_begin]);
        count++;
      }
      d = right;
      n_begin++;
    }
  }
  return result;
}

int main(){
  vector<vector<int>> test{{1,2,3},{4,5,6},{7,8,9}};
  vector<int> result = spiralOrder(test);
  for (auto elem : result)
    cout << elem  <<  " " ;
  cout << endl;
  vector<vector<int>> test2 {{1,2,3,4},{5,6,7,8},{9,10,11,12}, {13,14,15,16}};
  vector<int> ret = spiralOrder(test2);
  for (auto elem: ret)
    cout << elem << " " ;
  return 0;
}
