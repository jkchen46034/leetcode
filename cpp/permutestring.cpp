#include <iostream>
#include <string>

int main() {
  std::string s = "abcde";
  for (int i=0; i<s.size(); i++){
    for (int j=1; j<=s.size() && i+j<=s.size(); j++) {
      std::string sub = s.substr(i, j);
      std::cout << sub << std::endl;
    }
  }
}