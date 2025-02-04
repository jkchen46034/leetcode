// merge in place

#include <iostream>
#include <vector>

class Solution{
  public:
  void merge(std::vector<int> &l1, std::vector<int>l2);
};

void Solution::merge(std::vector<int> &l1, std::vector<int>l2) {
  int i = l1.size() - l2.size() - 1;
  int j = l2.size() - 1;
  int k = l1.size() - 1;

  while (j>=0) {
    if (i>=0 && l1[i]>=l2[j]) {
      l1[k--] = l1[i--];
    } else {
      l1[k--] = l2[j--];
    }
  }
}

int main() {
  Solution* sol = new Solution();
  std::vector<int> v1 = {2,5,6,0,0,0};
  std::vector<int> v2 = {1,4,5};
  sol->merge(v1, v2);
  for (auto v:v1) {
    std::cout << v << " ";
  }
  std::cout << std::endl;
}