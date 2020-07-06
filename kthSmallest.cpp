#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

struct item
{
    int val;
    int x;
    int y;
    item(int val, int x, int y) : val(val), x(x), y(y){};
    bool operator>(const item& a) const {return this->val > a.val;}

};


int kthSmallest1(vector<vector<int>>& matrix, int k) {
    if (matrix.empty())
    {
        return 0;
    }
    priority_queue<item, vector<item>, greater<item>> queues;

    // 将matrix中第一列放入优先队列中，会实现自动排序
    for (int i = 0; i < matrix.size(); i++)
    {
        queues.emplace(matrix[i][0], i, 0);
    }

    //将最小出队，次小入队。（而“次小”就是“最小”的右侧第一个 j + 1）
    for (int j = 0; j < k - 1; j++)
    {
        item a = queues.top();
        queues.pop();
        if (a.y != matrix.size() - 1) //防止越界
        {
            queues.emplace(matrix[a.x][a.y + 1], a.x, a.y + 1);
        }
    }
    //pop掉k - 1个，最后一个就是队列的top
    return queues.top().val;
}


bool check(vector<vector<int>>& nums, int mid, int n, int k)
{
    int i = n - 1;
    int j = 0;
    int num = 0;
    while (i >= 0 && j < n)
    {
        if (nums[i][j] > mid)
        {
            i--;
        }
        else
        {
            j++;
            num += i + 1;
        }
    }
    return num >= k;
}

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int left = matrix[rows - 1][0];
    int right = matrix[0][cols - 1];
    int mid = left + ((right - left) >> 1);

    while (left <= right)
    {
        if (check(matrix, mid, cols, k))
        {
            mid = right;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}





int main()
{
    vector<vector<int>> a = {{1,5,9},{10,11,13},{12,13,15}};
    kthSmallest1(a, 8);
    return 0;
}