// https://leetcode.com/problems/unique-paths-ii/description/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int helper(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& m){

  if (r >= 0 && c >= 0 && m[r][c] != -1)
    return m[r][c];
  if ( r < 0 || c < 0 ||grid[r][c] == 1 )
    return 0;
  if (r == 0 && c == 0 && grid[r][c] == 0)
    return 1;
  if (r == 0 && c == 1 && grid[r][c] == 0)
    return 1;
  if (r == 1 && c == 0 && grid[r][c] == 0)
    return 1;
  m[r][c] = helper(grid, r-1, c, m) + helper(grid, r, c-1, m);
  return m[r][c];
}

int unique_paths_with_obstacles(vector<vector<int>>& obstacle_grid){
  // down [r-1][c]; right [r][c-1]
  // [r][c] = unique_path(r-1,c) + unique_path(r,c-1)
  // if [r][c] == 0; unique path = 0
  if(obstacle_grid[0][0] == 1)
    return 0;
  int R = obstacle_grid.size(), C = obstacle_grid[0].size();
  vector<vector<int>> m(R, vector<int>(C, -1));
  return helper(obstacle_grid, R-1, C-1, m);
}

int main(){
  vector<vector<int>> grid {
    {0,0,0},
    {0,1,0},
    {0,0,0}
  };
  vector<vector<int>> grid2 {
    {0,0,0,0},
    {0,0,0,1},
    {1,0,0,0},
    {0,0,1,0}
  };
  vector<vector<int>> grid3{{1,0,0,0,0,0,0,0,0,1,0}};
  cout << unique_paths_with_obstacles(grid2) << endl;
 
  return 0;
}