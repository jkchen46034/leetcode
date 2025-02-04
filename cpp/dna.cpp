#include <iostream>
#include <vector>
using namespace std;

/*
 * Complete the 'isSpecialSequence' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING dna_sequence as parameter.
 */


bool isPalindrome(std::string str) {
    if (str==""){
      return false;
    }
    for (int i=0; i<str.size(); i++) {
        if (str[i] != str[str.size()-i-1])
            return false;
    }
    return true;
}

bool isPalindrome_helper(std::string str) {
    // remove one char and 
    std::string strcopy = str;
    for (int i=0;i<str.size(); i++) {
      std::string strcopy = str;
      strcopy.erase(strcopy.begin()+i);
      if (isPalindrome(strcopy)) {
        return true;
      }
    }
    return false;
}

string isSpecialSequence(string str) {
    for (int i=1; i<str.size()-1; i++){
        std::string str1 = str.substr(0,i);
        std::string str2 = str.substr(i, str.size());
        std::cout << str1 << ", " << str2 << std::endl;
        if (isPalindrome_helper(str1) && isPalindrome_helper(str2))
            return "YES";
    }
    return "FALSE";
}


int main() {
  //std::cout<<isSpecialSequence("abcad ") << std::endl;
  std::cout<<isSpecialSequence("d") << std::endl;
}