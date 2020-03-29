#include <iostream>
#include <vector>
using namespace std;

// void quickSort(int* nums, int left, int right)
// {
//     if (left < right)
//     {   
//         int i = left, j = right;
//         int x = nums[left];

//         while (i < j)
//         {
//             while (i < j && nums[j] >= x){
//                 j--;
//             }
//             if (i < j){
//                 nums[i++] = nums[j];
//             }
//             while (i < j && nums[i] <= x){
//                 i++;
//             }
//             if (i < j){
//                 nums[j--] = nums[i];
//             }
//         }
//         nums[i] = x;
//         quickSort(nums, left, i - 1);
//         quickSort(nums, i + 1, right);
//     } 
// }

int partition(vector<int>& nums, int left, int right)
{
        int i = left, j = right;
        int x = nums[left];

        while (i < j)
        {
            while (i < j && nums[j] >= x){
                j--;
            }
            if (i < j){
                nums[i++] = nums[j];
            }
            while (i < j && nums[i] <= x){
                i++;
            }
            if (i < j){
                nums[j--] = nums[i];
            }
        }
        nums[i] = x;
        return i;
}

int partition_two(vector<int>& nums, int left, int right)
{
    int pivot = nums[left];
    int i = left + 1, j = right;
    while (i < j)
    {
        while(i < j && nums[i] <= pivot) i++;
        while(i < j && nums[j] >= pivot) j--;
        if (i < j){
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i], nums[left]);
    return i;
}

vector<int> quickSort(vector<int>& nums, int left, int right)
{
    if (left < right)
    {   
        int i = partition_two(nums, left, right);
        quickSort(nums, left, i - 1);
        quickSort(nums, i + 1, right);
    }
}

 vector<int> sortArray(vector<int>& nums) {
     int i = 0, j = nums.size() - 1;
     quickSort(nums, i, j);
     return nums;
}

int main()
{   
    vector<int> num = {72,6,57,88,60,42,83,73,48,85};
    int nums[10] = {72,6,57,88,60,42,83,73,48,85};
    quickSort(num, 0, 9);
    return 0;

}