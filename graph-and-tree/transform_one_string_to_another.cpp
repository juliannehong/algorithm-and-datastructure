em// element of programming interview 18.7
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;

int transform_string(unordered_set<string> D, const string& s, const string& t){
  struct StringWithDistance {
    string candidate_string;
    int distance;
  };
  queue<StringWithDistance> q;
  D.erase(s); // queued
  q.push(StringWithDistance{s, 0});
  while (!q.empty()){
    auto current = q.front();
    if (current.candidate_string == t){
      return current.distance;
    }
 
  }
  
}
