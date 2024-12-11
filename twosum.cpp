/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
    public:
    std::vector<int> twoSum(const vector<int>& nums, int target);
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
  Solution *sol = new Solution();
  std::vector<int> result = sol->twoSum(std::vector<int>{1,3,5,7,9}, 8);
  for (int index:result) {
    std::cout << index << std::endl;
  }
  delete sol;
  sol = 0;
}

/*
osx-jkchen:leetcode juikun1001$ g++ twosum.cpp --std=c++11
osx-jkchen:leetcode juikun1001$ ./a.out
2, 1
*/