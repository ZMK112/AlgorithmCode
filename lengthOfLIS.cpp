#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;


int lengthOfLIS1(vector<int>& nums) {
    if (nums.empty())
    {
        return 0;
    }
    int res = 1;
    vector<int> dp(nums.size(), 0);
    dp[0] = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                dp[i] = max(dp[j] +  1, dp[i]);
            }
        }
        cout<<dp[i];
        res = max(dp[i], res);
    }
    return res;
}




int lengthOfLIS2(vector<int>& nums) {
    if (nums.empty())
    {
        return 0;
    }
    vector<int> tmp;
    int res = 1;
    tmp.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {   
        if (nums[i] > tmp.back())
        {
            tmp.push_back(nums[i]);
        }
        else
        {
            for (int j = 0; j < tmp.size(); j++)
            {
                if (tmp[j] >= nums[i])
                {
                    tmp[j] = nums[i];
                    break;
                }
            }
        }
    }
    return tmp.size();
}


int lengthOfLIS3(vector<int>& nums) {
    if (nums.empty())
    {
        return 0;
    }
    int res = 0;
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                dp[i] = max(dp[i], dp[i - 1] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    return res;
}

int binary_search(vector<int>& res, int target)
{
    int begin = 0, end = res.size() - 1, index = -1;

    while (index == -1 && begin <= end)
    {
        int mid = (begin + end) / 2;
        if (res[mid] >= target)
        {
            if (mid == 0 || target > res[mid - 1])
            {
                index = mid - 1;
                break;
            }
            else
            {
                end = mid - 1;
            }
            
        }
        else 
        {
            if (mid == res.size() - 1 || target < res[mid + 1])
            {
                index = mid + 1;
                break;
            }
            else
                begin = mid + 1;
        }
    }
    return index;
}

int lengthOfLIS(vector<int>& nums) {
    int lens = nums.size();
    if (lens < 2)
    {
        return lens;
    }
    vector<int> res(lens, 0);
    res.push_back(nums[0]);
    for (int i = 0; i < lens; i++)
    {   
        if (nums[i] > res.back())
        {
            res.push_back(nums[i]);
        }
        else
        {
            int index = binary_search(res, nums[i]);
            res[index] = nums[i]; 
        }
    }
    return res.size();
}






