#include <iostream>
#include <cassert>

struct Node {
  int val;
  Node *left, *right;
  public:
  Node(int val):val(val),left(nullptr), right(nullptr){};
};

class Solution{
  public:
    bool isSame(Node *tree1, Node *tree2){
      if (tree1==nullptr && tree2==nullptr) 
        return true;

      if (tree1==nullptr || tree2==nullptr) 
        return false;

      return (tree1->val==tree2->val) && isSame(tree1->left, tree2->left) && isSame(tree1->right, tree2->right);
    }
};

int main() {
  Node *n0 = new Node(0);
  n0->left = new Node(1);
  n0->right = new Node(2);

  Node *n1 = new Node(0);
  n1->left = new Node(1);

  Solution *sol = new Solution();
  assert(sol->isSame(n0,n1)==false);

  n1->right = new Node(2);
  assert(sol->isSame(n0,n1)==true);

  n0->right->left = new Node(5);
  n1->right->left = new Node(5);

  assert(sol->isSame(n0,n1)==true);

  n1->right->val = 3;
  assert(sol->isSame(n0,n1)==false);

  std::cout << "All passed." << std::endl;
  
  return 1;
}