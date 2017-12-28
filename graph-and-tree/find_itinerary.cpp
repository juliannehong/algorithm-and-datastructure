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
  //auto lexical = [](string left, string right){return left > right;};
  //typedef priority_queue<string, vector<string>, decltype(lexical)> pq(lexical);
  //unordered_map<string, priority_queue<string, vector<string>, decltype(lexical)>> graph(lexical);
  unordered_map<string, priority_queue<string>> graph;
  for (auto ticket : tickets)
    graph[ticket.first].push(ticket.second);

  
  stack<string> st;
  st.push("JFK");

  while (!st.empty()){
    string current = st.top();
    st.pop();
    re.push_back(current);
    while (!graph[current].empty()){
      st.push(graph[current].top());
      graph[current].pop();
    }
  }
  return re;
}

int main(){
  vector<pair<string,string>> tickets;
  tickets.push_back(make_pair("MUC","LHR"));
  tickets.push_back(make_pair("JFK","MUC"));
  tickets.push_back(make_pair("SFO","SJC"));
  tickets.push_back(make_pair("LHR","SFO"));
  
  vector<string> it = find_itinerary(tickets);
  
  for (auto elem : it)
    cout << elem << " " ;
  cout << endl;
  
  vector<pair<string,string>> tickets2;
  tickets2.push_back(make_pair("JFK","SFO"));
  tickets2.push_back(make_pair("JFK","ATL"));
  tickets2.push_back(make_pair("SFO","ATL"));
  tickets2.push_back(make_pair("ATL","JFK"));
  tickets2.push_back(make_pair("ATL","SFO"));
  
  vector<string> result = find_itinerary(tickets2);
  for (auto elem : result)
    cout << elem << " ";
  cout << endl;
  
  return 0;
}






