// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description///
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;

// failed test cases: ab

int get_slow_iterator(const string& s, unordered_set<char>& word_set, int fast, int slow){
  char to_be_removed = s[slow];
  int result = fast;
  bool gotit = false;
  for (int i = fast; i >= slow; --i){
    if (s[i] == to_be_removed && !gotit){
      result = i;
      gotit = true;
    }
    if (gotit){
      word_set.erase(s[i]);
    }
  }
  
  return (to_be_removed == s[fast-1]) ? result : result + 1;
}

int length_of_longest_substring_K_distinct(string s, int k){
  if (k == 0 || s.empty())
    return 0;
  int fast = 0, slow = 0, result = 0;
  unordered_set<char> word_set;
  while (slow <= fast && fast < s.size()){
    if (word_set.find(s[fast]) == word_set.end() && word_set.size() < k){
      word_set.insert(s[fast]);
      result = max(result, fast - slow + 1);
      fast++;
    }
    else if (word_set.find(s[fast]) == word_set.end() && word_set.size() >= k){
      slow = get_slow_iterator(s, word_set, fast, slow);
      word_set.insert(s[slow]);
      word_set.insert(s[fast]);
      result = max(result, fast - slow + 1);
      fast++;
    }
    else{
      result = max(result, fast - slow + 1);
      fast++;
    }
  }
  return result;
}

int main(){
//  "eceba"
//  2
//  "abcabefg"
//  3
//  "babbdd"
//  0
//  "beeeddd"
//  4
//  "abced"
//  2
//  "abaccc"
//  2
  cout << length_of_longest_substring_K_distinct("ab", 1) << endl;
  cout << length_of_longest_substring_K_distinct("abced", 2) << endl;
  cout << length_of_longest_substring_K_distinct("eceba", 2) << endl;
  cout << length_of_longest_substring_K_distinct("abaccc", 2) << endl;
  return 0;
}
