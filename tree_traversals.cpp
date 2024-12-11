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
    void inorder(Node *tree){
      if (tree==nullptr)
        return;
      
      inorder(tree->left);
      std::cout << tree->val << std::endl;
      inorder(tree->right);
      return; 
    };

    void preorder(Node *tree){
      if (tree==nullptr)
        return;
      
      std::cout << tree->val << std::endl;
      preorder(tree->left);
      preorder(tree->right);
      return; 
    };

    void postorder(Node *tree){
      if (tree==nullptr)
        return;
      
      postorder(tree->left);
      postorder(tree->right);
      std::cout << tree->val << std::endl;
      return; 
    };
};

int main() {
  Node *n0 = new Node(0);
  n0->left = new Node(1);
  n0->right = new Node(2);

  Solution *sol = new Solution();
  sol->inorder(n0); // 1 0 2
  std::cout << std::endl;
  sol->preorder(n0); // 0 1 2
  std::cout << std::endl;
  sol->postorder(n0); // 1 2 0
  std::cout << std::endl;
  return 1;
}