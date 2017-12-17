#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

void build_graph(int src, int dst, unordered_map<int, unordered_set<int>>* graph_ptr){
  auto& graph = *graph_ptr;
  graph[src].insert(dst);
}

void dfs_recursive(int src, vector<bool>* visited_ptr, const unordered_map<int, unordered_set<int>>& graph){
  auto& visited = *visited_ptr;
  visited[src] = true;
  cout << src << " ";
  for (auto n : graph.at(src)){
    if (!visited[n])
      dfs_recursive(n, visited_ptr, graph);
  }
}

void dfs_stack(int src, const unordered_map<int, unordered_set<int>>& graph){
  stack<int> st;
  st.push(src);
  vector<bool> visited(graph.size(), false);
  while(!st.empty()){
    src = st.top();
    st.pop();
    cout << src << " ";
    visited[src] = true;
    for (auto n : graph.at(src)){
      if (!visited[n])
        st.push(n);
    }
  }
  cout << endl;
}

void bfs_queue(int src, const unordered_map<int, unordered_set<int>>& graph){
  queue<int> q;
  q.push(src);
  vector<bool> visited(graph.size(), false);
  while (!q.empty()){
    src = q.front();
    q.pop();
    cout << src << " " << endl;
    visited[src] = true;
    for (auto n : graph.at(src)){
      if (!visited[n])
        q.push(n);
    }
  }
}

int main(){
  unordered_map<int, unordered_set<int>> graph;
  build_graph(0, 1, &graph);
  build_graph(0, 2, &graph);
  build_graph(1, 3, &graph);
  build_graph(1, 4, &graph);
  build_graph(2, 5, &graph);
  build_graph(2, 6, &graph);
  build_graph(3, NULL, &graph); // unordered_map::at() will throw exception without key
  build_graph(4, NULL, &graph);
  build_graph(5, NULL, &graph);
  build_graph(6, NULL, &graph);
  //dfs_stack(0, graph);
  //vector<bool> visited(graph.size(), false);
  //dfs_recursive(0, &visited, graph);
  bfs_queue(0, graph);
  return 0;
}
