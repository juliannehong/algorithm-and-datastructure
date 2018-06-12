// https://leetcode.com/problems/reverse-linked-list/description/
#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* reverse_list(ListNode* head){
  ListNode* prev = nullptr;
  while (head != nullptr){
    ListNode* forward = head->next;
    head->next = prev;
    prev = head;
    head = forward;  
  }
  return head;
}

void print_linkedlist(ListNode* head) {
  while (head != nullptr) {
    cout << head->val << "->";
    head = head->next;
  }
  cout << endl;
}

int main() {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  print_linkedlist(head);
  ListNode* ans = reverse_list(head);
  print_linkedlist(ans);

  system("pause");
  return 0;
}
