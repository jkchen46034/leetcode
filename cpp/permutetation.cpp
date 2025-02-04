#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public: 
    vector<int> solve(const vector<int>& v);
};

vector<int> Solution::solve(const vector<int>& v){
  vector<int> result;
  for (int i=0; i<v.size(); ++i) {
    std::vector<int> vtemp(v);
    int elem = vtemp[i];
    vtemp.erase(vtemp.begin()+i);
    vector<int> r = this.solve(vtemp);

  }

}
