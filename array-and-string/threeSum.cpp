//https://leetcode.com/problems/3sum/description/
#include <iostream>
#include <vector>
#include <algorithm> //sort
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){
  int N = nums.size();
  sort(begin(nums), end(nums));
  vector<vector<int>> result;
  for (int i = 0; i < N - 2; ++i){
    int a = i + 1;
    int b = N - 1;
    while (a < b){
      // bigger than 0 -> move b to left
      if (nums[i] + nums[a] + nums[b] > 0)
        --b;
      // less than 0 -> move a to right
      else if (nums[i] + nums[a] + nums[b] < 0)
        ++a;
      // exactly 0 -> push_back to result
      else{
        //vector<int> v {nums[i], nums[a], nums[b]};
        result.push_back({nums[i], nums[a], nums[b]});
        break;
      }
    }
  }
  return result;
}

int main(){
  vector<int> n{-1, 0, 1, 2, -1, -4};
  vector<vector<int>> ans = threeSum(n);
  for (auto big : ans){
    for (auto small : big){
      cout << small << " " ;
    }
    cout << endl;
  }
  
  return 0;
}
