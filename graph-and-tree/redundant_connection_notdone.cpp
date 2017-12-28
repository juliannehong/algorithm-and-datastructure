// https://leetcode.com/problems/redundant-connection-ii/description/
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

// failed testcase: [[1,2],[1,3],[2,3]]

unordered_map<int, unordered_set<int>> get_new_graph(const unordered_map<int, unordered_set<int>>& graph, vector<int> edge_to_remove) {
  unordered_map<int, unordered_set<int>> new_graph = graph;
  new_graph[edge_to_remove[0]].erase(edge_to_remove[1]);
  return new_graph;
}

bool bfs_feasible(const unordered_map<int, unordered_set<int>>& graph, int root) {
  queue<int> q;
  q.push(root);
  if (graph.at(root).size() == 0) {
    return false;
  }
  vector<int> visited_nodes;
  visited_nodes.push_back(root);
  while (!q.empty()) {
    int current = q.front();
    q.pop();
    for (auto child : graph.at(current)) {
      if (find(begin(visited_nodes), end(visited_nodes), child) != end(visited_nodes))
        return false;
    }
  }
  return true;
}


vector<int> find_redundant_directed_connection(vector<vector<int>>& edges) {
  unordered_map<int, unordered_set<int>> graph;
  unordered_map<int, int> parent;
  unordered_map<int, int> child;
  unordered_set<int> nodes;
  vector<vector<int>> candidate;
  for (auto edge : edges) {
    graph[edge[0]].insert(edge[1]);
    parent[edge[0]]++;
    child[edge[1]]++;
    if (child[edge[1]] > 1) {
      for (auto can : edges) {
        if (can[1] == edge[1])
          candidate.push_back(can);
      }
    }
    nodes.insert(edge[0]);
    nodes.insert(edge[1]);
  }
  // find root or root candidates
  int root = -1;
  for (auto node : nodes) {
    if (child.find(node) == end(child)) {
      root = node;
      break;
    }
  }
  // if there's no root; root candidate is the one that has the most children
  if (root == -1){
    root = edges[0][0];
    for (auto node : nodes) {
      if (parent[root] < parent[node]) {
        root = node;
      }
    }
    for (auto edge : edges) {
      if (edge[1] == root)
        return edge;
    }
  }
  else {
    if (candidate.size() == 1)
      return candidate[0];
    else {
      for (auto can : candidate) {
        if (bfs_feasible(get_new_graph(graph, can), root)) {
          return can;
        }
      }

    }
  }
  return { 0,0 };
}

void print_answer(const vector<int>& ans) {
  for (auto e : ans)
    cout << e << ",";
  cout << endl;
}

int main() {
  vector<vector<int>> edges1{ {1,2},{1,3},{2,3} };
  vector<vector<int>> edges2{ {1,2},{2,3},{3,4},{4,1},{1,5} };
  vector<vector<int>> edges3{ {2,1},{3,1},{4,2},{1,4} };
  auto re1 = find_redundant_directed_connection(edges1);
  auto re2 = find_redundant_directed_connection(edges2);
  auto re3 = find_redundant_directed_connection(edges3);
  print_answer(re3);

  system("pause");
  return 0;
}