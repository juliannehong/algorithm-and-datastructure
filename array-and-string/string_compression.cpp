#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int string_compression(vector<char>& chars){
  int count = 1, index = 0;
  for (int i = 1; i < chars.size(); ++i){
    if (chars[i] != chars[i-1]){
      chars[index++] = chars[i-1];
      if (count > 1){
        string s = to_string(count);
        for (auto c : s){
          chars[index++] = c;
        }
      }
      count = 1;
    }
    else{
      count++;
    }
  }
  chars[index++] = chars[chars.size()-1];
  if (count > 1){
    string s = to_string(count);
    for (auto c : s){
      chars[index++] = c;
    }
  }
  return index;
}

int string_compression_improved(vector<char>& chars){
  int index = 0;
  for (int l = 0, r = 0; r < chars.size(); ++r){
    if (chars[r] != chars[r+1] || r == chars.size() - 1){
      chars[index++] = chars[l];
      if (r - l > 0) {
        string str = to_string(r - l + 1);
        for (auto s : str)
          chars[index++] = s;
      }
      l = r+1;
    }
  }
  return index;
}

int main(){
  
//  vector<char> test {'a','a','b','b','c','c','c'};
//  string_compression(test);
//  for (auto elem : test){
//    cout << elem << endl;
//  }
  
  vector<char> test1 {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
  vector<char> test2 {'a','a','b','b','c','c','c'};
  cout << string_compression_improved(test2) << endl;;
  for (auto elem : test2){
    cout << elem << endl;
  }
  
  return 0;
}
