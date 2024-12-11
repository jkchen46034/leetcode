#include <iostream>
#include <cmath>

class Solution {
  public:
  bool is_power_of_four(int val) {
    int s = int(sqrt(sqrt(val)));
    if (s*s*s*s==val)
      return true;
    return false;
  }
};

int main() {
  Solution* sol=new Solution();
  assert(sol->is_power_of_four(1)==true);
  assert(sol->is_power_of_four(4)==false);
  assert(sol->is_power_of_four(16)==true);
  assert(sol->is_power_of_four(81)==true);
  assert(sol->is_power_of_four(27)==false);
  assert(sol->is_power_of_four(64)==false);
  assert(sol->is_power_of_four(1827)==false);
  std::cout << "all passed." << std::endl;
  return 1;
}