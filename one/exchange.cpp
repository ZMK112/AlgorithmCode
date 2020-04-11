#include <iostream>
#include <vector>
#include <string.h>
    
using namespace std;

vector<int> exchange(vector<int>& nums) 
{   
    int lens = nums.size() - 1;
    int head, tail = 0, lens;
    while (head < tail)
    {
        while(head < tail && nums[head] & 1) head++;
        while(head < tail && !(nums[tail] & 1)) tail--;
        if(head < tail) swap(nums[head], nums[tail]); 
    }
    return nums;
}