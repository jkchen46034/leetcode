#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int val):val(val), next(nullptr){};
};

class Solution {
  public:
    void print_forward(ListNode* node);
};

/*
->1->2->3 
*/
void Solution::print_forward(ListNode* node) {
  if (node==nullptr)
    return;

  std::cout << node->val << std::endl;
  this->print_forward(node->next);
  return ;
}

int main() {

  ListNode* n0= new ListNode(0);
  ListNode* n1= new ListNode(1);
  ListNode* n2= new ListNode(2);
  ListNode* n3= new ListNode(3);
  n0->next=n1;
  n1->next=n2;
  n2->next=n3;

  Solution* sol = new Solution();
  sol->print_forward(n0);
  return 1;
}