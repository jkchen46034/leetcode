/*
Given a string s, find the length of the longest 
substring without repeating characters.
 */
#include <iostream>
#include <map>
#include <string>
#include <cassert>

class Solution {
  public:
   int LengthLogest(std::string s);
};

int Solution::LengthLogest(std::string s) {
  std::map<char, int> mymap;

  int left = 0; 
  int right = -1;
  int max = 0;
    
  for (int i=0; i<s.size(); i++) {
    if (mymap.count(s[i])==0) {
      mymap[s[i]] = i;
      right = i;
      //std::cout << left << ", " << right <<  ", " << right -left + 1 << std::endl;
      if (right-left+1 > max) {
        max = right - left + 1;
      }
    } else {
      left = mymap[s[i]]+1;
      mymap[s[i]] = i;
    }
  }
  return max;
}

int main()
{
    Solution *solution = new Solution();
    assert(solution->LengthLogest("pwwkew")==3);
    assert(solution->LengthLogest("aaaaaa")==1);
    assert(solution->LengthLogest("abcabcbb")==3);
    assert(solution->LengthLogest("abcabcdae")==5);
    assert(solution->LengthLogest("abcdefg")==7);
    assert(solution->LengthLogest("abcdefabcdef")==6);
    std::cout<<"Hello World, all passed" << std::endl;
    return 0;
}