#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

int findBestValue(vector<int>& arr, int target) {
    int lens = arr.size();
    if (!lens)
    {
        return 0;
    }
    sort(arr.begin(), arr.end());
    vector<int> nums(lens + 1);
    int diff = 999999999, res = 0;
    for (int i = 1; i <= lens; i++)
    {
        nums[i] = nums[i - 1] + arr[i - 1];
    }

    int r = *max_element(arr.begin(), arr.end());
    int left = 0;
    while (left <= r)
    {
        int mid = (left + r) / 2;
        auto p = lower_bound(arr.begin(), arr.end(), mid);
        int sum = nums[p - arr.begin()] + (arr.end() - p) * left;

        if (sum < target)
        {
            res = mid;
            mid += 1;
        }
        else
        {
            mid -= 1;
        }
    }
    return res;    
}