#include <iostream>

int max(int a, int b) {
  if (a > b) 
    return a;
  return b;
}

struct Node {
  int val;
  Node *left, *right;
  public:
  Node(int val):val(val),left(nullptr), right(nullptr){};
};

class Solution{
  public:
    int height(Node *node){
      if (node==nullptr)
        return 0;

      return max(height(node->left), height(node->right)) + 1;
    }
};

int main() {
  Node *n0 = new Node(0);
  n0->left = new Node(1);
  n0->right = new Node(2);
  n0->right->right = new Node(3);

  Solution *sol = new Solution();
  std::cout << sol->height(n0) << std::endl;
  return 1;
}