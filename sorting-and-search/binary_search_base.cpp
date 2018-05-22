// Binary Search Basic
#include <iostream>
#include <vector>
using namespace std;

int bsearch_recursive(const vector<int>& v, int s, int start, int end){
  if (v.empty() || start > end)
    return -1;
  int mid = start + (start - end) / 2;
  if (v[mid] == s)
    return mid;
  else if (v[mid] > s)
    return BinarySearchRecursive(v, s, start, mid-1);
  else
    return BinarySearchRecursive(v, s, mid+1, end);
}

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

