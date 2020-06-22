#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

// bool canJump(vector<int>& nums) {
//     if(nums.empty()) return true;
//     vector<int> index;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         index.push_back(i + nums[i]);
//     }
//     int jump = 0;
//     int maxIndex = index[0];
//     while (jump < nums.size() && jump <= maxIndex)
//     {
//         if (maxIndex >= nums.size())
//         {
//             return true;
//         }
        
//         maxIndex = max(maxIndex, index[jump++]);
//     }
//     if (jump == nums.size())
//     {
//         return true;
//     }
//     return false;
// }

// int jump(vector<int>& nums) {
//     if(nums.size() < 2) 
//         return 0;
//     int cur = nums[0];
//     int pre = nums[0];
//     int jump = 1;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (i > cur)
//         {
//             jump++;
//             cur = pre;
//         }
//         if (pre < nums[i] + 1)
//         {
//             pre = nums[i] + 1;
//         }
//     }
//     return jump;
// }

bool canJump(vector<int>& nums) {
    int maxIndex = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (i < maxIndex)
        {
            maxIndex = max(maxIndex, i + nums[i]);
        }
        if (maxIndex > nums.size() - 2)
        {
            return true;
        }
    }
    return false;
}

int jump(vector<int>& nums) {
    int lens = nums.size();
    if (lens < 2)
    {
        return lens;
    }
    int cur = nums[0], pre = nums[0];
    int res = 0;
    for (int i = 1; i < lens; i++)
    {
        if (i > cur)
        {
            cur = pre;
            res++;
        }
        pre = max(pre, nums[i] + i);
    }
    return res;
}


int findMinArrowShots(vector<vector<int>>& points) 
{
    if(points.empty()) return 0;
    sort(points.begin(), points.end());
    int ph = points[0][0];
    int pr = points[0][1];
    int lens = points.size();
    int res = 1;

    for (int i = 0; i < lens; i++)
    {
        if (points[i][0] <= pr)
        {
            ph = points[i][0];
            pr = min(pr, points[i][1]);
        }
        else
        {
            res++;
            ph = points[i][0];
            pr = points[i][1];
        }
    }
    return res;
}