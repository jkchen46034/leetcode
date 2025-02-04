// C++ program to count number of ways to reach
// nth stair using recursion

#include <iostream>

int countWays(int n) {
    if (n == 0 || n == 1)
        return 1;

    return countWays(n - 1) + countWays(n - 2);
}

int main() {
    int n = 2;
    std::cout << countWays(n) << std::endl;
    return 0;
}
