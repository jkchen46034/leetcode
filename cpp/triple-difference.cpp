/*
You are given a 0-indexed array of positive integers nums. 
Find the number of triplets (i, j, k) that meet the following conditions:

0 <= i < j < k < nums.length
nums[i], nums[j], and nums[k] are pairwise distinct.
In other words, nums[i] != nums[j], nums[i] != nums[k], and nums[j] != nums[k].
Return the number of triplets that meet the conditions.
*/
#include <iostream>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int> > tripple_difference(const std::vector<int> &nums);
};

std::vector<std::vector<int> > Solution::tripple_difference(const std::vector<int> &nums) {
  std::vector<std::vector<int> > result;
  for (int i=0; i<nums.size(); i++) {
    for (int j=i+1; j<nums.size(); j++) {
      for (int k=j+1; k<nums.size(); k++) {
        if (nums[i] != nums[j] && nums[j]!= nums[k] && nums[i]!=nums[k])
          result.push_back({nums[i], nums[j], nums[k]});
      }
    }
  }
  return result;
}

void print_vector(std::vector<std::vector<int>> nums) {
  for (auto res:nums) {
    for (auto val:res) {
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }
}

int main() {
  Solution *sol = new Solution();
  print_vector(sol->tripple_difference(std::vector<int>{4,4,2,4,3}));
  print_vector(sol->tripple_difference(std::vector<int>{1,1,1,1,1}));
  print_vector(sol->tripple_difference(std::vector<int>{1,2,3,2,1}));
  return 1;
}