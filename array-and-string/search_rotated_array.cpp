// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
#include <iostream>
#include <vector>
using namespace std;

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

int helper(const vector<int>& nums, int target, int left, int right){
  int mid = left + (right - left) / 2;
  if (nums[mid] == target)
    return mid;
  if (nums[mid] < nums[right]){ // pivot must be left
    if (nums[mid] < target){
      return helper(nums, target, mid + 1, right);
    }
    else { // 
      return helper(nuns, target, left, mid - 1);
    }
  }
  else { 
    
  }
}

int search(const vector<int>& nums, int target){
  int result = -1;

}

int main(){
  auto ans = search_range({5,7,7,8,8,10}, 8);
  for (auto elem : ans){
    cout << elem << " ";
  }
  cout << endl;
  return 0;
}