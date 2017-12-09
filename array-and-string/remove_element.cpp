// https://leetcode.com/problems/remove-element/description/
#include <iostream>
#include <vector>
using namespace std;

int remove_element(vector<int>& nums, int val) {
    auto iter = begin(nums);
    while (iter != end(nums)){
        if (*iter == val){
            iter = nums.erase(iter);
        }
        else{
            iter++;
        }
    }
    return nums.size();
}
