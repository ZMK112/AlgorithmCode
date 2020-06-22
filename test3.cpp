#include <iostream>
#include <vector>
using namespace std;

bool verifys(vector<int>& nums, int lens)
{
    if (nums.empty() || lens <= 0)
    {
        return false;
    }
    
    int root = nums[lens - 1];
    int i = 0;
    for (; i < lens - 1; ++i)
    {
        if (nums[i] > root)
        {
            break;
        }
    }
    
    int j = i;
    
    for (; j < lens - 1; ++j)
    {
        if (nums[j] < root)
        {
            return false;
        }
    }

    bool left = true;
    if (i > 0)
    {
        left = verifys(nums, i);
    }

    bool right = true;
    if (i < lens - 1)
    {
        vector<int> tmp(nums.begin() + i, nums.end());
        right = verifys(tmp, lens - i - 1);
    }
    return left && right;
}

bool verifyPostorder(vector<int>& postorder) {
    bool res = verifys(postorder, postorder.size());
    return res;
}

int main()
{
    int nums[5] = {1,3,2,6,5};
    vector<int> res;
    for (int i = 0; i < 5; i++)
    {
        res.push_back(nums[i]);
    }
    bool re = verifyPostorder(res);
    return 0;
}
