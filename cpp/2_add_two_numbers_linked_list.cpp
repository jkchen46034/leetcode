#include <iostream>

struct Node {
  int val;
  Node *next;
  Node(int val): val(val), next(nullptr){};
  Node(int val, Node *next): val(val), next(next){};
};

void iterateList(Node *node) {
  while (node) {
    std::cout << node->val << " " ;
    node = node->next;
  }
  std::cout << std::endl; 
};

class Solution {
  public:
  static Node* solve(Node* n1, Node* n2);
};

Node* Solution::solve(Node* n1, Node* n2) {
  Node* dummyhead = new Node(0);
  Node* prev = dummyhead;

  int carry = 0;
  while (n1 || n2 || carry != 0) {
    int digit1 = (n1) ?  n1->val : 0;
    int digit2 = (n2) ?  n2->val : 0;
    int sum = digit1 + digit2 + carry;
    int digit = sum % 10;
    carry = sum / 10;
    Node* newNode = new Node(digit);

    prev->next = newNode;
    prev = newNode;

    if (n1) n1=n1->next;
    if (n2) n2=n2->next;
  }

  Node* head = dummyhead->next;
  delete dummyhead;

  return head;
}


int main() {
  Node* node1 = new Node(3);
  node1->next = new Node(7);
  node1->next->next = new Node(4);
  Node* node2 = new Node(9);
  node2->next = new Node(1);
  node2->next->next = new Node(8);

  iterateList(node1);
  iterateList(node2);

  Node* n = Solution::solve(node1, node2);
  iterateList(n);

  node2->next->next = nullptr;

  iterateList(node1);
  iterateList(node2);

  n = Solution::solve(node1, node2);
  iterateList(n);
}
