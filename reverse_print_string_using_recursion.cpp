#include <iostream>
#include <vector>

class Solution {
  public:
    void print_reverse(const std::string str);
};

void Solution::print_reverse(const std::string str){
  if (str=="") {
    return;
  }
  print_reverse(str.substr(1,str.size()-1));
  std::cout << str[0] << std::endl;
}

int main() {
  Solution *sol = new Solution();
  sol->print_reverse("abcdef");
}