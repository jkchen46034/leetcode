#include <iostream>

struct Node {
  int val;
  Node* next;
  Node(int val):val(val), next(nullptr){};
};

class Solution {
  public:
  static void print_backwards(Node* node);
};

void Solution::print_backwards(Node* node) {
  if (node==nullptr)
    return;

  print_backwards(node->next);
  std::cout << node->val << std::endl;

  return ;
}

int main() {
  Node* n0= new Node(0);
  n0->next = new Node(1);
  n0->next->next = new Node(2);
  n0->next->next->next = new Node(3);

  Solution::print_backwards(n0);
  return 1;
}