#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
  static string longest_common_prefix(const std::vector<string> &strs);
};

string Solution::longest_common_prefix(const std::vector<string> &strs) {
  int j=0;
  for (int i=0; i<strs.size(); i++) {
    for (int k=0; k<strs.size(); k++) {
      if (strs[0][j]!=strs[k][j]) {
          return strs[i].substr(0, j);
      }
    }
    j++;
  }
  return strs[1];
}

int main() {
  std::cout << Solution::longest_common_prefix({"flower", "flow", "flight"}) << std::endl;
  std::cout << Solution::longest_common_prefix({"dog", "racecar", "car"}) << std::endl;
  std::cout << Solution::longest_common_prefix({"dog", "dog", "dog"}) << std::endl;
}