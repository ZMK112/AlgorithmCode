#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int minSetSize(vector<int>& arr) {
    map<int, int> maps;
    vector<int> nums;

    for (int i = 0; i < arr.size(); i++)
    {
        maps[arr[i]]++;
    }

    for (auto x : maps)
    {
        nums.push_back(x.second);
    }

    sort(nums.begin(), nums.end(), greater<int>());

    int res = 0, tmp_num = 0;
    
    for (auto x : nums)
    {
        tmp_num += x;
        res++;
        if (tmp_num >= arr.size() / 2)
        {
            return res;
        }
    }
    return res;
}