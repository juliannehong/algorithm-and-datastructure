// https://leetcode.com/problems/search-for-a-range/description/
#include <iostream>
#include <vector>
using namespace std;

// [5,7,7,8,8,10]
// target = 8

void helper(const vector<int>& nums, int target, int left, int right, vector<int>& result){
  int mid = left + (right - left) / 2;
  if (target < nums[mid])
    helper(nums, target, left, mid - 1);
  else if (target > nums[mid])
    helper(nums, target, mid + 1, right);
  else{ // target == [mid]
    if (mid == left && result[0] == -1)
      result[0] = mid;
    if (mid == right && result[1] == -1)
      result[1] = mid;
    if (nums[mid + 1] != target){
      result[1] = mid;
      helper(nums, target, left, mid - 1, result);
    }
    if (nums[mid - 1] != target){
      result[0] = mid;
      helper(nums, target, mid + 1, right, result);
    }
  }
}

vector<int> search_range(const vector<int>& nums, int target){
  vector<int> result {-1, -1};
  //helper(nums, result, target, 0, nums.size() - 1);
  return result;
}

int main(){
  auto ans = search_range({5,7,7,8,8,10}, 8);
  for (auto elem : ans){
    cout << elem << " ";
  }
  cout << endl;
  return 0;
}