// Binary Search Basic
#include <iostream>
#include <vector>
using namespace std;

int BinarySearchRecursive(const vector<int>& v, int s, int start, int end){
  if (v.empty() || start > end)
    return -1;
  int mid = (start + end) / 2;
  if (v[mid] == s)
    return mid;
  else if (v[mid] > s)
    return BinarySearchRecursive(v, s, start, mid-1);
  else
    return BinarySearchRecursive(v, s, mid+1, end);
}

int main(){
  vector<int> v{2, 3, 4, 10, 40};
  cout << BinarySearchRecursive(v, 50, 0, 4) << endl;
  
  return 0;
}
