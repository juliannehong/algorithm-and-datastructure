#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#if 0 // solution below is VERY BAD!!
int maxProfit_BADSOLUTION(vector<int>& prices){
  if (prices.empty())
    return -1;
  int n = 0, a = 0, b = prices.size()-1, max = prices[b], min = prices[a];
  while (a < b && n < prices.size()){
    if (min >= prices[a]){
      min = prices[a++];
    }
    if (max <= prices[b]){
      max = prices[b--];
    }
    n++;
  }
  return (max - min > 0) ? max - min : 0;
}
#endif
int maxProfit(vector<int>& prices){
  int min = INT_MAX;
  int profit = 0;
  for (int i = 0; i < prices.size(); ++i){
    if (prices[i] < min){
      min = prices[i];
    }
    else{
      if (prices[i] - min > profit)
        profit = prices[i] - min;
    }
  }
  return profit;
}

int main()
{
  vector<int> v{7, 1, 5, 3, 6, 4};
  cout << maxProfit(v) << endl;
  vector<int> v2{7, 6, 4, 3, 1};
  cout << maxProfit(v2) << endl;
  return 0;
}
