#include <iostream>
#include <unordered_map>

// Function to calculate the factorial of a number using memoization
unsigned long long factorial(int n, std::unordered_map<int, unsigned long long>& memo)
{
    if (n <= 1)
        return 1;

    if (memo.find(n) != memo.end())
        return memo[n];

    unsigned long long fact = n * factorial(n - 1, memo);
    memo[n] = fact;

    return fact;
}

int main()
{
    int n;
    std::cout << "Enter a number to calculate its factorial: ";
    std::cin >> n;

    std::unordered_map<int, unsigned long long> memo;
    unsigned long long result = factorial(n, memo);

    std::cout << "The factorial of " << n << " is: " << result << std::endl;

    return 0;
}
