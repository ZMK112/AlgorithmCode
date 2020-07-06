#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int rows = dungeon.size();
    int columns = dungeon[0].size();

    vector<vector<int>> dp(rows, vector<int>(columns, 0));
    dp[rows - 1][columns - 1] = max(1, 1 - dungeon[rows - 1][columns - 1]);

    for (int i = rows - 2; i >= 0 ; i--)
    {
        dp[i][columns - 1] = max(1, dp[i + 1][columns - 1] - dungeon[i][columns - 1]);
    }
    
    for (int j = columns - 2; j >= 0 ; j--)
    {
        dp[rows - 1][j] = max(1, dp[rows - 1][j + 1] - dungeon[rows - 1][j]);
    }
    
    for (int i = rows - 2; i >= 0; i--)
    {
        for (int j = columns - 2; j >= 0; j--)
        {
            int mins = min(dp[i + 1][j], dp[i][j + 1]);
            dp[i][j] = max(1, mins - dungeon[i][j]);
        }
    }
    return dp[0][0];
}