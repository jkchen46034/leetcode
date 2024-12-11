#include <iostream>
#include <vector>
/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/
class list {
  public:
  int val;
  list *next;
  list(int val, list *next): val(val), next(next){};
};

void iterateList(list *list) {
  while (list) {
    std::cout << list->val << " " ;
    list = list->next;
  }
  std::cout << std::endl; 
}

int main() {
  list *l3 = new list(7, 0);
  list *l2 = new list(4, l3);
  list *l1 = new list(3, l2);
  list *l6 = new list(4, 0);
  list *l5 = new list(6, l6);
  list *l4 = new list(8, l5);

  iterateList(l1);
  iterateList(l4);

  list *n1 = l1;
  list *n2 = l4;
  int carry = 0;
  list *dummyhead = new list(0, 0);
  list *prev=dummyhead;
  while (n1 || n2 || carry != 0) {
    int digit1 = (n1) ?  n1->val : 0;
    int digit2 = (n1) ?  n2->val : 0;
    int sum = digit1 + digit2 + carry;
    int digit = sum % 10;
    carry = sum / 10;
    list *newlist = new list(digit, 0);

    prev->next = newlist;
    prev = newlist;

    n1 = (n1)? n1->next : 0;
    n2 = (n2)? n2->next : 0;
  }
  list *head=dummyhead->next;
  delete dummyhead;
  dummyhead = 0;
  iterateList(head);
}