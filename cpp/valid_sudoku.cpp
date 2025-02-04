#include <iostream>
#include <vector>
#include <cassert>

typedef std::vector<std::vector<char>> Matrix;

class Solution {
  public:
    bool isValid(const Matrix& matrix);
};

bool Solution::isValid(const Matrix& matrix){
  int rows = matrix.size();
  int columns = matrix[0].size();

  for (int i=0; i<rows; i++){
    std::vector<bool> seen(10, false);
    for (int j=0; j<columns; j++) {
      char c = matrix[i][j];
      if (isalnum(c)) {
        int val = c - '0';
        if (seen[val]) {
          return false;
        }
        seen[val] = true;
      }
    } 
  }
  for (int j=0; j<columns; j++){
    std::vector<bool> seen(10, false);
    for (int i=0; i<rows; i++) {
      char c = matrix[i][j];
      if (isalnum(c)) {
        int val = c - '0';
        if (seen[val]) {
          return false;
        } 
        seen[val] = true;
      }
    } 
  }
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      std::vector<bool> seen(10, false);
      for (int k=0; k<3; k++){
        for (int q=0; q<3; q++) {
          char c = matrix[3*i+k][3*j+q];
          if (isalnum(c)) {
            int val = c - '0';
            if (seen[val]) {
              return false;
            } 
            seen[val] = true;
          }
        }
      }
    } 
  }
  return true;
}

int main() {
  Matrix matrix = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}};
  
  Solution* sol=new Solution();
  assert(sol->isValid(matrix)==true);
  matrix[0][0]='3';
  assert(sol->isValid(matrix)==false);
  std::cout << "All passed" << std::endl;
}


