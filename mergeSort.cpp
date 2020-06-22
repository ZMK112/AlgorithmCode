#include <iostream>
#include <fstream>
#include<sstream>
#include <vector>
#include <queue>
using namespace std;

// void mergeVector(vector<int>& vec1, vector<int>& vec2, vector<int>& res)
// {
//     int i = 0, j = 0;
//     int n = min(vec1.size(), vec2.size());
//     while (i < n && j < n)
//     {
//         if (vec1[i] < vec2[j])
//         {
//             res.push_back(vec1[i++]);
//         }
//         else
//         {
//             res.push_back(vec2[j++]);
//         }
//     }
    
//     for (; i < vec1.size(); i++)
//     {
//         res.push_back(vec1[i]);
//     }
//     for (; j < vec2.size(); j++)
//     {
//         res.push_back(vec2[j]);
//     }
// }

void merge(vector<int>& arr, int left, int mid, int right)
{
    vector<int> tmp;
    int i = left, j = mid + 1, index = 0;

    while (i <= mid && j <= right)
    {
        int num = arr[i] < arr[j] ? arr[i++] : arr[j++];
        tmp.push_back(num);
        cout<< arr[i] << "---"<< arr[j]<< "---"<< i << "---"<< j <<endl;
    }
    for ( ; i <= mid; i++)
    {
        tmp.push_back(arr[i]);
    }
    for ( ; j < right; j++)
    {
        tmp.push_back(arr[j]);
    }
    for (int i = 0; i < tmp.size(); i++)
    {
        arr[left++] = tmp[i];
    }
}

void mergeSort(vector<int>& arr, int left, int right)
{
    if (left == right)
    {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// void mergeSort(vector<int>& arr)
// {
//     mergeSort(arr, 0, arr.size());
// }

int main()
{
    vector<int> nums = {5,2,6};
    mergeSort(nums, 0, 2);

    for (int i = 0; i < nums.size(); i++)
    {
        cout<< nums[i];
    }
    
    return 0;
}