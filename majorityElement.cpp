#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

bool check(vector<int>& nums, int num)
{
    int time = 0;
    bool res = false;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == num)
        {
            time++;
        }
        if (time * 2 > nums.size())
        {
            res = true;
        }
        
    }
    return res;
}

int majorityElement(vector<int>& nums) {
    if (nums.empty())
    {
        return 0;
    }
    int res = nums[0];
    int times = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (times == 0)
        {
            res = nums[i];
            times = 1;
        }
        else if (nums[i] == res)
        {
            times++;
        }
        else
        {
            times--;
        }
    }
    if (!check(nums, res))
    {
        res = 0;
    }
    return res;
}