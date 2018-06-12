// element of programming interview 18.5
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

struct GraphVertex {
  int label;
  vector<GraphVertex*> edges;
};

GraphVertex* clone_graph(GraphVertex* G){
  if (G == nullptr){
    return nullptr;
  }
  
  unordered_map<GraphVertex*, GraphVertex*> vertex_map;
  queue<GraphVertex*> q;
  q.push(G);
  vertex_map.insert({G, new GraphVertex({G->label})});
  while (!q.empty()){
    auto v = q.front();
    q.pop();
    for (auto n : v->edges){
      if (vertex_map.find(n) == end(vertex_map)){
        vertex_map.insert({n, new GraphVertex({n->label})});
        q.push(n);
      }
      vertex_map[v]->edges.push_back(vertex_map[n]);
    }
  }
  return vertex_map[G];
}

int main(){
  GraphVertex* g = new GraphVertex{1};
  g->edges.push_back(new GraphVertex{2});
  g->edges.push_back(new GraphVertex{3});
  
  auto new_g = clone_graph(g);
  for (auto e : new_g->edges){
    cout << e->label << endl;
  }
  return 0;
}
