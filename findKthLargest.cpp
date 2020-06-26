#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

//ֱ��ʹ��stl�е�priority_queue���ȶ���
	//�󶥶�  
	// priority_queue<int, vector<int>, less<int>> q;

	// //С����
	// priority_queue<int, vector<int>, greater<int>> p;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> a;
    for (int i = 0; i < nums.size(); i++)
    {
        if (a.size() < k)
        {
            a.push(nums[i]);
        }
        else if (a.top() < nums[i])
        {
            a.pop();
            a.push(nums[i]);
        }
    }
    
    return a.top();
}