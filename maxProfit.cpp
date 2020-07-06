#include <iostream>
#include <vector>
using namespace std;

int maxProfit2(vector<int>& prices) {
    int maxRes = 0;
    for (int i = 0; i < prices.size() - 1; i++)
    {
        for (int j = i + 1; j < prices.size(); j++)
        {
            maxRes = max(maxRes, prices[j] - prices[i]);
        }
    }
    return maxRes;
}

int maxProfit(vector<int>& prices){
    int minPrice = 99999999999;
    int maxRes = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < minPrice)
        {
            minPrice = prices[i];
        }

        maxRes = max(prices[i] - minPrice, maxRes);
    }
    return maxRes;
}

int maxSubArray(vector<int>& nums)
{
    int pre = 0;
    int maxRes = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        pre = max(pre, pre + nums[i]);
        maxRes = max(maxRes, pre);
    }
    return maxRes;
}

