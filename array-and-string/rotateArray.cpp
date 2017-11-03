#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<int>& nums, int k) {
  vector<int> temp;
  if (nums.size() < k)
    k = k - nums.size();
  for (int i = nums.size()-k; i < nums.size(); ++i)
    temp.push_back(nums[i]);
  for (int i = 0; i<nums.size()-k; ++i)
    temp.push_back(nums[i]);
  nums = temp;
}

void swap(int& x, int& y){
  int temp = x;
  x = y;
  y = temp;
}

void rotate_2(vector<int>& nums, int k){
  if (nums.size() < k)
    k = k - nums.size();
  reverse(begin(nums),end(nums));
  reverse(begin(nums), begin(nums)+k);
  reverse(begin(nums)+k, end(nums));
}


int main(){

//  vector<int> v{1,2,3,4,5,6};
//  rotate_2(v, 11);
//  for (auto e : v)
//    cout << e << " ";
//
  
  vector<int> test {1,2,3,4,5};
  reverse(begin(test)+1, end(test));
//  for (auto i : test)
//    cout << i << " " ;
  
  vector<int> t{1,2};
  reverse(begin(t),end(t));
  for (auto i : t)
    cout << i << " " ;
  cout << endl;
  reverse(begin(t),begin(t)+1);
  for (auto i : t)
    cout << i << " " ;
  cout << endl;
  reverse(begin(t)+1,end(t));
  for (auto i : t)
    cout << i << " " ;
  
  return 0;
}
