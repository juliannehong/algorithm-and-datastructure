// https://leetcode.com/problems/trapping-rain-water/description/
// using two pointers
#include <iostream>
#include <vector>
using namespace std;
// using left/right two pointers

int trap(vector<int>& height){
  int left(0);
  int right(height.size() - 1);
  int result = 0, left_max = 0, right_max = 0;
  
  while (left < right){
    if (height[left] < height[right]){
      if (left_max > height[left])
        result += (left_max - height[left]);
      else
        left_max = height[left];
      left++;
    }
    else{
      if (right_max > height[right])
        result += (right_max - height[right]);
      else
        right_max = height[right];
      right--;
    }
  }
  return result;
}

int main(){
  vector<int> test{0,1,0,2,1,0,1,3,2,1,2,1};
  cout << trap(test) << endl;
  
  return 0;
}
