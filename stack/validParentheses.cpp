t65r4eer // https://leetcode.com/problems/valid-parentheses/description/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool validParentheses(string s){
  stack<char> stack; // push left parens
  for (auto c:s){
    if (c == '(' || c == '{' || c == '[')
      stack.push(c);
    else if (c == ')'){
      if (stack.top() != '(')
        return false;
      else
        stack.pop();
    }
    else if (c == '}'){
      if (stack.top() != '{')
        return false;
      else
        stack.pop();
    }
    else{
      if (stack.top() != '[')
        return false;
      else
        stack.pop();
    }
  }
  return stack.empty();
}

int main(){
  string test1 = "()()((())){[[]]}";
  string test2 = "()()((())){){){}({{{}}})";
  
  cout << validParentheses(test1) << endl;
  cout << validParentheses(test2) << endl;
  
  return 0;
}
