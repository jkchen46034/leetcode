#include <iostream>
#include <vector>

class Solution {
  public:
    std::string reverse(const std::string str);
};

std::string Solution::reverse(const std::string str){
  if (str=="") {
    return "";
  }
  std::string mystr = this->reverse(str.substr(1,str.size()-1));
  return mystr+str[0];
}

int main() {
  Solution *sol = new Solution();
  std::cout << sol->reverse("abcdef") << std::endl;
}