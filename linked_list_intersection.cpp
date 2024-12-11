/*
Linked list intersection
*/

#include <iostream>
#include <map>
#include <cassert>

struct Node {
  int val;
  Node *next;
  public:
  Node(int val): val(val), next(nullptr){};
};

class Solution {
  public:
  Node* find_intersection(Node *list1, Node *list2) {
    std::map<Node*, bool> m;
    while (list1) {
      m[list1]=true;
      list1=list1->next;
    }
    while (list2) {
      if (m[list2]) 
        return list2;
      list2=list2->next;
    }
    return nullptr;
  }
};

int main() {
  Node *n0= new Node(0);
  
  n0->next = new Node(1);
  n0->next->next = new Node(2);
  Node *n3 = new Node(3);
  n0->next->next->next = n3;
  n0->next->next->next->next = new Node(4);
 

  Node* n1= new Node(5);
  n1->next = new Node(6);
  n1->next->next = new Node(7);
  n1->next->next->next = n3;
  
  Solution* sol=new Solution();
  assert(sol->find_intersection(n0,n0)->val == 0);
  assert(sol->find_intersection(n1,n1)->val = 1);
  assert(sol->find_intersection(n0,n3)->val = 3);
  assert(sol->find_intersection(n0,n1)->val = 3);
 
  std::cout << "All passed" << std::endl;
  return 1;
}