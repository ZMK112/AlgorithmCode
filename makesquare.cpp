#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
using namespace std;


bool generates(int i, int lens, vector<int>& nums, vector<int>& buck)
{
    if (i >= nums.size())
    {
        return (buck[0] == lens && buck[1] == lens && buck[2] == lens && buck[3] == lens);
    }

    for (int j = 0; j < 4; j++)
    {
        if (buck[j] + nums[i] > lens)
        {
            continue;
        }
        buck[j] += nums[i];
        if (generates(i + 1, lens, nums, buck))
        {
            return true;
        }
        buck[j] -= nums[i];
    }
    return false;
}

bool makesquare(vector<int>& nums) {
    if (nums.empty())
    {
        return false;
    }

    int res = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        res += nums[i];
    }
    
    if (res % 4)
    {
        return false;
    }
    
    sort(nums.begin(), nums.end(), greater<int>());

    vector<int> buck(4, 0);

    bool ans = generates(0, res / 4, nums, buck);
    return ans;
}