#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

//�ݹ�������
// void heapify(vector<int>& nums, int lens, int index)
// {
//     if (index > lens)
//     {
//         return;
//     }
    
//     int left = index * 2 + 1;
//     if (left >= lens)
//     {
//         return;
//     }
    
//     int maxIndex = (left + 1 < lens) && nums[left + 1] > nums[left] ? left + 1 : left;
//     maxIndex = nums[maxIndex] > nums[index] ? maxIndex : index; //һ�������

//     if (maxIndex == index)
//     {
//         return;
//     }
    
//     swap(nums[maxIndex], nums[index]);
//     heapify(nums, lens, maxIndex);
// }


//�ǵݹ�������
void heapify(vector<int>& nums, int lens, int index)
{
    int left = 2 * index + 1;
    while (left < lens)
    {
        // int maxIndex = left + 1 < lens && nums[left + 1] > nums[left] ? left + 1: left;
        int maxIndex = left + 1 < lens && nums[left + 1] < nums[left] ? left : left + 1;
        // һ������� nums[left + 1] < nums[left] ? left : left + 1 ǰ���˳��Ӧ��������˳����һ��
        maxIndex = nums[maxIndex] > nums[index] ? maxIndex : index;
        if (maxIndex == index)
        {
            break;
        }
        swap(nums[maxIndex], nums[index]);
        index = maxIndex;
        left = 2 * index + 1;
    }
}

void heapSort(vector<int>& nums)
{
    int lens = nums.size();
    for (int i = lens/2 - 1; i >= 0; i--)
    {
        heapify(nums, lens, i);
    }
    
    for (int i = lens - 1; i > 0; i--)  //�ڶ��δ����
    {
        swap(nums[i], nums[0]);
        heapify(nums, i, 0);
    }
    
}

vector<int> sortArray(vector<int>& nums) {
    heapSort(nums);
    return nums;
}

int main()
{
    int arr[5] =  {5,4,3,2,1};
    vector<int> nums;
    for (int i = 0; i < 5; i++)
    {
        nums.push_back(arr[i]);
    }
    heapSort(nums);
    for (int i = 0; i < 5; i++)
    {
        printf("%d",nums[i]);
    }
    
    return 0;
}