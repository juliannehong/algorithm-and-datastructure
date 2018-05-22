// https://leetcode.com/problems/median-of-two-sorted-arrays/description/
#include <iostream>
#include <vector>
using namespace std;

// brute force
double findMedianSortedArrays_merge(vector<int>& nums1, vector<int>& nums2){
  bool isOdd = (nums1.size()+nums2.size()) % 2 == 0 ? false : true;
  int mid = (nums1.size()+nums2.size()) / 2;
  vector<int> merge;
  int a = 0, b = 0;
  for (int i = 0; i <= mid; ++i)
    nums1[a] < nums2[b] ? merge.push_back(nums1[a++]) : merge.push_back(nums2[b++]);
  
  double result = isOdd ? merge.back() : (merge[mid-1] + merge[mid])/2
  return result;
}


int main(){
  vector<int> n1 {1,2};
  vector<int> n2 {3,4};
  cout << findMedianSortedArrays_merge(n1, n2) << endl;
  return 0;
}
