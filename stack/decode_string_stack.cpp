#include <iostream>
#include <stack>
#include <string>
using namespace std;

//s = "3[a]2[bc]", return "aaabcbc".
//s = "3[a2[c]]", return "accaccacc".
//s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

bool is_digit(char c){
  return c - '0' >= 0 && c - '0' <= 9;
}

void repeat_string(string* str_ptr, int n){
  auto& str = *str_ptr;
  string tmp = str;
  while (n-- > 1)
    str.append(tmp);
}

string decode_string_stack(string str){
  stack<int> n_st;
  stack<char> c_st;
  string result;
  string temp;
  for (int i = 0; i < str.size(); ++i){
    if (str[i] == ']'){
      while (c_st.top() != '['){
        temp += c_st.top();
        c_st.pop();
      }
      c_st.pop(); // pop the '['
      repeat_string(&temp, n_st.top());
      n_st.pop();
      
      if (c_st.empty()){
        result.append({temp.rbegin(), temp.rend()});
        temp = "";
      }
    }
    else if (is_digit(str[i])){
      if (i > 0 && is_digit(str[i-1])){
        int temp_n = n_st.top()*10 + (int)str[i]-'0';
        n_st.pop();
        n_st.push(temp_n);
      }
      else{
        n_st.push((int)str[i]-'0');
      }
    }
    else {
      c_st.push(str[i]);
    }
  }
  while (!c_st.empty()){
    temp += c_st.top();
    c_st.pop();
  }
  return result.append({temp.rbegin(), temp.rend()});
}

int main(){
  cout << decode_string_stack("100[leetcode]") << endl;
  cout << decode_string_stack("3[a]2[bc]") << endl;
  cout << decode_string_stack("3[a2[c]]") << endl;
  cout << decode_string_stack("2[abc]3[cd]ef") << endl;
  return 0;
}

