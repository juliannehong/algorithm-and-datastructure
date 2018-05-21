// https://leetcode.com/problems/move-zeroes/description/
#include <iostream>
#include <vector>
using namespace std;

void move_zeros_1(vector<int>& nums){
  int index = 0;
  for (int i = 0; i < nums.size(); i++){
    if (nums[i] != 0){
      nums[index++] = nums[i];
    }
  }
  while (index < nums.size()){
    nums[index++] = 0;
  }
}

void move_zeros_2(vector<int>& nums){
  int index = 0;
  for (int i = 0; i < nums.size(); i++){
    if (nums[i] != 0){
      swap(nums[index++], nums[i]);
    }
  }
}

int main(){
  vector<int> n1{0,1,0,3,12};
  move_zeros_2(n1);
  for (auto elem : n1)
    cout << elem << " ";
  
  cout << endl;
}