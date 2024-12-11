/* climbing stairs*/

/*
There are n stairs, and a person standing at the bottom wants to climb stairs to reach the top. 
The person can climb either 1 stair or 2 stairs at a time, the task is to count the number of ways 
that a person can reach at the top.
*/

#include <iostream>
#include <cassert>

class Solution {
  public:
    int climb_stairs(int n);
};

int Solution::climb_stairs(int n) {
  if (n<=2) 
    return n;
  int n0=1;
  int n1=2;
  int val;
  for (int i=3; i<=n; i++) {
    val=n1+n0;
    n0=n1;
    n1=val; 

  }
  return val;
}

int main() {
  Solution* sol = new Solution();
  assert(sol->climb_stairs(1)==1);
  assert(sol->climb_stairs(2)==2);
  assert(sol->climb_stairs(3)==3);
  assert(sol->climb_stairs(4)==5);
  assert(sol->climb_stairs(5)==8);
  std::cout << "all passed" << std::endl;
}