#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

int climbStairs1(int n) {
    if(!n) return 0;
    int tmp, cur = 1, pre = 1;
    for (int i = 0; i < n; i++)
    {
        tmp = cur;
        cur += pre;
        pre = tmp; 
    }
    return cur;
}

int climbStairs2(int n) {
    if (n == 1 && n == 2)
    {
        return n;
    }
    int sum = climbStairs2(n - 1) + climbStairs2(n - 2);
    return sum;
}

int climbStairs(int n) {
    vector<int> nums(n + 3);
    nums[0] = 1, nums[1] = 1, nums[2];
    for (int i = 0; i < n; i++)
    {
        nums[i] = nums[i - 2] + nums[i - 1];
    }
    return nums[n - 1];
}