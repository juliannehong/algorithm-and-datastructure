// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
#include <iostream>
using namespace std;

struct ListNode{
  int data;
  ListNode* next;
};

//Given 1->1->2, return 1->2.
//Given 1->1->2->3->3, return 1->2->3.

ListNode* delete_duplicates(ListNode* head){
  auto dummy = head; // think 1: why can't I just iterate with 'head'?
  while (dummy != nullptr && dummy->next != nullptr){ // think 2: why need to check dummy->next?
    if (dummy->data == dummy->next->data){
      dummy->next = dummy->next->next;
    }
    else{ // think 3: why need else here? why can't i just move on to next node at each iteration?
      dummy = dummy->next;
    }
    return head;
  }
}



