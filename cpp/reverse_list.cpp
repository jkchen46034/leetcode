#include <iostream>

struct Node {
  int val;
  Node *next;
  Node(int val):val(val), next(nullptr){};
};

class Solution {
  public:
    Node* reverse(Node* node);
};

Node* Solution::reverse(Node* head) {
  Node *current=head, *previous=nullptr, *next;

  while (current!=nullptr) {
    next = current->next;
    current->next = previous;
    previous=current;
    current=next;
  }
  return previous;
}

void print_list(Node *node) {
  while (node) {
    std::cout << node->val << std::endl;
    node=node->next;
  }
}
int main() {
  Solution* sol = new Solution();

  Node *n0= new Node(0);
  n0->next = new Node(1);
  n0->next->next = new Node(2);
  n0->next->next->next = new Node(3);
  n0->next->next->next->next = new Node(4);

  print_list(sol->reverse(n0));
  return 1;
}