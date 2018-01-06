// https://leetcode.com/problems/closest-binary-search-tree-value/description/
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

vector<string> summary_ranges(vector<int>& nums){
  vector<string> result;
  if (nums.empty())
    return result;
  int fast = 1, slow = 0;
  while (slow <= fast && fast < nums.size()){
    if (nums[fast] - 1 != nums[fast - 1]){
      string current = (slow == fast - 1) ? to_string(nums[slow]) : (to_string(nums[slow])) + "->" + (to_string(nums[fast-1]));
      result.push_back(current);
      slow = fast;
    }
    fast++;
  }
  string last = (slow == fast - 1) ? to_string(nums[slow]) : (to_string(nums[slow])) + "->" + (to_string(nums[fast-1]));
  result.push_back(last);
  return result;
}

int main(){
  
  vector<int> v{0,2,3,4,6,8,9};
  vector<string> st = summary_ranges(v);
  vector<int> v2 {0,1,2,4,5,7};
  vector<string> st2 = summary_ranges(v2);
  
  for (auto e : st){
    cout << e << " ";
  }
  cout << endl;
  
  for (auto e : st2){
    cout << e << " ";
  }
  cout << endl;

  return 0;
}
