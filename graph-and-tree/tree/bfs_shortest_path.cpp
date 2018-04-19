#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

void build_graph(int src, int dst, unordered_map<int, unordered_set<int>>& graph){
  graph[src].insert(dst);
  graph[dst].insert(src);
}

vector<int> bfs_path_trace(const unordered_map<int, unordered_set<int>>& graph, int src, int dst){
  queue<vector<int>> q;
  vector<bool> visited(graph.size(), false);
  q.push({src});
  visited[src] = true;
  while (!q.empty()){
    vector<int> current_path = q.front();
    int current_node = current_path.back();
    q.pop();
    for (auto node : graph.at(current_node)){
      if (visited[node] == false){
        vector<int> new_path = current_path;
        new_path.push_back(node);
        if (node == dst){
          return new_path;
        }
        q.push(new_path);
        visited[node] = true;
      }
    }
  }
  return {};
}


int main(){
  unordered_map<int, unordered_set<int>> graph;
  
  build_graph(0, 8, graph);
  build_graph(8, 2, graph);
  build_graph(8, 9, graph);
  build_graph(2, 1, graph);
  build_graph(2, 4, graph);
  build_graph(4, 3, graph);
  build_graph(3, 1, graph);
  build_graph(1, 9, graph);
  build_graph(3, 5, graph);
  build_graph(1, 7, graph);
  build_graph(5, 6, graph);
  build_graph(7, 6, graph);
  
  unordered_map<int, unordered_set<int>> graph2;
  build_graph(1, 2, graph2);
  build_graph(1, 3, graph2);
  build_graph(2, 4, graph2);
  build_graph(2, 5, graph2);
  build_graph(3, 6, graph2);
  build_graph(3, 7, graph2);
  
  auto ans = bfs_path_trace(graph, 0, 6);
  
  for (auto node : ans){
    cout << node << " ";
  }
  cout << endl;

  return 0;
}
