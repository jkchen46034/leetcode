#include <iostream>
#include <vector>
struct  Node { 
  public:
  int val;
  Node *next;
  Node(int val): val(val), next(nullptr){};
  Node(int val, Node *next): val(val), next(next){};
};

class Solution {
  public:
  static Node* addTwoNumbers(Node* n1, Node* n2);
};

Node* Solution::addTwoNumbers(Node* n1, Node* n2) {
  int carry = 0;
  Node* dummyhead = new Node(0);
  Node* prev = dummyhead;
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
void iterate(Node* n) {
  while (n) {
    std::cout << n->val << " " ;
    n = n->next;
  }
  std::cout << std::endl; 
}

int main() {
  Node *n1 = new Node(8);
  n1->next = new Node(7);
  n1->next->next = new Node(8);

  Node *n2 = new Node(2);
  n2->next = new Node(3);
  n2->next->next = new Node(1);

  iterate(n1);
  iterate(n2);

  Node* head = Solution::addTwoNumbers(n1, n2);

  iterate(head);
}