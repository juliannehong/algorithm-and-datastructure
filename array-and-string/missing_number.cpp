//https://leetcode.com/articles/missing-number/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int missing_number_sorting(vector<int>& nums) {
  
  sort(begin(nums),end(nums));
  for (int i = 0; i < nums.size(); ++i){
    if (i != nums[i])
      return i;
  }
  return -1;
}

int missing_number_hash(vector<int>& nums){
  unordered_set<int> us;
  for (auto n : nums)
    us.insert(n);
  
  for (int i = 0; i <= nums.size(); ++i){
    if (us.find(i) == end(us))
      return i;
  }
    
  return -1;
}

int main(){
  vector<int> n{2,3,1,0,5};
  cout << missing_number_sorting(n) << endl;
  cout << missing_number_hash(n) << endl;
  return 0;
}

