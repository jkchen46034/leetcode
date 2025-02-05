#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
    static std::vector<int> twoSum(const vector<int>& nums, int target);
};

std::vector<int> Solution::twoSum(const vector<int>& nums, int target) {
    std::unordered_map<int, int> m;
    for (int i=0; i<nums.size(); i++) {
        int diff = target - nums[i];
        if (m.contains(diff)) {
            return {i, m[diff]};
        }
        m[nums[i]] = i;
    }
    return {};
}

int main() {
  std::vector<int> result = Solution::twoSum(std::vector<int>{1,3,5,7,9}, 12);
  for (int index:result) {
    std::cout << index << std::endl;
  }
}
// g++ 1_two_sum.cpp -std=c++2a