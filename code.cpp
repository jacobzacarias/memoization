#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::string longestCommonSubsequence(const std::string& str1, const std::string& str2, int i, int j,
                                     std::unordered_map<std::pair<int, int>, std::string>& memo)
{
    // Check for valid indices
    if (i <= 0 || j <= 0)
        return "";

    // Check if result is already memoized
    if (memo.find({i, j}) != memo.end())
        return memo[{i, j}];

    if (str1[i - 1] == str2[j - 1])
    {
        memo[{i, j}] = longestCommonSubsequence(str1, str2, i - 1, j - 1, memo) + str1[i - 1];
    }
    else
    {
        std::string lcs1 = longestCommonSubsequence(str1, str2, i - 1, j, memo);
        std::string lcs2 = longestCommonSubsequence(str1, str2, i, j - 1, memo);
        memo[{i, j}] = (lcs1.length() > lcs2.length()) ? lcs1 : lcs2;
    }

    return memo[{i, j}];
}

int main()
{
    std::string str1, str2;
    std::cout << "Enter the first string: ";
    std::cin >> str1;
    std::cout << "Enter the second string: ";
    std::cin >> str2;

    std::unordered_map<std::pair<int, int>, std::string> memo;
    std::string lcs = longestCommonSubsequence(str1, str2, str1.length(), str2.length(), memo);

    std::cout << "The Longest Common Subsequence is: " << lcs << std::endl;

    return 0;
}
