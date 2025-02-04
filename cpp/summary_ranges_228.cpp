#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
  public:
  static vector<string> summaryRanges(const vector<int>& nums);
};

vector<string> Solution::summaryRanges(const vector<int>& nums) {
  vector<string> result;
  int j=0;
  int k=1;
  while (k<nums.size()) {
    if (nums[k]-nums[k-1] != 1) {
      stringstream ss;
      ss <<  nums[j] << "->" << nums[k-1];
      result.push_back(ss.str());
      j=k;
      k=k+1;
    } else {
      k++;
    }
  }
  stringstream ss;
  ss <<  nums[j] << "->" << nums[k-1];
  result.push_back(ss.str());
  return result;
}

int main() {
  std::vector<string> result = Solution::summaryRanges({0, 1, 2, 4, 5, 7});
  for (int i=0; i<result.size(); i++) {
    std::cout << result[i] << std::endl;
  }
}