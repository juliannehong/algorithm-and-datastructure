// https://leetcode.com/problems/longest-absolute-file-path/description/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

pair<int, int> get_level(const string& input, int index){
  int level = 0;
  while(input[++index] == '\t'){
    level++;
  }
  return make_pair(level, index);
}

int longest_file_path(const string& input){
  int max_length = 0;
  bool is_file = false;
  unordered_map<int, string> m;
  int index = 0;
  string current_str = "";
  while(input[index] != '\n' && index < input.size()){
    current_str += input[index];
    if (input[index] == '.')
      is_file = true;
    index++;
  }
  pair<int, int> current_level = make_pair(0,index);
  for (int i = index; i < input.size(); ++i){
    if (input[i] == '\n'){
      // store previous path
      m[current_level.first] = current_str;
      if (is_file){
        max_length = (max_length < current_str.size()) ? current_str.size() : max_length;
        is_file = false;
      }
      current_level = get_level(input, i);
      i = current_level.second-1;
      current_str = m[current_level.first-1] + '/';
    }
    else{
      current_str += input[i];
      if (input[i] == '.')
        is_file = true;
    }
  }
  m[current_level.first] = current_str;
  if (is_file)
    max_length = (max_length < current_str.size()) ? current_str.size() : max_length;
  return max_length;
}


int main(){
  cout << longest_file_path("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext") << endl;
  cout << longest_file_path("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext") << endl;
  cout << longest_file_path("file name with  space.txt") << endl;
  return 0;
}
