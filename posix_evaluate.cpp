#include <iostream>
#include <vector>
#include <cassert>

class Solution {
  public:
    int solve(const std::string& s);
};

int Solution::solve(const std::string& s) {
  std::vector<int> v;
  for (int i=0; i<s.size(); i++) {
    char c=s[i];
    if (isalnum(c)) {
      v.push_back(c-'0');
    } else {
      int op2 = v.back();
      v.pop_back();
      int op1 = v.back();
      v.pop_back();
      switch(c) {
        case '*':
          v.push_back(op1*op2);
          break;
        case '+':
          v.push_back(op1+op2);
          break;
        case '-':
          v.push_back(op1-op2);
          break;
      }
    }
  }
  return v.back();
}

int main() {
  Solution* sol = new Solution();
  assert(sol->solve("231*+9-")==-4);
  assert(sol->solve("21-23*+")==7);
  std::cout << "all passed" << std::endl;
}
/*
2+3*1-9
231*+9-
*/

