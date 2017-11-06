// 8.5
#include <iostream>
#include <string>
using namespace std;

void printParenRecursive(int left, int right, string str, int iter){
  cout << left << right << endl;
  // invalid case
  if (left < 0 || right < left)
    return ;
  // return case
  if (left == 0 && right == 0){
    cout << "**" << endl;
    cout << str << endl;
  }
  
  if (left > 0){
    str.append("(");
    cout << "left" << endl;
    printParenRecursive(--left, right, str, ++iter);
  }
  if (right > left){
    str.append(")");
    cout << "right" << endl;
    printParenRecursive(left, --right, str, ++iter);
  }
  
}
void printParen(int n){
  string result;
  printParenRecursive(n, n, result, 0);
}

int main(){
  printParen(1);
  
  return 0;
}
