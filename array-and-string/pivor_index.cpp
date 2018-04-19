//https://leetcode.com/problems/find-pivot-index/description/
#include <iostream>
#include <vector>

using namespace std;

int pivot_index(vector<int>& nums) {
  int left(0), right(nums.size() - 1), left_sum(nums[left]), right_sum(nums[right]);
  while (left < right) {
    if (left_sum == right_sum && right - left == 2)
      return left + 1;
    if (left_sum < right_sum)
      left_sum += nums[++left];
    else
      right_sum += nums[--right];
  }
  return -1;
}

int main() {
  vector<int> a{ 1,7,3,6,5,6 };
  cout << pivot_index(a) << endl;

  system("pause");
  return 0;
}
//
//[1, 7, 3, 6, 5, 6]
//[]
//[-1, -1, -1, -1, -1, 0]
//[-1, -1, -1, 0, 1, 1]