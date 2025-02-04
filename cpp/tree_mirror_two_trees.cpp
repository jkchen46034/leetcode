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
    bool isMirrored(Node *tree1, Node *tree2){
      if (tree1==nullptr && tree2==nullptr) 
        return true;

      if (tree1==nullptr || tree2==nullptr) 
        return false;

      return (tree1->val==tree2->val) && isMirrored(tree1->left, tree2->right) && isMirrored(tree1->right, tree2->left);
    }
};

int main() {
  Node *n0 = new Node(0);
  n0->left = new Node(1);
  n0->right = new Node(2);

  Node *n1 = new Node(0);
  n1->left = new Node(2);
  n1->right = new Node(1);

  Solution *sol = new Solution();
  assert(sol->isMirrored(n0,n1)==true);

  n0->right->right = new Node(3);
  n1->left->left = new Node(3);
  assert(sol->isMirrored(n0,n1)==true);

  n0->right->right->right = new Node(4);
  n1->left->left->right = new Node(4);
  assert(sol->isMirrored(n0,n1)==false);
  std::cout << "All passed." << std::endl;
  
  return 1;
}