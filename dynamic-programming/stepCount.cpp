/* 
// Cracking the Coding Interview 6th Edition
// C++ Solution Implementation
// Chapter 8 Recursion and Dynamic Programming
// Question8.1 Triple Step

// if we knew the number of paths to each of the steps before step 100,
// could we compute the number of steps to 100?
*/

#include <iostream>
#include <unordered_map>
using namespace std;

std::unordered_map<int, int> map; 
map.insert({1,1});
map.insert({2,2});
map.insert({3,4});
int stepCount(int n){
  if (n <= 0)
    return 0;
  auto it = map.find(n);
  if (it != map.end())
    return it->second;
  else
    return stepCount(n-1) + stepCount(n-2) + stepCount(n-3);
}

// overflow?!
