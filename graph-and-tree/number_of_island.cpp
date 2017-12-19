// https://leetcode.com/problems/number-of-islands/description/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool is_root(int r, int c, const vector<vector<char>>& grid){
  return r < grid.size() && c < grid[0].size() && grid[r][c] == '1';
}

void dfs(int r, int c, vector<vector<char>>* grid_ptr){
  auto& grid = *grid_ptr;
  grid[r][c] = '0'; // visited
  const vector<vector<int>> shifts {{-1,0}, {1,0}, {0,-1}, {0, 1}};
  for (auto shift : shifts){
    if (is_root(r+shift[0], c+shift[1], grid)){
      dfs(r+shift[0], c+shift[1], grid_ptr);
    }
  }
}

void bfs(int r, int c, vector<vector<char>>* grid_ptr){
  auto& grid = *grid_ptr;
  queue<pair<int,int>> q;
  
}

int num_islands_dfs(vector<vector<char>>& grid) {
  int re = 0;
  for (int r = 0; r < grid.size(); ++r){
    for (int c = 0; c < grid[0].size(); ++c){
      if (is_root(r, c, grid)){
        dfs(r, c, &grid);
        re++;
      }
    }
  }
  return re;
}

int num_island_bfs(vector<vector<char>>& grid){
  
}

int main(){
  vector<vector<char>> test1 {
    {'1','1','1','1','0'},
    {'1','1','0','1','0'},
    {'1','1','0','0','0'},
    {'0','0','0','0','0'}};
  
  vector<vector<char>> test2 {
    {'1','1','0','0','0'},
    {'1','1','0','0','0'},
    {'0','0','1','0','0'},
    {'0','0','0','1','1'}};
  cout << num_islands_dfs(test1) << endl;
  cout << num_islands_dfs(test2) << endl;
  
  return 0;
}

