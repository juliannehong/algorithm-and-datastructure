// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int longestSubstr(const string& str){
  int N = str.size();
  if (N == 0)
    return 0;
  
  int m(0);
  int a(0);
  int b(0);
  set<char> set;
  
  // iterater a takes care of the big chuncks
  // iterater b takes care of the individual cases
  while (a < N && b < N){
    if(set.find(str[b]) == end(set)){
      set.insert(str[b]);
      b++;
      m = max(m, b-a);
    }
    else{
      auto it = set.find(str[a]);
      set.erase(it);
      a++;
    }
  }
  return m;
}


int main(){
  string t = "abcdaefg";
  cout << longestSubstr(t) << endl;
  
  return 0;
}
