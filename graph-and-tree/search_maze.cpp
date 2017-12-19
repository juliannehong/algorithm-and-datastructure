// element of programming interview 18.1
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <array>

using namespace std;

typedef enum { WHITE, BLACK } Color;

struct Coordinate {
  bool operator==(const Coordinate& that) const{
    return x == that.x && y == that.y; // this->x==that.x && this->y==that.y
  }
  int x, y;
};

bool is_feasible(const Coordinate& coor, const vector<vector<Color>>& maze){
  return coor.x >= 0 && coor.x < maze.size() && coor.y >= 0 && coor.y < maze.size() && maze[coor.x][coor.y] == WHITE;
}

bool search_maze_dfs(const Coordinate& src, const Coordinate& dst, vector<vector<Color>>* maze_ptr, vector<Coordinate>* path_ptr){
  auto& maze = *maze_ptr;
  if (!is_feasible(src, maze))
    return false;
  
  path_ptr->push_back(src);
  maze[src.x][src.y] = BLACK; // visited therefore blocked (wall)
  
  if (src == dst)
    return true;
  
  const array<array<int, 2>, 4> shifts = {{ {0,1}, {1,0}, {-1,0}, {0, -1} }};
  
  for (auto shift : shifts){
    if (search_maze_dfs({src.x+shift[0], src.y+shift[1]}, dst, maze_ptr, path_ptr))
      return true;
  }
  
  // if function reaches here, means it can't find a path from this block --> exclude from the path, but marked visited
  path_ptr->pop_back();
  return false;
}


