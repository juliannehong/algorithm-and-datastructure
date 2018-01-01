// https://leetcode.com/explore/interview/card/google/array-and-strings/435/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// counts only alphanumeric chars ignoring spaces
bool is_numeric(char c){
  return (c >= 48 && c <= 57);
}

bool is_alpha(char c){
  return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}

bool same(char a, char b){
  return ((a == b) || (is_alpha(a) && is_alpha(b) && (a - b == 32 || a - b == -32)));
}

bool is_palindrome(string s){
  int left = 0, right = s.size()-1;
  while (left < right){
    if (!(is_alpha(s[left]) || is_numeric(s[left]))){
      left++;
      continue;
    }
    if (!(is_alpha(s[right]) || is_numeric(s[right]))){
      right--;
      continue;
    }
    if (!same(s[left], s[right]))
      return false;
    left++;
    right--;
  }
  return true;
}

int main(){
  string s1 = "A man, a plan, a canal: Panama";
  string s2 = "race a car";
  string s3 = "0P";
  cout << is_palindrome(s1) << endl;
  cout << is_palindrome(s2) << endl;
  cout << is_palindrome(s3) << endl;
  return 0;
}
