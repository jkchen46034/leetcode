#include <iostream>
#include <cassert>

class Solution {
  public:
    int number_of_one_bits(int val) {
      int bits=0;
      while(val>0) {
        if ((val & 0x01) == 1) {
          bits++;
        }
        val=val>>1;
      }
      return bits;
    }
};

int main() {
  Solution* sol=new Solution();
  assert(sol->number_of_one_bits(0)==0);
  assert(sol->number_of_one_bits(1)==1);
  assert(sol->number_of_one_bits(2)==1);
  assert(sol->number_of_one_bits(128)==1);
  assert(sol->number_of_one_bits(192)==2);
  std::cout << "all passed." << std::endl;
}