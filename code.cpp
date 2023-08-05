#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// Function to find the Longest Common Subsequence of two strings
std::string longestCommonSubsequence(const std::string& str1, const std::string& str2, int i, int j,
                                     std::unordered_map<std::string, std::string>& memo)
{
    if (i == 0 || j == 0)
        return "";

    std::string key = std::to_string(i) + "|" + std::to_string(j);
    if (memo.find(key) != memo.end())
        return memo[key];

    if (str1[i - 1] == str2[j - 1])
    {
        memo[key] = longestCommonSubsequence(str1, str2, i - 1, j - 1, memo) + str1[i - 1];
    }
    else
    {
        std::string lcs1 = longestCommonSubsequence(str1, str2, i - 1, j, memo);
        std::string lcs2 = longestCommonSubsequence(str1, str2, i, j - 1, memo);
        memo[key] = (lcs1.length() > lcs2.length()) ? lcs1 : lcs2;
    }

    return memo[key];
}

int main()
{
    std::string str1, str2;
    std::cout << "Enter the first string: ";
    std::cin >> str1;
    std::cout << "Enter the second string: ";
    std::cin >> str2;

    std::unordered_map<std::string, std::string> memo;
    std::string lcs = longestCommonSubsequence(str1, str2, str1.length(), str2.length(), memo);

    std::cout << "The Longest Common Subsequence is: " << lcs << std::endl;

    return 0;
}
