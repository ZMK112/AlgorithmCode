#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) 
{
    int lens = nums.size();
    int sum = nums[0] + nums[1] + nums[2];
    int res = abs(sum - target);
    int ans = sum;

    if (lens == 3)
    {
        return ans;
    }
    
    sort(nums.begin(), nums.end());
    for (int i = 0; i < lens - 2; i++)
    {
        int front = i + 1;
        int rear = lens - 1;

        while (front < rear)
        {
            sum = nums[i] + nums[front] + nums[rear];
            int mins = abs(sum - target);

            if (mins < res)
            {
                res = mins;
                ans = sum;
            }
            
            if (sum < target)
            {
                front++;
            }
            else if(sum > target)
            {
                rear--;                
            }
            else
            {
                return ans;
            }
        }
    }
    return ans;
}