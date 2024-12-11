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
    Node *dummyNode = new Node(-1);
    Node *prev=dummyNode, *curr=list1;
    prev->next = list1;
    Node *heading=prev;
    while (curr != nullptr && list2 != nullptr) {
      if (list2->val < curr->val) {
        Node *next=list2->next;
        list2->next = curr;
        prev->next = list2;
        prev=list2;
        list2=next;
      } else {
        prev = curr;
        curr = curr->next;
      }
    }
    if (list2!=nullptr) {
      prev->next = list2;
    }
    return heading->next;
  } 
};

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

  Node* result = sol->merge(n0,n1);
  while (result != nullptr) {
    std::cout << result->val << std::endl;
    result=result->next;
  }
}