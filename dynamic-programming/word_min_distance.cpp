// https://leetcode.com/problems/edit-distance/description/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int min(int a, int b, int c){
  return min(min(a,b),c);
}

int min_distance_recur(string from_str, string to_str, int from_index, int to_index, vector<vector<int>>& memo){
  if (from_index < 0 && to_index >= 0)
    return to_index;
  
  if (to_index < 0 && to_index >= 0)
    return from_index;
  
  if (from_index < 0 && to_index < 0)
    return 0;
  
  if (memo[from_index][to_index] > 0)
    return memo[from_index][to_index];
  
  if (from_str[from_index] == to_str[to_index])
    memo[from_index][to_index] = min_distance_recur(from_str, to_str, from_index - 1, to_index - 1, memo);
  else
    memo[from_index][to_index] = 1 + min(min_distance_recur(from_str, to_str, from_index - 1, to_index, memo), min_distance_recur(from_str, to_str, from_index, to_index - 1, memo), min_distance_recur(from_str, to_str, from_index - 1, to_index - 1, memo));
  return memo[from_index][to_index];
}

int min_distance(string word1, string word2){
  if (word1.empty())
    return word2.size();
  if (word2.empty())
    return word1.size();
  
  vector<vector<int>> memo(word1.size(), vector<int>(word2.size(), 0));
  return min_distance_recur(word1, word2, word1.size()-1, word2.size()-1, memo);
}


int main(){
  cout << min_distance("a","b") << endl;
  cout << min_distance("","b") << endl;
  cout << min_distance("geek","geeks") << endl;
  cout << min_distance("sunday","saturday") << endl;

  return 0;
}

