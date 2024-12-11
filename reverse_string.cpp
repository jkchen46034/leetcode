#include <iostream>
#include <vector>
#include <cassert>

class Solution {
  public:
    void reverse_string(std::vector<char>& str);
};

void Solution::reverse_string(std::vector<char>& str) {
  for (int i=0, j=str.size()-1; i<str.size()/2; i++,j--) {
    std::swap(str[i],str[j]);
  }
}

int main() {
  Solution* sol = new Solution();
  std::vector<char>str={'a', 'b', 'c', 'd', 'e'};
  sol->reverse_string(str);
  for(auto c:str) {
    std::cout << c << std::endl;
  }
}