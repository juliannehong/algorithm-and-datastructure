// https://leetcode.com/problems/string-compression/description/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

// ["a","b","b","b","b","b","b","b","b","b","b","b","b"] => ["a","b","1","2"] => 4

// ["a"] => ["a"] => 1

// ["a","a","b","b","c","c","c"] => ["a","2","b","2","c","3"] => 6
int number_of_digits(int n){
  int result = 0;
  while (n != 0){
    n /= 10;
    result += 1;
  }
  return result;
}
// int compress_bf(vector<char>& chars){
//   // hash mpa
//   // everytime the char change, put into return map
//   int result = 0;
//   char c = "0";
//   for (int i = 0; i < chars.size(); i++){
//     if (chars[i] != c){
      
//     }
//   }
// }

int main(){
  cout << number_of_digits()
}