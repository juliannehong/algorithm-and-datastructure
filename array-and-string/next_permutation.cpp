// https://leetcode.com/problems/next-permutation/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1
// 1,3,2 -> 2,1,3
// 1,4,2,8,3,2,1 -> 1,4,3,1,2,2,8

// 1. find the first elem that's not decrementaly sorted
// 2. find element that's least bigger than current element, swap, then sort the rest ascending order
void flip(vector<int>& nums, int left, int right){
  while (left < right){
    swap(nums[left++], nums[right--]);
  }
}

void next_permutation(vector<int>& nums){
  for (int i = nums.size() - 1; i > 0; i--){
    if (nums[i] > nums[i-1]){
      flip(nums, i, nums.size() - 1);
      for (int j = i; j < nums.size(); j++){
        if (nums[i-1] < nums[j]){
          swap(nums[i-1],nums[j]);
          return ; 
        }
      }
    }
  }
  flip(nums, 0, nums.size() - 1);
}

void print_vector(const vector<int>& v){
  for (auto elem : v){
    cout << elem << " ";
  }
  cout << endl;
}



int main(){
  vector<int> test1 {1,2,3};
  vector<int> test2 {3,2,1};
  vector<int> test3 {1,4,2,8,3,2,1};
  vector<int> test4 {3,3,3};
  vector<int> test5 {};

  next_permutation(test1);
  next_permutation(test2);
  next_permutation(test3);
  next_permutation(test4);
  next_permutation(test5);

  print_vector(test1);
  print_vector(test2);
  print_vector(test3);
  print_vector(test4);
  print_vector(test5);
  print_vector(t);

  return 0;
}

