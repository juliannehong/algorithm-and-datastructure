// https://leetcode.com/problems/intersection-of-two-arrays/description/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
  unordered_map<int, int> numset;
  vector<int> result;
  for (int i = 0; i < nums1.size(); i++){
    numset[nums1[i]]++;
  }

  for (int i = 0; i < nums2.size(); i++){
    if (numset.find(nums2[i]) != numset.end()){
      if (numset[nums2[i]] > 0){
        result.push_back(nums2[i]);
        numset[nums2[i]]--;
      }
    }
  }
  return result;
}

int main(){
  vector<int> n {1,2,3,3,4};
  vector<int> m {3,3,4};
  auto ans = intersect(n, m);
  for (auto elem : ans){
    cout << elem << " ";
  }
  cout << endl;
  return 0;
}