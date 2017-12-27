// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int longest_substr_without_repeat_char(const string& str){
  if (str.empty())
    return 0;

  int slow = 0, fast = 0, re = 0;
  set<char> table;
  while (slow <= fast && fast < str.size()){ // notice it's slow <= fast NOT slow < fast; the while-loop wont even hit
    if (table.find(str[fast]) == end(table)){
      table.insert(str[fast]);
      re = max(re, fast - slow + 1);
      fast++;
    }
    else{
      table.erase(str[slow]);
      slow++;
    }
  }
  return re;
}

int main(){
  string s = "abcabcbb";
  cout << longest_substr_without_repeat_char(s) << endl;
  return 0;
}