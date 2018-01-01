// https://leetcode.com/problems/word-break/description/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool word_break(string s, vector<string>& word_dict){
  unordered_set<string> word_dict_set;
  
}


void cancel_word(string& s, string sub){
  if (sub.size() > s.size())
    return ;
  int N = sub.size();
  for (int i = 0; i <= s.size()-N; ++i){
    if (s.substr(i,N) == sub){
      for (int j = i; j < i + N; ++j){
        s[j] = '_';
      }
      i += N-1;
    }
  }
}

// failed testcase "cars" ["car","ca","rs"]
bool word_break_failed(string s, vector<string>& wordDict){
  string temp = s;
  for (auto w : wordDict){
    cancel_word(temp, w);
  }
  for (auto c : temp){
    if (c != '_')
      return false;
  }
  return true;
}

int main(){
  //cout << wordBreak("leetcode", {"leet","code"}) << endl;
  
  string test1 = "leetleet";
  vector<string> st = {"leet"};
  
  cancel_word(test1, st[0]);
  cout << test1 << endl;
  return 0;
}
