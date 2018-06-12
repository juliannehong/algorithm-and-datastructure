// https://leetcode.com/problems/top-k-frequent-elements/description/
#include <iostream>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

// using heap


// brute force
vector<int> top_k_frequent(const vector<int>& nums, int k){
  vector<int> result;
  auto comp = [](const pair<int,int>& p1, const pair<int,int>& p2)->bool {return p1.second > p2.second;};
  unordered_map<int, int> m;
  for (auto elem : nums){
    m[elem]++;
  }
  vector<pair<int,int>> v(m.begin(), m.end());
  sort(v.begin(), v.end(), comp);
  for (int i = 0; i < k; i++){
    result.push_back(v[i].first);
  }
  return result;
}

int main(){
  vector<int> v = top_k_frequent({3,4,6,8,8,6,5,4,2,2,1,1,3,43,2,3,4,5},5);
  for (auto elem : v){
    cout << elem << endl;
  }
  return 0;
}