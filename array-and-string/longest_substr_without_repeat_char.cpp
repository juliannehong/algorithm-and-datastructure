// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

int longest_substr_wo_repeating_char_bf(const string& str){
  int result = 0;
  for (int i = 0; i < str.size(); i++){
    unordered_set<char> cs;
    for (int j = i + 1; j < str.size(); j++){
      if (cs.find(str[j]) != cs.end()){
          result = max(result, static_cast<int>(cs.size()));
          break;
        }
        else{
            cs.insert(str[j]);
        }
      }   
    }
    return result;
}
// abcabcbb
int longest_substr_wo_repeating_char_two_ptr(const string& str){
  int result = 0, left = 0, right = 0;
  unordered_set<char> cs;
  while (left <= right){
    if (cs.find(str[right]) != cs.end()){
      result = max(result, right - left);
      cs.erase(str[left++]);
    }
    else{
      cs.insert(str[right++]);
    }
  }
  return result;
}



int main(){
  string t1 = "abcabcbb";
  string t2 = "bbbbb";
  string t3 = "pwwkew";
  string t4 = "";
  cout << longest_substr_wo_repeating_char_two_ptr(t1) << endl;
  cout << longest_substr_wo_repeating_char_two_ptr(t2) << endl;
  cout << longest_substr_wo_repeating_char_two_ptr(t3) << endl;
  cout << longest_substr_wo_repeating_char_two_ptr(t4) << endl;  
  
  return 0;
}