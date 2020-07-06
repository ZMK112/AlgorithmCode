#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

vector<vector<int>> res;

void combinationSum(vector<int>& nums, vector<int>& item, int i, int sum, int target)
{
    if (i >= nums.size() || sum > target)
    {
        return;
    }
    sum += nums[i];
    item.push_back(nums[i]);
    if (sum == target)
    {
        res.push_back(item);
    }
    combinationSum(nums, item, i + 1, sum, target);
    item.pop_back();
    sum -= nums[i];
    combinationSum(nums, item, i + 1, sum, target);
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    if (candidates.empty())
    {
        return res;
    }
    vector<int> item;
    sort(candidates.begin(), candidates.end());
    combinationSum(candidates, item, 0, 0, target);
    set<vector<int>> ans(res.begin(), res.end());
    vector<vector<int>> res(ans.begin(), ans.end());
    return res;
}