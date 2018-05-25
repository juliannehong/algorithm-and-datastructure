https://leetcode.com/problems/daily-temperatures/description/
#include <vector>
#include <iostream>

using namespace std;

// [73, 74, 75, 71, 69, 72, 76, 73]
// [1, 1, 4, 3, 1, 1, 0, 0]
// temperature range [30,100]

vector<int> daily_temperature_bf(const vector<int>& temperatures) {
  vector<int> result(temperatures.size(), 0);
  for (int i = 0; i < temperatures.size(); i++) {
    for (int j = i; j < temperatures.size(); j++) {
      if (temperatures[i] < temperatures[j]) {
        result[i] = j - i;
        break;
      }
    }
  }
  return result;
}



vector<int> daily_temperature(const vector<int>& temperatures) {
  // todo 
}
