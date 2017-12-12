// https://leetcode.com/problems/top-k-frequent-elements/description/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> top_k_frequent_element(const vector<int>& nums, int k){
  vector<int> result;
  
  auto comp = [](const pair<int, int>& p1, const pair<int,int>& p2)->bool{
    return p1.second > p2.second;
  };
  
  map<int, int> m;
  for (auto num : nums){
    m[num]++;
  }
  vector<pair<int,int>> temp;
  for (auto elem : m){
    temp.push_back(make_pair(elem.first, elem.second));
  }
  sort(begin(temp), end(temp), comp);
  for (int i = 0; i < k; ++i){
    result.push_back(temp[i].first);
  }
  
  return result;
}

int main(){
  vector<int> v {3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,1,1,1,4,4,4,4,4,2,2,2,2,2,3,3,3,3,3,3,3,3,2,2,1,2,2,2,2,2,2,2,2,2,2,5};
  vector<int> result = top_k_frequent_element(v, 3);
  for (auto e : result)
    cout << e << ", ";
  
  return 0;
}
