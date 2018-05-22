#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void reverse_string(string& s, int l, int r){
  while(l < r){
    char temp = s[l];
    s[l++] = s[r];
    s[r--] = temp;
  }
}

void reverse_words(string& s){
  reverse_string(s, 0, s.size() - 1);
  int c_index = 0;
  for (int i = 0; i < s.size(); i++){
    if(s[i] == ' '){
      reverse_string(s, c_index, i-1);
      c_index = i + 1;
    }
  }
  reverse_string(s, c_index, s.size() - 1);
}

int main(){
  string s = "the sky is blue";
  reverse_words(s);
  cout << s << endl;
  //cout << reverse_words(s) << endl;
  return 0;
}
