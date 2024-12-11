/*
Ways of different sums by alternating + and - to each number and perform the sum of vectors
*/
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <cassert>

class Solution {
  public:
    int sum(const std::vector<int>& nums) {
      std::vector<int> vals;
      vals.push_back(nums[0]);
      vals.push_back(-nums[0]);
      for (int i=1; i<nums.size(); i++) {
        int last = vals.size();
        const int valsize = vals.size();
        for (int j=0; j<valsize; j++) {
          vals.push_back(vals[j]+nums[i]);
          vals.push_back(vals[j]-nums[i]);
        }
        vals.erase(vals.begin(), vals.begin()+last);
      }

      std::map<int, bool>m;
      for (auto val: vals) {
        m[val] = true;
      }

      return m.size();
    }
};

int main() {
  Solution* sol = new Solution();
  assert(sol->sum(std::vector<int>{1})==2);
  assert(sol->sum(std::vector<int>{1,2})==4);
  assert(sol->sum(std::vector<int>{1,2,1})==5);
  assert(sol->sum(std::vector<int>{1,2,1,2})==7);
  std::cout << "All passed." << std::endl;
}