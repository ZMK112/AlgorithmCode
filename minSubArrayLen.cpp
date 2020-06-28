#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;


// 非连续的数组
// int minSubArrayLen(int s, vector<int>& nums) {
//     if (nums.empty())
//     {
//         return 0;
//     }
//     sort(nums.begin(), nums.end(), greater<int>());

//     int res = 0, num = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (res >= s)
//         {
//             return num;
//         }
//         else
//         {
//             res += nums[i];
//             num++;
//         }
//     }
//     return num;
// }

int minSubArrayLen(int s, vector<int>& nums) {
    if (nums.empty())
    {
        return 0;
    }
    int begin = 0, ans = 0, sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum >= s)
        {
            ans = min(ans, i - begin + 1);
            sum -= nums[begin];
            begin--;
        }
    }
    return ans;
}


























