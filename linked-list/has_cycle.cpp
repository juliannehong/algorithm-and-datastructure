// https://leetcode.com/problems/linked-list-cycle/description/
#include <iostream>
#include "main/linked_list.h"
#include <unordered_set>
#include <algorithm>
using namespace std;

bool has_cycle_two_ptr(ListNode* head){
  
}

bool has_cycle_hash(ListNode* head){
  unordered_set<int> visited;
  while (head != nullptr){
    if (visited.find(head->val) != visited.end()){
      return true;
    }
    visited.insert(head->val);
    head = head->next;
  }
  return false;
}

int main(){

}