/*
Given a string s, return true if the s can be palindrome after deleting at most one character from it.
*/

#include <iostream>
#include <cassert>

class Solution {
  public:
  bool valid_palindrome(std::string s) {
    for (int i=0, j=s.length()-1; i<s.length()/2; i++, j--) {
      if (s[i] != s[j]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution* sol = new Solution();
  assert(sol->valid_palindrome("a")==true);
  assert(sol->valid_palindrome("aa")==true);
  assert(sol->valid_palindrome("abcba")==true);
  assert(sol->valid_palindrome("abcba")==true);
  assert(sol->valid_palindrome("ab")==false);
  assert(sol->valid_palindrome("abcaa")==false);
  assert(sol->valid_palindrome("abcdba")==false);
  std::cout << "all passed" << std::endl;
}