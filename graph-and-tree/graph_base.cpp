#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph{
  vector<int>* adjList;
  int N;
public:
  Graph(int N);
  void addNode(int n1, int n2);
  void BFS(int s); // queue
  void DFS(int s, vector<bool>& visited); // recursion
  int getSize(){return N;}
};

Graph::Graph(int N){
  N = N;
  adjList = new vector<int>[N]();
}

void Graph::addNode(int n1, int n2){
  adjList[n1].push_back(n2);
}

void Graph::BFS(int s){
  vector<bool> visited(getSize(),false);
  queue<int> q;
  q.push(s);
  visited[s] = true;
  cout << s << " ";
  while(!q.empty()){
    s = q.front();
    q.pop();
    for (auto n : adjList[s]){
      if (!visited[n]){
        q.push(n);
        visited[n] = true;
        cout << n << " ";
      }
    }
  }
  cout << endl;
}

void Graph::DFS(int s, vector<bool>& visited){
  cout << s <<  " ";
  visited[s] = true;
  for (auto n : adjList[s]){
    if(!visited[n])
      DFS(n, visited);
  }
  cout << endl;
}

int main()
{
  Graph g(4);
  g.addNode(0, 1);
  g.addNode(0, 2);
  g.addNode(1, 2);
  g.addNode(2, 0);
  g.addNode(2, 3);
  g.addNode(3, 3);
  vector<bool> visited(4, false);
  g.DFS(0, visited);
  g.BFS(0);
  return 0;
}
