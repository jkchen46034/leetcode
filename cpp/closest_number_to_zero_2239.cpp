#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
  public:
    static int findCloseNumber(const vector<int>& nums);
};

int Solution::findCloseNumber(const vector<int>& nums) {
  int min = 0;
  for (int i=0; i<nums.size(); i++) {
    if (std::abs(nums[i]) < std::abs(nums[min])) {
      min = i;
    } else if (std::abs(nums[i]) == std::abs(nums[min])) {
      if (nums[min]<nums[i]) {
        min = i;
      }
    }
  }
  return nums[min];
}

int main() {
  std::cout << Solution::findCloseNumber(std::vector<int>{-4,-2,1,4,8}) << std::endl;
  std::cout << Solution::findCloseNumber(std::vector<int>{2,-1,1}) << std::endl;
}