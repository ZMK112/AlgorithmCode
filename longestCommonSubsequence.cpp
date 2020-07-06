#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

string str1, str2;
int dp(int a, int b)
{
    if (a == -1 || b == -1)
    {
        return 0;
    }
    if (str1[a] == str2[b])
    {
        return dp(a - 1, b - 1) + 1;
    }
    else
    {
        return max(dp(a - 1, b), dp(a, b - 1));
    }
}

int longestCommonSubsequence2(string text1, string text2) {
    if (text1.empty() || text2.empty())
    {
        return 0;
    }
    str1 = text1, str2 = text2;
    return dp(text1.length(), text2.length());
}



int longestCommonSubsequence(string text1, string text2) {
    int lens1 = text1.length(), lens2 = text2.length();
    vector<vector<int>> dp(lens1, vector<int>(lens2, 0));

    for (int i = 1; i < lens1; i++)
    {
        for (int j = 1; j < lens2; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[lens1 - 1][lens2 - 1];
}