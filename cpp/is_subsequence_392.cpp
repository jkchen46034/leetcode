#include <iostream>

using namespace std;

class Solution {
  public:
  static bool isSubsequence(string s, string t); 
};

bool Solution::isSubsequence(string s, string t) {
  int j=0;
  for (int i=0; i<s.length() && j<t.length(); i++) {
    while (j<t.length()) {
      if (s[i]==t[j]) {
        if (i==s.length()-1) {
          return true;
        }
        j++;
        break;
      } else {
        j++;
      }
    }
  }
  return false;
}

int main() {
  std::cout << Solution::isSubsequence("abc", "ahbgdc") << std::endl;
  std::cout << Solution::isSubsequence("axc", "ahbgdc") << std::endl;
}