#include <iostream>

struct Node {
    int val;
    Node* next;
    Node(int val) : val(val), next(nullptr) {}
};

Node* reverseList(Node *node) {
    if (!node|| !node->next) {
        return node; 
    }

    Node* newHead = reverseList(node->next);
    node->next->next = node; 
    node->next = nullptr; 
    return newHead;
}

void print_list(Node *node) {
  while (node) {
    std::cout << node->val << std::endl;
    node=node->next;
  }
}

int main() {
    Node *node= new Node(1);
    node->next = new Node(2);
    node->next->next = new Node(3);
    node->next->next->next = new Node(4);

    print_list(reverseList(node));

    return 0;
}