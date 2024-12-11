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
    bool isMirrored(Node *tree1) {}
      return false;
    }
};

int main() {
  Node *n0 = new Node(0);
  n0->left = new Node(1);
  n0->right = new Node(1);

  Solution *sol = new Solution();
  assert(sol->isMirrored(n0)==true);

  std::cout << "All passed." << std::endl;
  return 1;
}