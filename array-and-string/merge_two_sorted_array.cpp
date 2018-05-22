// https://leetcode.com/problems/merge-sorted-array/description/
#include <iostream>
#include <vector>
using namespace std;

// nums1 = [1,2,3,0,0,0], m = 3
// nums2 = [2,5,6],       n = 3

// Output: [1,2,2,3,5,6]
// num1 already have arr size allocated
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
  int index1 = m-1, index2 = n-1, total = m+n-1;
  while(index1 >= 0 && index2 >= 0){
    if (nums1[index1] > nums2[index2])
      nums1[total--] = nums1[index1--];
    else
      nums1[total--] = nums2[index2--];
  }
  while (index2 >= 0){
    nums1[total--] = nums2[index2--];
  }
}
