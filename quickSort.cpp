#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

int patitation(vector<int>& nums, int left, int right)
{
    if(nums.empty()) return 0;
    int i = left, j = right;
    int tmp = nums[left];

    while (i < j)
    {
        while(i < j && nums[j] > tmp) j--;
        if( i < j) nums[i++] = nums[j];

        while(i < j && nums[i] < tmp) i++;
        if(i < j) nums[j--] = nums[i];
    }
    nums[i] = tmp;
    return i;    
}

void quickSort(vector<int>& nums, int left, int right)
{
    if(nums.empty()) return;
    if (left < right)
    {
        int index = patitation(nums, left, right);
        quickSort(nums, left, index - 1);
        quickSort(nums, index + 1, right);
    }
}

int main()
{   
    vector<int> num = {72,6,57,88,60,42,83,73,48,85};
    int nums[10] = {72,6,57,88,60,42,83,73,48,85};
    quickSort(num, 0, 9);
    return 0;

}