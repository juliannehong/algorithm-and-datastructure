#include <iostream>
#include <vector>
using namespace std;

void visitRecursive(vector<vector<bool>>& visited, vector<vector<int>>& grid, int r, int c);

int numOfIsland(vector<vector<int>>& grid){
  int result = 0;
  vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(), false));
  for (int r = 0; r < grid.size(); ++r){
    for (int c = 0; c < grid[0].size(); ++c){
      if (grid[r][c] == 1 && visited[r][c] == false){
        visitRecursive(visited, grid, r, c);
        result++;
      }
    }
  }
  return result;
}

void visitRecursive(vector<vector<bool>>& visited, vector<vector<int>>& grid, int r, int c){
  if (r >= 0 && c >=0 && visited[r][c] == false && r < grid.size() && c < grid[0].size() && grid[r][c] == 1){
    visited[r][c] = true;
    
    visitRecursive(visited, grid, r-1, c);
    visitRecursive(visited, grid, r+1, c);
    visitRecursive(visited, grid, r, c-1);
    visitRecursive(visited, grid, r, c+1);
    
  }
}

int main(){
  vector<vector<int>> test {
    {1, 1, 1, 1, 0},
    {1, 1, 0, 1, 0},
    {1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0}
  };
  
  cout << numOfIsland(test) << endl;
  
  
  vector<vector<int>> test2 {
    {1, 1, 0, 0, 0},
    {1, 1, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 1, 1}
  };

  
  return 0;
  
}
