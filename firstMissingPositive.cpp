#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    
    for(auto& x : nums)
    {
        if (x <= 0)
        {
            x = n + 1;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        int tmp = abs(nums[i]);
        if (tmp <= n)
        {
            nums[tmp - 1] = -abs(nums[tmp - 1]);
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            return i + 1;
        }
    }
    
    return n + 1;
}