#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

int maxSubArray1(vector<int>& nums) {
    if (nums.empty())
    {
        return 0;
    }
    int res = nums[0], cur = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        cur = max(cur + nums[i], nums[i]);
        res = max(res, cur);
    }
    return res;
}

int maxSubArray(vector<int>& nums) {
    if (nums.empty())
    {
        return 0;
    }
    vector<int> dp(nums.size() + 3);
    dp[0] = nums[0];
    int res = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        dp[i] = max(nums[i], nums[i] + dp[i - 1]);
        res = max(dp[i - 1], dp[i]);
    }
    return res;
}