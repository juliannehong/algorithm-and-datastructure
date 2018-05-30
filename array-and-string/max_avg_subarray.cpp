// https://leetcode.com/problems/maximum-average-subarray-i/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double find_max_average(const vector<int>& nums, int k){
  int sum = 0;
  for (int i = 0; i < k; i++){
    sum += nums[i];
  }
  double result = (double)sum/k;
  for (int i = k; i < nums.size(); i++){
    sum = sum + nums[i] - nums[i - k];
    result = max(result, (double)sum/k);
  }
  return result;
}

int main(){
  vector<int> test {1,12,-5,-6,50,3};
  cout << find_max_average(test, 4) << endl;
  return 0;
}