#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
    public:
    static std::vector<int> twoSum(const vector<int>& nums, int target);
};

std::vector<int> Solution::twoSum(const vector<int>& nums, int target) {
    std::map<int, int> m;
    for (int i=0; i<nums.size(); i++) {
        if (m.count(target-nums[i])) {
            return {i, m[target-nums[i]]};
        } else {
            m[nums[i]] = i;
        }
    }
    return {};
}

int main() {
  std::vector<int> result = Solution::twoSum(std::vector<int>{1,3,5,7,9}, 8);
  for (int index:result) {
    std::cout << index << std::endl;
  }
}