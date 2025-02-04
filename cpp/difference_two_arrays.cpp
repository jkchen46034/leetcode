/*
Find the difference of two arrays
*/
#include <iostream>
#include <vector>
#include <map>

class Solution {
  public:
  std::vector<std::vector<int>> difference_two_arrays(const std::vector<int> &a, const std::vector<int> &b);
};

std::vector<std::vector<int>> Solution::difference_two_arrays(const std::vector<int> &a, const std::vector<int> &b){
  std::vector<std::vector<int>> result;
  std::map<int, bool> m1;
  std::map<int, bool> m2;

  for (auto val: a) {
    m1[val] = true;
  }

  for (auto val: b) {
    m2[val] = true;
  }

  std::vector<int> temp;
  for (auto val: a) {
    if (m2.count(val) == 0) {
      temp.push_back(val);
    }
  }
  result.push_back(temp);

  temp.clear(); 
  for (auto val: b) {
    if (m1.count(val) == 0) {
      temp.push_back(val);
    }
  }
  result.push_back(temp);

  return result;
}


int main() {
  Solution *sol = new Solution;
  std::vector<std::vector<int>> results = sol->difference_two_arrays(std::vector<int>{1,2,4,5}, std::vector<int>{3,4,5,6});
  for (auto v: results) {
    for (auto val: v) {
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }
  return 1;
}
