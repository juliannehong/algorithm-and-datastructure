// sorting algorithms
#include <iostream>
#include <vector>
using namespace std;

void print_array(const vector<int>& v){
  for (int i = 0; i < v.size() - 1; ++i){
    cout << v[i] << ", ";
  }
  cout << v[v.size() - 1] << endl;
}

// 1. insertion sort
void insertion_sort(vector<int>& v){
  for (int i = 1; i < v.size(); ++i){
    int j = i-1;
    int temp = v[i];
    while (temp < v[j] && j >= 0){
      v[j+1] = v[j];
      j--;
    }
    v[j+1] = temp;
  }
}

// 2. merge sort
vector<int> merge_two_sorted_array(const vector<int>& left, const vector<int>& right){
  vector<int> re;
  int i = 0, j = 0;
  while (i < left.size() && j < right.size()){
    (left[i] < right[j]) ? re.push_back(left[i++]) : re.push_back(right[j++]);
  }
  (i == left.size()) ? re.insert(end(re), begin(right)+j, end(right)) : re.insert(end(re), begin(left)+i, end(left));
  return re;
}

vector<int> merge_sort(const vector<int>& v, int l, int r){
  vector<int> re;
  // base case
  if (l == r){
    re.push_back(v[l]);
  }
  else{
    int mid = (l + r) / 2;
    auto left = merge_sort(v, l, mid);
    auto right = merge_sort(v, mid+1, r);
    re = merge_two_sorted_array(left, right);
  }
  return re;
}

// 3. quick sort
void swap(int& x, int& y){
  int temp = x;
  x = y;
  y = temp;
}

void quick_sort(vector<int>& v, int l, int r){
  if (l == r || l > r)
    return ;
  else{
    int pivot = r, low = l, high = r - 1;
    while (low < high){
      if (v[low] >= v[pivot] && v[high] <= v[pivot]){
        swap(v[low], v[high]);
      }
      if (v[low] < v[pivot]){
        low++;
      }
      if (v[high] > v[pivot]){
        high--;
      }
    }
    swap(v[low], v[pivot]);
    quick_sort(v, l, low-1);
    quick_sort(v, low+1, r);
  }
}

void test_sort(vector<int>& nums) {
  for (int i = 1; i < nums.size(); i++) {
    int sorted = i - 1;
    int current = nums[i];
    while (nums[sorted] >= current) {
      nums[sorted + 1] = nums[sorted--];
    }
    nums[sorted] = current;
  }
}

// 4. heap sort

int main(){
  vector<int> test {9,5,3,6,2,4,1};
  test_sort(test);
  for (auto elem : test)
    cout << elem << endl;
  system("pause");
  return 0;
}
