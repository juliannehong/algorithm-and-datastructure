// https://leetcode.com/problems/find-the-duplicate-number/description/
#include <iostream>
#include <vector>
using namespace std;
//[1,2,3,4,4]
int find_duplicate(const vector<int>& nums){
  int maxnum = (int)nums.size() - 1;
  int sum = maxnum*(1 + maxnum)/2, count = 0;
  for (int i = 0; i < nums.size(); i++){
    count += nums[i];
  }
  return count - sum;
}

int main(){
  cout << find_duplicate({1,3,4,2,2}) << endl;
  cout << find_duplicate({3,1,3,4,2}) << endl;

  return 0;
}