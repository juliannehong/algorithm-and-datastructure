// https://leetcode.com/problems/number-of-islands/description/
#include <iostream>
#include <vector>
using namespace std;

void visited(vector<vector<char>>& grid, int r, int c);

int numOfIsland(vector<vector<char>>& grid){
  int result = 0;
  for (int r = 0; r < grid.size(); ++r){
    for (int c = 0; c < grid[r].size(); ++c){
      if (grid[r][c] == 1){
        visited(grid, r, c);
        result++;
      }
    }
  }
  return result;
}

void visited(vector<vector<char>>& grid, int r, int c){

  grid[r][c] = 0;
  for (int i = 0; i < 4; ++i){
    int offset_r = 0;
    int offset_c = 1;
    switch (i){
      case 1:
        offset_r = 0;
        offset_c = -1;
        break;
      case 2:
        offset_r = 1;
        offset_c = 0;
        break;
      case 3:
        offset_r = -1;
        offset_c = 0;
        break;
    }
    int rt = r + offset_r;
    int ct = c + offset_c;
    if (rt < 0 || rt >= grid.size())
      continue;
    if (ct < 0 || ct >= grid[rt].size())
      continue;
    if (grid[rt][ct] == 0)
      continue;
    visited(grid, rt, ct);
  
  }
}

int main(){
  vector<vector<char>> test {
    {1, 1, 1, 1, 0},
    {1, 1, 0, 1, 0},
    {1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0}
  };
  
  cout << numOfIsland(test) << endl;
  
  
  vector<vector<char>> test2 {
    {1, 1, 0, 0, 0},
    {1, 1, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 1, 1}
  };
  
  cout << numOfIsland(test2) << endl;
  
  
  return 0;
  
}
