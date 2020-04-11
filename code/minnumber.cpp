#include <iostream>
#include <vector>
using namespace std;

int minArray(vector<int>& nums)
{   
    int length = nums.size();
    if (length < 0){
        return 0;
    }
     int p1 = 0;
     int p2 = length - 1;
     int pm = p1;

     while (nums[p1] >= nums[p2])
     {
        if (p2 - p1 == 1)
        {
            pm = p2;
            break;
        }
        pm = (p1 + p2) / 2;

        if (nums[p1] == nums[p2] && nums[p1] == nums[pm]){
            int res = nums[p1];
            for (int i = 0; i <= p2; i++){
                if (res > nums[i]){
                    res = nums[i];
                }
            }
            return res;
        }
        
        if (nums[pm] >= nums[p1])
        {
            p1 = pm;
        }
        else if(nums[pm] <= nums[p2])
        {
            p2 = pm;
        }       
     }
    return nums[pm];
}