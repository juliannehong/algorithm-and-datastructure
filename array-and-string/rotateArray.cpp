// https://leetcode.com/problems/rotate-array/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<int>& nums, int k){
  int r = 0;
  while (r < k){
    iter_swap(begin(nums)+r, end(nums)-k+r);
    r++;
  }
}

int main(){
  vector<int> v{1,2,3,4,5,6,7};
  rotate(v, 3);
  for (auto elem:v)
    cout << elem  <<  " ";
  
  return 0;
}
