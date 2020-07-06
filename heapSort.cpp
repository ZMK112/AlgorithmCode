#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

// ·ÇµÝ¹é°æ±¾µÄ¶ÑÅÅÐò

void heapify(vector<int>& nums, int lens, int index)
{
    int left = 2 * index + 1;
    while (left < lens)
    {
        int maxIndex = left + 1 < lens && nums[left + 1] < nums[left] ? left : left + 1;
        maxIndex = nums[maxIndex] < nums[index] ? index : maxIndex;
        if (maxIndex == index)
        {
            return;
        }
        swap(nums[maxIndex], nums[index]);
        index = maxIndex;
        left = 2 * index + 1;
    }
}