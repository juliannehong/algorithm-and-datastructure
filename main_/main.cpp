// https://leetcode.com/problems/reverse-linked-list/description/
#include <iostream>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int x): val(x), next(nullptr){}
};

ListNode* reverseList(ListNode* head) {
  ListNode* current = head;
  ListNode* forward_1 = head->next;
  ListNode* forward_2 = head->next->next;

  while (forward_2 != nullptr){
    forward_1->next = current;
    current = forward_1;
    forward_1 = forward_2;
    forward_2 = forward_2->next;
  }
  forward_1->next = current;
  return forward_1;
}

void print_linkedlist(ListNode* head){
  while (head != nullptr){
    cout << head->val << "->";
    head = head->next;
  }
  cout << endl;
}

int main(){
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  print_linkedlist(head);
  ListNode* ans = reverseList(head);
  print_linkedlist(ans);
  
  return 0;
}
