// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
#include <iostream>
#include <vector>

using namespace std;

int search_helper(const vector<int>& nums, int target, int left, int right){
  if (left > right)
    return -1;
  int mid = left + (right - left)/2;
  if (nums[mid] == target) 
    return mid;
  if (nums[mid] > nums[right] && nums[mid] > nums[left]){ // pivot on the right side
    if (target <= nums[right] || target > nums[mid]) // target on the right side
      return search_helper(nums, target, mid + 1, right);
    else // target on the left side
      return search_helper(nums, target, left, mid - 1);
  }
  else if (nums[mid] < nums[left] && nums[mid] < nums[right]){ // pivot on the left side or on mid
    if (target < nums[mid] || target > nums[right])
      return search_helper(nums, target, left, mid - 1); // target must be left
    else  // target must be right
      return search_helper(nums, target, mid + 1, right);
  }
  else{ // regular binary search
    if (target < nums[mid])
      return search_helper(nums, target, left, mid - 1);
    else
      return search_helper(nums, target, mid + 1, right);
  }
}

int search(const vector<int>& nums, int target){
  return search_helper(nums, target, 0, nums.size() - 1);
}

int main(){
  vector<int> nums{4,6,8,9,1,2,3};
  vector<int> test1{4,5,6,7,8,1,2,3};

  vector<int> test{5,1,3};
  cout << search(test1, 8) << endl;
  // cout << search(nums, 4) << endl;
  // cout << search(nums, 6) << endl;
  // cout << search(nums, 8) << endl;
  // cout << search(nums, 9) << endl;
  // cout << search(nums, 1) << endl;
  // cout << search(nums, 2) << endl;
  // cout << search(nums, 3) << endl;
  // cout << search(nums, 5) << endl;
  return 0;
}