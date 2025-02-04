#include <iostream>

using namespace std;

class Solution {
  public:
  static string mergeAlternatively(const string w1, const string w2) {
    string result;
    for (int i=0; i<w1.length(); ++i) {
      result.append(w1,i,1);
      if (i<w2.length()) {
        result.append(w2,i,1);
      }
    }
    if (w1.length()<w2.length()) {
      result.append(w2, w1.length(), w2.length()-w1.length());
    }
    return result;
  }
};

int main() {
  std::cout << Solution::mergeAlternatively("abc", "pqrs") << std::endl;
  std::cout << Solution::mergeAlternatively("abcde", "pqr") << std::endl;
  std::cout << Solution::mergeAlternatively("abc", "pqrst") << std::endl;
}