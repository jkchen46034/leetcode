#include <iostream>
/*
 * Complete the 'fizzBuzz' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void fizzBuzz(int n) {
    for (int i=1; i<=n; i++) {
        if ((i%15)==0)
            std::cout << "FizzBuzz" << std::endl;
            continue;
        if ((i%3)==0) 
            std::cout << "Fizz" << std::endl;
            continue;
        if ((i%5)==0)
            std::cout << "Buzz" << std::endl;
            continue;
        std::cout << i << std::endl;
    }
}

int main() {
  fizzBuzz(15);
}