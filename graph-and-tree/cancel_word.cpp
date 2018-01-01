// cancel word
#include <iostream>
#include <string>
using namespace std;

void cancel_word(string& s, string sub){
  int N = sub.size();
  for (int i = 0; i <= s.size()-N; ++i){
    if (s.substr(i,N) == sub){
      for (int j = i; j < i + N; ++j){
        s[j] = '_';
      }
      i += N;
    }
  }
}
  
int main(){
  string s = "helloworldhowareyou?";
  string sub = "world";
  cancel_word(s,sub); // "hello_____howareyou?"
  cancel_word(s,"?"); // "hello_____howareyou_"

  return 0;
}
