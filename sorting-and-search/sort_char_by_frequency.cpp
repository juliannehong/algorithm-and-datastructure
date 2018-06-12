 // https://leetcode.com/problems/sort-characters-by-frequency/description/
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

string frequency_sort(string s){
  string result;
  unordered_map<char, int> m;
  for (auto str : s){
    m[str]++;
  }
  auto comp = [](const pair<char, int>& a, const pair<char, int>& b)->bool{return a.second <= b.second;};
  priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> max_heap(comp);
  for (auto elem : m){
    max_heap.push(make_pair(elem.first, elem.second));
  }
  while (!max_heap.empty()){
    auto current = max_heap.top();
    while (current.second > 0){
      result += current.first;
      current.second--;
    }
    max_heap.pop();
  }
  return result;
}

int main(){
  string test1("aaabbbccccAccddd");
  cout << frequency_sort(test1) << endl;

  return 0;
}