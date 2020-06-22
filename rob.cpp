#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

int rob1(vector<int>& nums) {
    if (nums.empty())
    {
        return 0;
    }
    vector<int> dp(nums.size() + 3);
    dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++)
    {   
        
        dp[i] = max(dp[i], nums[i] + dp[i - 2]);
    }
    return nums[nums.size() - 1];
}

int rob(vector<int>& nums) {
    if (nums.empty())
    {
        return 0;
    }
    if (nums.size() == 1)
    {
        return nums[0];
    }
    
    vector<int> dp(nums.size() + 3);
    int pre = nums[0], cur = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++)
    {
        int tmp = cur;
        cur = max(cur, pre + nums[i]);
        pre = tmp;
    }
    return cur;
}

int main()
{
    vector<int> nums = {1,2,3,1};
    rob(nums);
    cout<<"dasdads";
    return 0;
}