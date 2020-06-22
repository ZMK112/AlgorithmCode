#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> res;

void merge(vector<pair<int, int>>& arr, int left, int mid, int right)
{
    vector<pair<int, int>> tmp;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (arr[i].first <= arr[j].first)
        {
            res[arr[i].second] += j - mid - 1;
            tmp.push_back(arr[i++]);
        }
        else if(arr[i].first > arr[j].first)
        {
            tmp.push_back(arr[j++]);
        }
    }

    while( i <= mid)
    {   
        res[arr[i].second] += j -mid - 1;
        tmp.push_back(arr[i++]);
    }
    
    while (j <= right)
    {
        tmp.push_back(arr[j++]);
    }

    for (int i = 0; i < tmp.size(); i++)
    {
        arr[i + left] = tmp[i];
    }
}

void mergeSort(vector<pair<int, int>>& arr, int left, int right)
{
    if (left == right){
        return;
    }
    int mid = left + (right - left)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr,left, mid, right);
}

vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    if(!n) return res;
    vector<pair<int, int>> map;
    vector<int> a(n, 0);
    res = a;
    for (int i = 0; i < n; i++)
    {
        map.push_back({nums[i], i});
    }

    mergeSort(map, 0, n - 1); 
    // for(int i = 0; i < map.size(); i++)
    //     cout<< map[i].first;
    for (int i = 0; i < map.size(); i++){
        cout<<res[i];
    }

    return res;
}

int main()
{
    vector<int> nums = {5,2,6,1};
    countSmaller(nums);
    return 0;
}