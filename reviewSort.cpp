#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& nums)
{
    int lens = nums.size();
    for (int i = lens - 1; i >= 0 ; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}

void bubbleSort_two(vector<int>& nums)
{
    int lens = nums.size();
    for (int i = 0; i < lens - 1; i++)
    {
        for (int j = 0; j < lens - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}

void insertSort(vector<int>& nums)
{
    
}


int main()
{
    vector<int> nums = {4,3,2,1};
    bubbleSort_two(nums);
    return 0;
}