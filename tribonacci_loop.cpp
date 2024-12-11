/*
The Tribonacci sequence Tn is defined as follows: 
T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
Given n, return the value of Tn.
*/

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
  public:
  int tribonacci(int n);
};

int Solution::tribonacci(int n) {
  if (n==0) {
    return 0;
  } else if (n==1 || n==2)  {
    return 1;
  }
  int n0=0, n1=1, n2=1;
  int val;
  for (int i=3; i<=n; i++) {
    val = n2+n1+n0;
    n0=n1;
    n1=n2;
    n2=val;
  }
  return val;
}

int main() {
  Solution* sol = new Solution();
  assert(sol->tribonacci(2)==1);
  assert(sol->tribonacci(3)==2);
  assert(sol->tribonacci(4)==4);
  assert(sol->tribonacci(5)==7);
  assert(sol->tribonacci(6)==13);
  std::cout << "all passed" << std::endl;
}
