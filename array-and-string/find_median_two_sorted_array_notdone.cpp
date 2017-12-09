#include <iostream>
#include <vector>
using namespace std;

double find_median_two_sorted_array(vector<int>& nums1, vector<int>& nums2){
  int N = nums1.size() + nums2.size();
  bool even = (N % 2 == 0);
  int index = N/2 ;
  int i = 0, j = 0;
  double result = 0;
  while (i+j <= index && i < nums1.size() && j < nums2.size()){
    result = (nums1[i] < nums2[j]) ? nums1[i++] : nums2[j++];
    if (i == nums1.size() || j == nums2.size()){
      result = (i == nums1.size()) ? nums2[index-i] : nums1[index-j];
    }
  }
  if (even){
    if (i+j <= index){
      result += (i == nums1.size()) ? nums2[index-i+1] : nums1[index-j+1];
      result /= 2;
    }
    else{
      result += (nums1[i] < nums2[j]) ? nums1[i] : nums2[j];
      result /= 2;
    }
  }
  return result;
}

int main(){
  vector<int> n1 {1,2};
  vector<int> n2 {3,4};
  vector<int> v {0,1,2,3,4};
  //cout << v[v.size()/2] << endl;
  cout << find_median_two_sorted_array(n1, n2) << endl;
  return 0;
}
