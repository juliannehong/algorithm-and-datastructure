// https://leetcode.com/problems/plus-one-linked-list/description/
#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* plus_one_linked_list(ListNode* head) {
  if (head == nullptr)
    return nullptr;
  ListNode* tail = head;
  ListNode* first_nine = nullptr;
  while (tail != nullptr) {
    if (tail->next == nullptr) { // last digit
      if (tail->val == 9) {
        // update previous nodes
        if (first_nine == nullptr) {
          tail->next = new ListNode(0);
          first_nine = head;
          first_nine->val = 0;
          tail = tail->next;
        }
        first_nine->val++;
        first_nine = first_nine->next;
        while (first_nine != nullptr) {
          first_nine->val = 0;
          first_nine = first_nine->next;
        }
      }
      else {
        tail->val++;
      }
    }
    else {
      if (tail->val != 9 && tail->next->val == 9) {
        first_nine = tail;
      }
    }
    tail = tail->next;
  }
  return head;
}

int main() {
  ListNode* t1 = new ListNode(2);
  t1->next = new ListNode(0);
  t1->next->next = new ListNode(9);
  t1->next->next->next = new ListNode(0);
  t1->next->next->next->next = new ListNode(9);
  t1->next->next->next->next->next = new ListNode(9);
  t1 = plus_one_linked_list(t1);

  while (t1 != nullptr) {
    cout << t1->val << endl;
    t1 = t1->next;
  }
  return 0;
}