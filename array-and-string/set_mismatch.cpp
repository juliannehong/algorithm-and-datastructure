// https://leetcode.com/problems/set-mismatch/solution/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// O(nlogn) O(nlogn)
vector<int> find_err_nums_sort(const vector<int>& nums){
  sort(begin(nums), end(nums));
  int missing = -1, repeat = -1, N = nums.size();
  if (nums[0] != 1)
    missing = 1;
  if (nums[N-1] != N)
    missing = N;
  for (int i = 1; i < N; ++i){
    int diff = nums[i] - nums[i-1];
    if (diff == 0)
      repeat = nums[i];
    if (diff > 1)
      missing = nums[i] - 1;
  }
  vector<int> result {repeat, missing};
  return result;
}

// O(n) O(n)
vector<int> find_err_nums_map(const vector<int>& nums){
  int missing = -1, repeat = -1;
  unordered_map<int, int> map;
  for (auto elem : nums){
    auto ins = map.insert({elem, 1});
    if (!ins.second){
      repeat = elem;
    }
  }
  for (int i = 1; i <= nums.size(); ++i){
    if(map.find(i) == end(map)){
      missing = i;
      break;
    }
  }
  vector<int> result {repeat, missing};
  return result;
}
