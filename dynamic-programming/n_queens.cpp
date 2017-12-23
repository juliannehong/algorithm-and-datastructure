// https://www.hackerearth.com/practice/basic-programming/recursion/recursion-and-backtracking/tutorial/
#include <iostream>
#include <vector>
using namespace std;

bool is_valid(const vector<vector<int>>& board, int r, int c){
  const int N = board.size();

  for (int i = 0; i < N; ++i)
    if (board[r][i] == 1)
      return false;
  
  for (int j = 0; j < N; ++j)
    if (board[j][c] == 1)
      return false;
  
  for (int i = 0; i < N; ++i){
    for (int j = 0; j < N; ++j){
      if (i+j == r+c || i-j == r-c)
        if (board[i][j] == 1)
          return false;
    }
  }
  return true;
}

bool n_queens(vector<vector<int>>& board, int left_queen){
  if (left_queen == 0)
    return true;
  for (int r = 0; r < board.size(); ++r){
    for (int c = 0; c <board.size(); ++c){
      if (is_valid(board, r, c)){
        board[r][c] = 1;
        if (n_queens(board, left_queen-1))
          return true;
        else
          board[r][c] = 0;
      }
    }
  }
  return false;
}

int main(){
  vector<vector<int>> test {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
  cout << n_queens(test, 4) << endl;
  return 0;
}
