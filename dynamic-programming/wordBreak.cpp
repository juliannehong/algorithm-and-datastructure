#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
  return true;
  
}

int main(){
  vector<string> str{"hello","hi"};
  auto it = find(begin(str),end(str),"hello");
  if (it != end(str))
    cout << "yes" << endl;
  else
    cout << "no" << endl;
  
  return 0;
}
