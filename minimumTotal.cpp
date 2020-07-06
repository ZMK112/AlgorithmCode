#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int lens = triangle.size();
    if (!lens)
    {
        return 0;
    }
    vector<vector<int>> dp(lens, vector<int>(triangle[0].size(), 0));
    for (int i = 0; i < triangle[lens - 1].size(); i++)
    {
        dp[lens - 1][i] = triangle[lens - 1][i];
    }
    
    for (int j = lens - 2; j >= 0; j++)
    {
        for (int i = 0; i < triangle[j].size(); i++)
        {
            dp[j][i] = min(dp[j + 1][i], dp[j + 1][i + 1]) + triangle[j][i];
        }
    }
    return dp[0][0];
}