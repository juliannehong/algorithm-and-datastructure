#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;

bool is_valid(const vector<vector<int>>& rooms, int r, int c) {
  return (r >= 0 && c >= 0 && r < rooms.size() && c < rooms[0].size() && rooms[r][c] != -1);
}

int bfs(const vector<vector<int>>& rooms, int r, int c) {
  int result = 0;
  vector<vector<int>> shifts{ { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } };
  queue<pair<int,int>> q;
  q.push(make_pair(r, c));
  while (!q.empty()) {
    pair<int, int> curr = q.front();
    q.pop();
    int current_distance = 0;
    for (auto s : shifts) {
      if (is_valid(rooms, curr.first+s[0], curr.second+s[1])) {
        if (rooms[curr.first + s[0]][curr.second + s[1]] == 0) {
          return ++result;
        }
        else { 
          q.push(make_pair(curr.first + s[0], curr.second + s[1]));
        }
      }
    }
    result++;
  }
  return INT_MAX;
}

void wallsAndGates(vector<vector<int>>& rooms) {

  for (int r = 0; r < rooms.size(); r++) {
    for (int c = 0; c < rooms[0].size(); c++) {
      if (rooms[r][c] == INT_MAX)
        rooms[r][c] = bfs(rooms, r, c);
    }
  }
}

//INF - 1  0  INF
//INF INF INF - 1
//INF - 1 INF - 1
//0 - 1 INF INF
int main() {
  vector<vector<int>> rooms1{
    {INT_MAX, -1, 0, INT_MAX},
    {INT_MAX, INT_MAX, INT_MAX, -1},
    {INT_MAX, -1, INT_MAX, -1},
    {0 , -1, INT_MAX, INT_MAX}
  };

  wallsAndGates(rooms1);

  for (auto row : rooms1) {
    for (auto elem : row) {
      cout << elem << " ";
    }
    cout << endl;
  }
  system("pause");
  return 0;
}