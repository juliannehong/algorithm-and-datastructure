#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // max_element
using namespace std;

int findPeakElement_bf(vector<int>& nums) {
  int result(-1);
  for (int i = 1; i < nums.size() - 1; ++i){
    if (nums[i-1] < nums[i] && nums[i] > nums[i+1])
      result = i;
  }
  return result;
}


int search(vector<int>& nums, int begin, int end){
  if (begin > end)
    return -1;
  if (begin == end)
    return begin;
  int mid = (begin + end)/2;
  if (nums[mid] > nums[mid+1]) // move left
    return search(nums, begin, mid); // note that it's not search(nums, begin, mid-1);
  else
    return search(nums, mid + 1, end);
}


int findPeakElement_bs(vector<int>& nums){
  return search(nums, 0, nums.size()-1);
}


int main(){
  vector<int> v{1,2,3,2};
  cout << findPeakElement_bs(v) << endl;
  
 
  return 0;
}
