// https://leetcode.com/problems/add-binary/description/
#include <iostream>
#include <string>
using namespace std;

string add_binary(string a, string b){
  string re;
  int i = a.size()-1, j = b.size()-1;
  int carry = 0;
  while (i >= 0 || j >= 0 || carry != 0){
    int temp = carry;
    if (i >= 0)
      temp += a[i] - '0'; // can't be "0"
    if (j >= 0)
      temp += b[j] - '0';
    (temp == 1 || temp == 3) ? re += "1" : re += "0";
    carry = temp /= 2;
    i--;
    j--;
  }
  return {re.rbegin(), re.rend()};
}

int main(){
  cout << add_binary("1", "1") << endl;
  return 0;
}
