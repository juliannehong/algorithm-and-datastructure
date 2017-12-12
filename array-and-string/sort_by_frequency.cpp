#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> top_k_frequent_element(const vector<int>& nums, int k){
  vector<int> result;
  
  
  return result;
}

vector<int> sort_by_frequency(const vector<int>& v){
  auto comp = [](const pair<int, int>& p1, const pair<int,int>& p2)->bool{
    return p1.second > p2.second;
  };
  
  map<int, int> m;
  for (auto elem : v){
    m[elem]++;
  }
  
  vector<pair<int, int>> temp;
  for (auto p : m){
    temp.push_back(make_pair(p.first, p.second));
  }
  
  sort(begin(temp), end(temp), comp); // O(nlogn)
  
  vector<int> result;
  for (auto elem : temp){
    while (elem.second-- > 0){
      result.push_back(elem.first);
    }
  }
  return result;
}

int main(){
  vector<int> v {3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,1,1,1,4,4,4,4,4,2,2,2,2,2,3,3,3,3,3,3,3,3,2,2,1,2,2,2,2,2,2,2,2,2,2,5};
  vector<int> result = sort_by_frequency(v);
  for (auto e : result)
    cout << e << ", ";
  
  return 0;
}
