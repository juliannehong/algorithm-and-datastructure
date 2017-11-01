// https://leetcode.com/problems/summary-ranges/description/
// important!
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> summaryRanges(vector<int>& nums){
  // slow (a) fast (b) two pointer
  int a = 0; // slow iter
  vector<string> result;
  for (int b = 0; b < nums.size(); ++b){
    if (b < nums.size() - 1 && nums[b+1] == nums[b]+1)
      continue;
    else{
      if (a == b)
        result.push_back(to_string(nums[b]));
      else
        result.push_back(to_string(nums[a]).append("->").append(to_string(nums[b])));
      a = b + 1;
    }
  }
  return result;
}

int main(){
  vector<int> v{0,2,3,4,6,8,9};
  vector<string> st = summaryRanges(v);
  vector<int> v2 {0,1,2,4,5,7};
  vector<string> st2 = summaryRanges(v2);

  for (auto c:st)
    cout << c << " " ;
  cout << endl;
  for (auto c:st2)
    cout << c << " " ;
  
  return 0;
}

