#include <iostream>
#include <vector>

class CircularQueue {
  private:
    std::vector<int> *elem;
    int n; 
    int front;
    int rear;
  public:
    CircularQueue(int n): n(n), front(-1), rear(-1) {
      elem=new std::vector<int>(n, 0);
    } 

    int Front() {
      if (front==-1) 
        return -1;
      else 
        return elem->at(front);
      return -1;
    }

    int Rear() {
      if (rear==-1) 
        return -1;
      else 
        return elem->at(rear);
      return 1;
    }

    bool enQueue(int value) {
      return true;
    }

    bool deQueue(int value) {
      return true;
    }

    bool isEmpty() {
      return true;
    }

    bool isFull() {
      return true;
    }
};