// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
// https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/tutorial/
// https://youtu.be/_lHSawdgXpI
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

void build_directed_graph(char src, char dst, int weight, unordered_map<char, vector<pair<char,int>>>& graph){
  graph[src].push_back(make_pair(dst, weight));
}

void dijkstra(char src, unordered_map<char, int>& min_path_weight, unordered_map<char, vector<char>>& min_path_trace, const unordered_map<char, vector<pair<char,int>>>& graph){

  for (auto node : graph){
    min_path_weight[node.first] = INT_MAX;
  }
  min_path_weight[src] = 0;
  min_path_trace[src].push_back(src);
  

  auto comp = [](const pair<char, int> a, const pair<char, int> b){return a.second > b.second;};
  priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> pq(comp);
  pq.push(make_pair(src, min_path_weight[src]));

  while (!pq.empty()){
    auto current = pq.top();
    pq.pop();

    for (auto node : graph.at(current.first)){
      if (current.second + node.second < min_path_weight[node.first]){
        min_path_weight[node.first] = current.second + node.second;
        min_path_trace[node.first] = min_path_trace[current.first];
        min_path_trace[node.first].push_back(node.first);
        pq.push(make_pair(node.first, min_path_weight[node.first]));
      }
    }
  }
}
int main(){
  
  unordered_map<char, vector<pair<char,int>>> graph; // unordered_set<pair<..>> is NOT possible in current c++

  build_directed_graph('a', 'b', 4, graph);
  build_directed_graph('a', 'c', 2, graph);
  build_directed_graph('b', 'c', 3, graph);
  build_directed_graph('b', 'd', 2, graph);
  build_directed_graph('b', 'e', 3, graph);
  build_directed_graph('c', 'b', 1, graph);
  build_directed_graph('c', 'd', 4, graph);
  build_directed_graph('c', 'e', 5, graph);
  build_directed_graph('e', 'd', 1, graph);
  build_directed_graph('d', 'd', 0, graph); // since 'd' never become a src, it won't be added as a key; so add d -> d weight 0;

  unordered_map<char, int> min_path_weight;
  unordered_map<char, vector<char>> min_path_trace;

  dijkstra('a', min_path_weight, min_path_trace, graph);
  
  for (auto elem: min_path_trace){
    cout << elem.first << ": ";
    for (auto path : elem.second){
      cout << path << " ";
    }
    cout << endl;
  }
  cout << "==============" << endl;

  for (auto elem : min_path_weight){
    cout << elem.first << ": " << elem.second << endl;
  }
 
  return 0;
}
