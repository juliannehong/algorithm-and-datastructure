// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
// NOT DONE
#include <iostream>
#include <vector>
using namespace std;

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

int bsearch_iterative(vector<int>& nums, int target){
  int l = 0, u = nums.size() - 1;
  while (l <= u){
    int m = l + (u - l) / 2;
    if (target == nums[m])
      return m;
    else if (target < nums[m])
      u = m-1;
    else 
      l = m+1;
  }
  return -1;
}

// [9,10,1,2,3,4,5,6,7];
// [4,5,6,7,9,10,1,2,3]
// 4,5,6,7,0,1,2
// 15,17,69,5,7,9,10,11,12,13,
// 15,17,69,5,7,9,10,11,12,13,14
int search(const vector<int>& nums, int target){
  int l = 0, u = nums.size() - 1;
  while (l <= u){
    int m = l + (u - l) / 2;
    if (nums[m] == target)
      return m;
    if (nums[m] < nums[u]){ // pivot should be left
      if (nums[u] >= target && target > nums[m]){ // target must be right
        l = m+1;
      }
      else{ // target must be right
        u = m-1;
      }
    }
    else { // pivot should be right
      if (nums[l] <= target && target < nums[m]){ //target must be left
        u = m-1;
      } 
      else{ // target must be right
        l = m+1;
      }
    }
  }
  return -1;
}



 int main(){
   vector<int> nums1 {4,5,6,7,0,1,2};
   vector<int> nums2 {15,17,69,5,7,9,10,11,12,13,14};
  //  cout << search(nums1, 0) << endl;
  //  cout << search(nums1, 7) << endl;
  //  cout << search(nums1, 8) << endl;
   cout << search(nums2, 69) << endl; // 2
   cout << search(nums2, 14) << endl; // 11
   cout << search(nums2, 15) << endl; // 0
   cout << search(nums2, 10) << endl; // 7
   cout << search(nums2, 16) << endl; // -1
   cout << search(nums2, 8) << endl; // -1 
   return 0;
 }