// elements of programming interviews in c++ p.162
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

vector<string> top_k_longtest_streaming_string(int k, vector<string>::const_iterator stream_begin, vector<string>::const_iterator stream_end){
  auto comp = [](const string& s1, const string& s2)->bool{return s1.size() >= s2.size();};
  priority_queue<string, vector<string>, decltype(comp)> min_heap(comp);
  while (stream_begin != stream_end){
    min_heap.push(*stream_begin);
    if (min_heap.size() > k){
      min_heap.pop();
    }
  }

  vector<string> result;
  while (!min_heap.empty()){
    result.push_back(min_heap.top());
    min_heap.pop();
  }
}