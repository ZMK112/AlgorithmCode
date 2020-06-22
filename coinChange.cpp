#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    if (coins.empty())
    {
        return 0;
    }
    vector<int> dp(amount+1, -1); //dp从1开始，所以是amount + 1
    dp[0] = 0;
    for (int i = 0; i < coins.size(); i++)
    {
        if(coins[i] <= amount) // coins的面额可能越界
        dp[coins[i]] = 1;
    }
    // cout<<dp[0];
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != -1)
            {
                // cout<<i;
                dp[i] = dp[i] == -1 ? dp[i - coins[j]] + 1 : min(dp[i], dp[i - coins[j]] + 1);
                // if(dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1)
                //     dp[i] = dp[i - coins[j]] + 1;
            }
        }
    }
    return dp[amount];
}