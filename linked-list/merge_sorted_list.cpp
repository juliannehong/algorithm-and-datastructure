// https://leetcode.com/problems/sort-characters-by-frequency/description/
#include <iostream>
using namespace std;

struct ListNode{
  int data;
  ListNode* next;
};

ListNode* merge_sorted_linked_lists(ListNode* l1, ListNode* l2){
  ListNode dummy;;
  auto tail = &dummy;
  while (l1 != nullptr && l2 != nullptr){
    if (l1->data < l2->data){
      tail->next = l1;
      l1 = l1->next;
    }
    else{
      tail->next = l2;
      l2 = l2->next;
    }
    tail = tail->next;
  }
  tail->next =  l1 ? l1 : l2;
  return dummy.next;
}

int main(){
  ListNode* l1 = new ListNode{1, nullptr};
  l1->next = new ListNode{3, nullptr};
  l1->next->next = new ListNode{5, nullptr};
  l1->next->next->next = new ListNode{6, nullptr};
  ListNode* l2 = new ListNode{2, nullptr};
  l2->next = new ListNode{4, nullptr};
  l2->next->next = new ListNode{7, nullptr};
  l2->next->next->next = new ListNode{8, nullptr};

  ListNode* result = merge_sorted_linked_lists(l1, l2);
  
  while (result != nullptr){
    cout << result->data << endl;
    result = result->next;
  }

  return 0;
}
