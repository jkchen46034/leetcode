#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public: 
    vector<vector<int>> solve(const vector<int>& v);
};

vector<vector<int>> Solution::solve(const vector<int>& v){
  vector<vector<int>> result;
  if (v.size()==0) {
    return {{}};
  }
  if (v.size()==1) {
    return {{v[0]}};
  }
  for (int i=0; i<v.size(); ++i) {
    std::vector<int> vtemp(v);
    int elem = vtemp[i];
    vtemp.erase(vtemp.begin()+i);
    vector<vector<int>> r = this->solve(vtemp);
    for (int j=0; j<r.size(); ++j) {
      r[j].insert(r[j].begin(), elem);
      result.push_back(r[j]);
    }
  }
  return result;
}

int main() {
  Solution sol;
  vector<vector<int>> r = sol.solve({0,1,2,3});
  for (int i=0; i<r.size(); i++) {
    for (int j=0; j<r[i].size(); j++) {
      std::cout << r[i][j] <<  " ";
    }
    std::cout << std::endl;
  }
}
