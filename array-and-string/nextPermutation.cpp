//https://leetcode.com/problems/next-permutation/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& num){
  auto it = end(num) - 1; // point to the last elem
  while (it > begin(num)){
    if (*it > *(it - 1)){
      it--;
      break;
    }
    it--;
  }
  if (it == begin(num))
    reverse(begin(num), end(num));
  int current_min = 10;
  int n = *it;
  auto ans = it;
  for (auto it2 = it+1; it2 != end(num); ++it2){
    if (*it2 > n && *it2 < current_min){
      current_min = *it2;
      ans = it2;
    }
  }
  iter_swap(it, ans);
  //cout << *it << endl;
}

int main(){
  vector<int> test1 {4,3,2,4,3,2,1};
  //nextPermutation(test1); //should print out 2
  vector<int> test2{3,2,1};
  nextPermutation(test2);
//  for (auto i : test2)
//    cout << i << " "; // 1,2,3
  
  nextPermutation(test1);
  for (auto j : test1)
    cout << j << " "; //4 3 3 4 2 2 1
  return 0;
}
