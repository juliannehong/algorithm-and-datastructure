// https://leetcode.com/problems/two-sum/description/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> two_sum(vector<int>& nums, int target){
  unordered_map<int,int> m;
  for (int i = 0; i < nums.size(); ++i){
    m.insert({nums[i], i});
    int comp = target - nums[i];
    if (m.find(comp) != m.end()){
      if (i != m[comp])
        return {i, m[comp]};
    }
  }
  return {NULL, NULL};
}

vector<int> two_sum_wrong(vector<int>& nums, int target){
  unordered_map<int,int> m;
  for (int i = 0; i < nums.size(); ++i){
    m.insert({nums[i], i});
    int comp = target - nums[i];
    if (i != m[comp] && m.find(comp) != m.end()){ // NOTE: this will insert {comp, 0} automatically
        return {i, m[comp]};
    }
  }
  return {NULL, NULL};
}

int main(){
  vector<int> in{-3,4,3,90};
  vector<int> ans = two_sum(in, 0);
  for (auto e : ans)
    cout << e << endl;
  return 0;
}
