// https://leetcode.com/problems/island-perimeter/description/
#include <vector>
#include <iostream>
using namespace std;
bool is_valid_island(vector<vector<int>>& grid, int r, int c){
  return (r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size() && grid[r][c] == 1);
}



void dfs(vector<vector<int>>& grid, int r, int c, int& count){
  cout << "(" << r <<" , " << c << ')' << endl;
   cout << count << endl;
  vector<vector<int>> shifts {{0,-1},{-1,0},{0,1},{1,0}};
  grid[r][c] = 0;
  for (auto s : shifts){
    if (is_valid_island(grid, r+s[0], c+s[1])){
      dfs(grid, r+s[0], c+s[1], --count);
    }
    else{
      cout << "(" << r <<" , " << c << ')' << endl;
      count++;
      cout << count << endl;
    }
  }
}

int islandPerimeter(vector<vector<int>>& grid) {
  // for n number of cube -> 2*n + 2;
  int result = 0;
  for (int i = 0; i < grid.size(); i++){
    for (int j = 0; j < grid[0].size(); j++){
      if (is_valid_island(grid, i, j)){
        int count = 0;
        dfs(grid, i, j, count);
        result += count;
      }
    }
  }
  return result;
}



int main(){
  vector<vector<int>> test1 {
    {1,1,1,1,0},
    {1,1,0,1,0},
    {1,1,0,0,0},
    {0,0,0,0,0}};

  vector<vector<int>> test2 {
    {1,1,0},
    {1,0,0},
    {0,0,0}
  };

  vector<vector<int>> test3{
    {0,1,0,0},
    {1,1,1,0},
    {0,1,0,0},
    {1,1,0,0}
  };
    cout << islandPerimeter(test1) << endl;
  
  // vector<vector<char>> test2 {
  //   {'1','1','0','0','0'},
  //   {'1','1','0','0','0'},
  //   {'0','0','1','0','0'},
  //   {'0','0','0','1','1'}};
  // cout << numIslands(test1) << endl;
  // cout << numIslands(test2) << endl;
  
  // vector<vector<char>> test3 {
  //   {'1','1','1','1','0'},
  //   {'1','1','0','1','0'},
  //   {'1','1','0','0','0'},
  //   {'0','0','0','0','0'}};
  
  // vector<vector<char>> test4 {
  //   {'1','1','0','0','0'},
  //   {'1','1','0','0','0'},
  //   {'0','0','1','0','0'},
  //   {'0','0','0','1','1'}};
  
  // cout << numIslands(test3) << endl;
  // cout << numIslands(test4) << endl;
  return 0;
}

