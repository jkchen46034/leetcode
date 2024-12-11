/*
merge two sorted linked list in place
*/

#include <iostream>

struct Node {
  int val;
  Node* next;
  Node(int val): val(val), next(nullptr) {};
};

class Solution {
  public:
  Node* merge(Node *list1, Node* list2) {
    Node *dummy = new Node(-1);
    Node *curr=dummy;

    while (list1 && list2) {
      if (list1->val < list2->val) {
        curr->next = list1;
        list1=list1->next;
      } else {
        curr->next = list2;
        list2=list2->next;
      }
      curr=curr->next;
    }

    if (list1) 
      curr->next = list1;
    if (list2) 
      curr->next = list2;

    return dummy->next;
  } 
};

void print_list(Node *node) {
  while (node) {
    std::cout << node->val << std::endl;
    node=node->next;
  }
}

int main() {
  Solution* sol = new Solution();

  Node* n0 = new Node(2);
  n0->next = new Node(2);
  n0->next->next = new Node(4);
  n0->next->next->next = new Node(5);
  n0->next->next->next->next = new Node(7);

  Node* n1 = new Node(1);
  n1->next = new Node(1);
  n1->next->next = new Node(3);
  n1->next->next->next = new Node(5);
  n1->next->next->next->next = new Node(6);

  print_list(sol->merge(n0,n1));
}