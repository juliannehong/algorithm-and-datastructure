// https://leetcode.com/problems/reverse-string-ii/description/
#include <iostream>
#include <string>
using namespace std;

void flip(string& s, int left, int right){
  if (right >= s.size())
    right = s.size()-1;
  while (left < right){
    swap(s[left++], s[right--]);
  }
}
string reverse_string(string& s, int k){
  for (int i = 0; i < s.size(); i += (2*k)){
    flip(s, i, i+k-1);
  }
  return s;
}

int main(){
  string s1 = "abcdefg";
  string s2 = "abcdefghijklmnopqr";
  cout << reverse_string(s1,2) << endl;
  cout << reverse_string(s2,4) << endl;
  return 0;
}