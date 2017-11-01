// https://leetcode.com/problems/trapping-rain-water/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// using dynamic programming

int trap(vector<int>& height){
  
  vector<int> left_max(height.size());
  vector<int> right_max(height.size());
  
  int m = 0, result = 0;
  for (int left = 0; left < height.size(); ++left){
    if (height[left] > m)
      m = height[left];
    else
      left_max[left] = m - height[left];
  }
  
  m = 0;
  for (int right = height.size() - 1; right >= 0; --right){
    if (height[right] > m)
      m = height[right];
    else
      right_max[right] = m - height[right];
  }
  
  for (int i = 0; i < height.size(); ++i){
    result += min(left_max[i], right_max[i]);
  }
  
  return result;
}

int main(){
  vector<int> v{0,1,0,2,1,0,1,3,2,1,2,1};
  cout << trap(v) << endl;
  return 0;
}
