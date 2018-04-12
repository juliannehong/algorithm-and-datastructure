// https://leetcode.com/problems/climbing-stairs/description/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int climbing_stairs(int n, unordered_map<int, int>& m) {
  // allowed step = 1, 2
  if (m.find(n) != m.end())
    return m[n];
  else if (n == 1)
    return 1;
  else if (n == 2)
    return 2;
  else {
    m[n] = climbing_stairs(n - 1, m) + climbing_stairs(n - 2, m);
    return m[n];
  }
}

int main() {
  unordered_map<int, int> m;
  cout << climbing_stairs(150, m) << endl;
  return 0;
}