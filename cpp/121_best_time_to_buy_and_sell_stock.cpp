#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
  public:
  static int maxProfit(const vector<int>& prices);
};

int Solution::maxProfit(const vector<int>& prices) {
  int buy=0;
  int sell=1;
  int profit = 0;
  for (int i=0; sell<prices.size(); i++) {
    int gain = prices[sell]-prices[buy];
    if (gain>0) {
      if (gain > profit) {
        profit = gain;
      }
      sell++;
    } else {
      buy = sell;
      sell = buy+1;
    }
  }
  return profit; 
}

int main() {
  assert(Solution::maxProfit(std::vector<int>{7,1,5,3,6,4}) == 5 );
  assert(Solution::maxProfit(std::vector<int>{7,6,4,3,1}) == 0); 
  assert(Solution::maxProfit(std::vector<int>{7,2,5,3,6,1,100,94}) == 99);
}

