// https://leetcode.com/problems/third-maximum-number/description/
#include <iostream>
#include <vector>
using namespace std;

// Input: [3, 2, 1]
// Output: 1

// Input: [1, 2]
// Output: 2

// Input: [2, 2, 3, 1]
// Output: 1


int third_max(const vector<int>& nums){
  bool third_exist = false;
  int first_max = INT_MIN, second_max = INT_MIN, third_max = INT_MIN;
  for (int i = 0; i < nums.size(); i++){
    if (nums[i] > first_max){
      third_max = second_max;
      second_max = first_max;
      first_max = nums[i];
    }
    else if (nums[i] > second_max && nums[i] < first_max){}
      third_max = second_max;
      second_max = nums[i];
    }
    else if (nums[i] < second_max && nums[i] > third_max){
      third_max = nums[i];
    }
  }
  if (third_exist)
    return third_max;
  else
    return first_max;
}

int main(){

}