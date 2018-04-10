// http://www.lintcode.com/en/problem/longest-common-subsequence/
// https://leetcode.com/problems/delete-operation-for-two-strings/description/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longest_common_substr_recur(string s1, string s2, int n1, int n2, vector<vector<int>>& memo){
  if (n1 < 0 || n2 < 0)
    return 0;
  if (memo[n1][n2] > 0)
    return memo[n1][n2];
  
  if (s1[n1] == s2[n2])
    memo[n1][n2] = longest_common_substr_recur(s1, s2, n1-1, n2-1, memo) + 1;
  else
    memo[n1][n2] = max(longest_common_substr_recur(s1, s2, n1-1, n2, memo), longest_common_substr_recur(s1, s2, n1, n2-1, memo));
  return memo[n1][n2];
}

int longest_common_substr(string s1, string s2){
  vector<vector<int>> memo (s1.size(), vector<int>(s2.size(), 0));
  return longest_common_substr_recur(s1, s2, s1.size()-1, s2.size()-1, memo);
}



int main(){
  cout << longest_common_substr("ABCD", "EDCA") << endl; // 1
  cout << longest_common_substr("ABCDGH", "AEDFHR") << endl; // 3
  cout << longest_common_substr("AGGTAB", "GXTXAYB") << endl; // 4
  cout << longest_common_substr("", "") << endl; // 0
  return 0;
}
