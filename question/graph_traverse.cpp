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
  vector<bool> queued(graph.size(), false);
  visited[src] = true;
  cout << queued.size() << endl;
  while (!q.empty()){
    int current = q.front();
    cout << current << endl;
    q.pop();
    visited[node] = true;
    for (auto node : graph.at(current)){
      if (visited[node] == false){
        q.push(node);
      }
    }
  }
}

void dfs_stack(int src, const unordered_map<int, unordered_set<int>>& graph){
  stack<int> st;
  st.push(src);
  vector<bool> stacked(graph.size(), false);
  visited[src-1] = true;
  while (!st.empty()){
    int current = st.top();
    cout << current << endl;
    st.pop();
    visited[node-1] = true;
    for (auto node : graph.at(current)){
      if (visited[node-1] == false){
        st.push(node);
      }
    }
  }
}

void dfs_recursive(int src, const unordered_map<int, unordered_set<int>>& graph, vector<bool>& visited){
  cout << src << endl;
  visited[src-1] = true;
  for (auto node : graph.at(src)){
    if (visited[node-1] == false){
      dfs_recursive(node, graph, visited);
    }
  }
}



int main(){
  unordered_map<int, unordered_set<int>> graph;
  build_graph(1,2, graph);
  build_graph(1,3, graph);
  build_graph(1,4, graph);
  build_graph(1,5, graph);
  build_graph(2,6, graph);
  build_graph(2,7, graph);
  build_graph(3,8, graph);
  build_graph(3,9, graph);
  build_graph(4,10, graph);
  build_graph(4,11, graph);
  build_graph(4,12, graph);
  build_graph(5,13, graph);
 // bfs(1, graph);
  dfs_stack(1,graph);
 
  return 0;
}