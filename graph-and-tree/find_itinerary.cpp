// https://leetcode.com/problems/reconstruct-itinerary/description/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <stack>
using namespace std;


vector<string> find_itinerary(vector<pair<string, string>> tickets) {
  vector<string> re;
  auto lexical = [](string left, string right){return left > right;};
  typedef priority_queue<string, vector<string>, decltype(lexical)> pq;
  unordered_map<string, pq> graph;

  for (auto ticket : tickets)
    graph[ticket.first].push(ticket.second);

  system("pause");
  stack<string> st;
  st.push("JFK");
  
  while (!st.empty()){
    string current = st.top();
    st.pop();
    re.push_back(current);
    if (!graph.at(current).empty()){
      st.push(graph.at(current).top());
      graph.at(current).pop();
    }
  }
  return re;
}

int main(){
  vector<pair<string,string>> tickets;
  tickets.push_back(make_pair("MUC","LHR"));
  tickets.push_back(make_pair("JFK","MUC"));
  tickets.push_back(make_pair("SFO","SJC"));
  tickets.push_back(make_pair("LUR","SFO"));

  vector<string> it = find_itinerary(tickets);

  for (auto elem : it)
    cout << elem << " " ;
  cout << endl;

  return 0;
}





