// https://leetcode.com/problems/valid-sudoku/description/
#include <iostream>
#include <vector>
using namespace std;


bool check_sub_mat(int r, int c, const vector<vector<char>>& board){
  vector<vector<int>> shifts = {{-1,-1}, {-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
  vector<bool> visited(9, false);
  if (board[r][c] != '.')
    visited[board[r][c] - '0'-1] = true;
  for (auto shift : shifts){
    int temp_r = r+shift[0], temp_c = c+shift[1];
    if (board[temp_r][temp_c] != '.'){
      int current = board[temp_r][temp_c] - '0' - 1;
      if (visited[current])
        return false;
      else
        visited[current] = true;
    }
  }
  return true;
}


bool is_valid_sudoku(vector<vector<char>>& board) {
  // validate each row
  for (int i = 0; i < 9; ++i){
    vector<bool> visited(9, false);
    for (int j = 0; j < 9; ++j){
      if (board[i][j] != '.'){
        int current = board[i][j] - '0' - 1;
        if (visited[current])
          return false;
        else
          visited[current] = true;
      }
    }
  }
  
  // validate each column
  for (int i = 0; i < 9; ++i){
    vector<bool> visited(9, false);
    for (int j = 0; j < 9; ++j){
      if (board[j][i] != '.'){
        int current = board[j][i] - '0' - 1;
        if (visited[current])
          return false;
        
        else
          visited[current] = true;
      }
    }
  }
  
  // validate 3x3
  for (int i = 1; i < 4; ++i){
    int current_r = 3*i - 2;
    for (int j = 1; j < 4; ++j){
      int current_c = 3*j - 2;
      if (!check_sub_mat(current_r, current_c, board))
        return false;
    }
  }
  return true;
}

int main(){
  vector<vector<char>> board {
    {'.','8','7','6','5','4','3','2','1'},
    {'2','.','.','.','.','.','.','.','.'},
    {'3','.','.','.','.','.','.','.','.'},
    {'4','.','.','.','.','.','.','.','.'},
    {'5','.','.','.','.','.','.','.','.'},
    {'6','.','.','.','.','.','.','.','.'},
    {'7','.','.','.','.','.','.','.','.'},
    {'8','.','.','.','.','.','.','.','.'},
    {'9','.','.','.','.','.','.','.','.'}
  };
    cout << is_valid_sudoku(board) << endl;
  
  vector<vector<char>> board2 {
    {'3','5','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','8','9','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
  };
   cout << is_valid_sudoku(board2) << endl;
  vector<vector<char>> board3 {
    {'.','.','5','.','.','.','.','.','6'},
    {'.','.','.','.','1','4','.','.','.'},
    {'.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','9','2','.','.'},
    {'5','.','.','.','.','2','.','.','.'},
    {'.','.','.','.','.','.','.','3','.'},
    {'.','.','.','5','4','.','.','.','.'},
    {'3','.','.','.','.','.','4','2','.'},
    {'.','.','.','2','7','.','6','.','.'}};
  cout << is_valid_sudoku(board3) << endl;

  vector<vector<char>> board4 {
    {'.','.','5','.','.','.','.','.','6'},
    {'.','5','.','.','1','4','.','.','.'},
    {'.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','9','2','.','.'},
    {'5','.','.','.','.','9','.','.','.'},
    {'.','.','.','.','.','.','.','3','.'},
    {'.','.','.','5','4','.','.','.','.'},
    {'3','.','.','.','.','.','4','2','.'},
    {'.','.','.','2','7','.','6','.','.'}};
  
    cout << is_valid_sudoku(board4) << endl;
  
  vector<vector<char>> board5 { // debug!!!
    {'.','.','.','.','.','3','2','.','4'},
    {'.','.','.','.','2','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.'},
    {'.','6','.','.','.','.','7','.','.'},
    {'.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','9','.','.','.','.'},
    {'3','.','.','1','.','.','.','8','.'},
    {'.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.'}};
  
  cout << is_valid_sudoku(board5) << endl;
  return 0;
}

