#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

void build_graph(int src, int dst, unordered_map<int, unordered_set<int>>& graph){
  graph[src].insert(dst);
  graph[dst].insert(src);
}

void bfs(int src, const unordered_map<int, unordered_set<int>>& graph){
  queue<int> q;
  q.push(src);
  vector<bool> visited(graph.size(), false);
  visited[src] = true;
  while (!q.empty()){
    int current = q.front();
    cout << current << " ";
    q.pop();
    for (auto node : graph.at(current)){
      if (visited[node] == false){
        q.push(node);
        visited[node] = true;
      }
    }
  }
}

void dfs_recursive(int src, const unordered_map<int, unordered_set<int>>& graph, vector<bool>& visited){
  cout << src << " ";
  visited[src] = true;
  for (auto node : graph.at(src)){
    if (visited[node] == false)
      dfs_recursive(node, graph, visited);
  }
}

void dfs_stack(int src, const unordered_map<int, unordered_set<int>>& graph){
  stack<int> st;
  st.push(src);
  vector<bool> visited(graph.size(), false);
  visited[src] = true;
  while (!st.empty()){
    int current = st.top();
    st.pop();
    cout << current << " ";
    for (auto node : graph.at(current)){
      if (visited[node] == false){
        st.push(node);
        visited[node] = true;
      }
    }
  }
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
  build_graph(8, 9, graph);
  build_graph(3, 5, graph);
  build_graph(1, 7, graph);
  build_graph(5, 6, graph);
  build_graph(7, 6, graph);
  
  cout << "bfs: ";
  bfs(2, graph);
  vector<bool> visited (graph.size(), false);
  cout << endl << "dfs_recursive: ";
  dfs_recursive(2, graph, visited);
  cout << endl << "dfs_stack: ";
  dfs_stack(2, graph);
  cout << endl;
  return 0;
}
