#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int findJustGreater(vector<int>& num, int a){
  // returns an index of an elem ranged (a:end) that is just greater than num[a]
  int current = 10; // because current can only be a single digit
  int idx = a;
  for (int i = a+1; i < num.size(); ++i){
    if (num[i] < num[a])
      continue;
    else
      if (num[i] < current){
        current = num[i];
        idx = i;
      }
  }
  return idx;
}


void nextPermutation(vector<int>& num){
  // iterate right to left
  // when elem decreases, swap that elem with one of the elem on the right that's just greater
  for (int i = num.size() - 1; i > 0; --i){ // compare [i-1] < [i]
    if (num[i-1] < num[i]){
      int justGreater = findJustGreater(num, i-1);
      iter_swap(begin(num)+i-1, begin(num)+justGreater);
      break;
    }
    if (i == 1)
      reverse(begin(num), end(num));
  }
}

int main(){
  vector<int> v1{1,2,3};
  vector<int> v2{3,2,1};
  vector<int> v3{1,1,5};
  
  nextPermutation(v1);
  nextPermutation(v2);
  nextPermutation(v3);
  
  for (auto e : v3)
    cout << e <<" ";
  
  return 0;
}

