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
  const vector<vector<int>> shifts {{-1,0}, {1,0}, {0,-1}, {0,1}};
  q.push(make_pair(r, c));
  while (!q.empty()){
    auto current = q.front();
    q.pop();
    grid[current.first][current.second] = '0';
    for (auto shift : shifts){
      if (is_root(current.first+shift[0], current.second+shift[1], grid))
        q.push(make_pair(current.first + shift[0],current.second+shift[1]));
    }
  }
  
}

int num_islands_dfs(vector<vector<char>>& grid) {
  int re = 0;
  for (int r = 0; r < grid.size(); +å+r){
    for (int c = 0; c < grid[0].size(); ++c){
      if (is_root(r, c, grid)){
        dfs(r, c, &grid);
        re++;
      }
    }
  }
  return re;
}

int num_islands_bfs(vector<vector<char>>& grid){
  int re = 0;
  for (int r = 0; r < grid.size(); ++r){
    for (int c = 0; c < grid[0].size(); ++c){
      if (is_root(r, c, grid)){
        bfs(r, c, &grid);
        re++;
      }
    }
  }
  return re;
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
  
  vector<vector<char>> test3 {
    {'1','1','1','1','0'},
    {'1','1','0','1','0'},
    {'1','1','0','0','0'},
    {'0','0','0','0','0'}};
  
  vector<vector<char>> test4 {
    {'1','1','0','0','0'},
    {'1','1','0','0','0'},
    {'0','0','1','0','0'},
    {'0','0','0','1','1'}};
  
  cout << num_islands_bfs(test3) << endl;
  cout << num_islands_bfs(test4) << endl;
  return 0;
}

