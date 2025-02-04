#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>

using namespace std;

class Solution {
  public: 
    vector<vector<int>> solve(const vector<int>& v);
    vector<vector<int>> solve_unique(std::vector<pair<int, int>>& vp);
};

vector<vector<int>> Solution::solve(const vector<int>& v){
  // vector into map with count
  unordered_map<int, int> mymap;
  for (int i=0; i<v.size(); ++i) {
    if (mymap[v[i]]>0) {
      mymap[v[i]]=mymap[v[i]]+1;
    } else {
      mymap[v[i]]=1;
    }
  }
  std::vector<pair<int,int>> vp;
  for (auto it=mymap.begin(); it!=mymap.end(); ++it) {
    vp.push_back(std::make_pair(it->first, it->second));
  }
  return solve_unique(vp);
}

vector<vector<int>> Solution::solve_unique(vector<pair<int, int>>& vp) {
  vector<vector<int>> result;
  if (vp.size()==0) {
    return {{}};
  }
  if (vp.size()==1 && vp[0].second == 1) {
    return {{vp[0].first}};
  }
  for (int i=0; i<vp.size(); ++i) {
    std::vector<pair<int, int>> vtemp(vp);
    std::pair<int,int> myelem = vtemp[i];
    vtemp[i].second = vtemp[i].second - 1;
    if (vtemp[i].second == 0) {
      vtemp.erase(vtemp.begin()+i);
    }
    vector<vector<int>> r = this->solve_unique(vtemp);
    for (int j=0; j<r.size(); ++j) {
      r[j].insert(r[j].begin(), myelem.first);
      result.push_back(r[j]);
    }
  }
  return result;
}

int main() {
  Solution sol;
  vector<vector<int>> r = sol.solve({1,1,2});
  for (int i=0; i<r.size(); i++) {
    for (int j=0; j<r[i].size(); j++) {
      std::cout << r[i][j] <<  " ";
    }
    std::cout << std::endl;
  }
}
