#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool is_palinromic(string& s){
  for (int i = 0, j = s.size()-1; i < j; ++i, --j){
    if (s[i] != s[j])
      return false;
  }
  return true;
}

int main(){
  string a = "asffsa"; // even
  string b = "ebgbe"; // odd
  string c = "erbes";
  string d = "jdlskd";
  cout << isPalinromic(a) << endl; // true
  cout << isPalinromic(b) << endl; // true
  cout << isPalinromic(c) << endl; // false
  cout << isPalinromic(d) << endl; // false
  return 0;
}
