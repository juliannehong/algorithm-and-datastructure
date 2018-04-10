// element of programming interviews heap first problem
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

vector<string> top_k_longest_string(int k, vector<string>::iterator str_begin, vector<string>::iterator str_end){
  auto comp = [](const string& a, const string& b){return a.size() > b.size();};
  priority_queue<string, vector<string>, decltype(comp)> min_heap(comp);
  
  while (str_begin != str_end){
    min_heap.push(*str_begin);
    if (min_heap.size() > k)
      min_heap.pop();
  }
  vector<string> result;
  while (!min_heap.empty()){
    result.push_back(min_heap.top());
    min_heap.pop();
  }
  return result;
}
