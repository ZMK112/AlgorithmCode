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

vector<vector<int>> subsets(vector<int>& nums, int i, vector<int>& item)
{
    if (i >= nums.size())
    {
        return res;
    }
    item.push_back(nums[i]);
    res.push_back(item);
    subsets(nums, i + 1, item);
    item.pop_back();
    subsets(nums, i + 1, item);
}

bool adds(vector<int>& nums, int target)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    if (sum == target)
    {
        return true;
    }
    return false;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> item;
    res.push_back(item);
    subsets(nums, 0, item);
    set<vector<int>> ans(res.begin(), res.end());
    vector<vector<int>> anwser(ans.begin(), ans.end());
    return anwser;    
}


vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<int> item;
    res.push_back(item);
    subsets(nums, 0, item);
    set<vector<int>> ans(res.begin(), res.end());
    vector<vector<int>> answer(ans.begin(), ans.end());
    vector<vector<int>> a;
    for (int i = 0; i < answer.size(); i++)
    {
        if (adds(answer[i], target))
        {
            a.push_back(answer[i]);
        }
    }

    return a;
}