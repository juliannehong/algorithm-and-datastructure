#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> get_powerset_recursion(vector<int> set, int index){
  vector<vector<int>> all_subset;
  if (set.size() - 1 == index){
      all_subset.push_back({});
  }
  else{
      all_subset = get_powerset_recursion(set, index+1);
      int element = set[index];
      vector<vector<int>> new_subsets;
      for (auto subset : all_subset){
          vector<int> subset_plus_element = subset.push_back(element);
          new_subsets.push_back(subset_plus_element);
      }
    all_subset.insert(end(all_subset), begin(new_subsets), end(new_subsets));
  }
  return all_subset;
}