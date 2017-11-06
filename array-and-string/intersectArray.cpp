#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> intersectArr(vector<int>& a, vector<int>& b){
  vector<int> intersect;
  for (int i = 0; i < a.size(); ++i){
    // no duplicate
    // binary search returns bool
    if ((i == 0 || a[i] != a[i-1]) && binary_search(begin(b), end(b), a[i]))
      intersect.push_back(a[i]);
  }
  return intersect;
}

int main(){
  vector<int> a{2,3,3,5,5,6,7,7,8,12};
  vector<int> b{5,5,6,8,8,9,10,10};
  for (auto elem : intersectArr(a, b))
    cout << elem << " ";
  return 0;
}
