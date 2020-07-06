#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> res;

//��������ʵ�ַ�ʽ
void generate(vector<int>& nums, int i, vector<int>& item)
{
    if (i > nums.size())
    {
        return;
    }
    
    item.push_back(nums[i]);
    res.push_back(item);
    generate(nums, i + 1, item);
    item.pop_back();
    generate(nums, i + 1, item);
}

vector<vector<int>> subsets1(vector<int>& nums) {
    vector<int> item;
    res.push_back(item);
    generate(nums, 0, item);
    return res;
}


//λ����ķ�ʽʵ��
vector<vector<int>> subsets(vector<int>& nums) {

    for (int i = 0; i < (1<<nums.size()); i++)
    {
        vector<int> item;
        for (int j = 0; j < nums.size(); j++)
        {
            if ((i>>j) & 1)
            {
                item.push_back(nums[i]);
            }
        }
        res.push_back(item);
    }
    return res;
}

