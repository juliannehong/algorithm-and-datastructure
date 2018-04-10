// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

int max_char_without_repeat(const string& s){

  if (s.size() == 0){
    return -1;
  }

  unordered_set<char> m;
  int max_len = 0;
  int fast = 0, slow = 0;

  while ((slow <= fast) && (fast < s.size())){
    if (m.find(s[fast]) == m.end()){
      m.insert(s[fast]);
      max_len = max(max_len, fast-slow+1);
      fast++;
    }else{
      m.erase(s[slow]);
      slow++;
    }
  }
  return max_len;
}

int main(){
  string t1 = "abcabcbb";
  string t2 = "bbbbb";
  string t3 = "pwwkew";
  cout << max_char_without_repeat(t1) << endl;
  cout << max_char_without_repeat(t2) << endl;
  cout << max_char_without_repeat(t3) << endl;
  return 0;
}