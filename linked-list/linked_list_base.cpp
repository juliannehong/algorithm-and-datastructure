#include <iostream>
using namespace std;

struct ListNode{
  int data;
  ListNode* next;
}

// search node with a key
ListNode* search_key(ListNode* head, int key){
  while (head->data != key && head != nullptr){
    head = head->next;
  }
  return head;
}

// insert node->new_node
void insert_node(ListNode* node, ListNode* new_node){
  new_node->next = node->next;
  node->next = new_node;
}

// delete node after node
void delete_node(ListNode* node){
  node->next = node->next->next;
  // no need to delete?
}
