//https://leetcode.com/problems/find-pivot-index/description/
#include <iostream>
#include <vector>

using namespace std;

int pivot_index(vector<int>& nums) {
  if (nums.size() == 0)
    return -1;
  int total_sum(0), left_sum, right_sum;
  for (auto elem : nums)
    total_sum += elem;
  left_sum = 0;
  right_sum = total_sum - nums[0];
  if (right_sum == left_sum)
    return 0;
  for (int i = 1; i < nums.size(); i++){
    left_sum += nums[i-1];
    right_sum -= nums[i];
    if (right_sum == left_sum)
      return i;
  }
  return -1;   
}

int main() {
  vector<int> t1{1, 7, 3, 6, 5, 6};
  vector<int> t2{};
  vector<int> t3{2};
  vector<int> t4{-1, -1, -1, -1, -1, 0};
  vector<int> t5{-1, -1, -1, 0, 1, 1};
  vector<int> t6{-1,-1,-1,0,1,1};

  cout << pivot_index(t1) << endl;
  cout << pivot_index(t2) << endl;
  cout << pivot_index(t3) << endl;
  cout << pivot_index(t4) << endl;
  cout << pivot_index(t6) << endl;

  return 0;
}
