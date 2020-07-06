#include <iostream>
#include <vector>
using namespace std;

vector<int> res;
void printm(vector<vector<int>>& nums, int rows, int cols, int i)
{
    //i能不能被视为第i圈
    int endx = cols - 1 - i;
    int endy = rows - 1 - i;
    //从左到右
    for (int j = i; j <= endx; j++)
    {
        res.push_back(nums[i][j]);
    }
    //右边：从上到下打印
    if (i < endy)
    {
        for (int j = i + 1; j <= endy; j++)
        {
            res.push_back(nums[j][endx]);
        }
    }
    //右边：从右到左
    if (i < endx && i < endy)
    {
        for (int j = endx - 1; j >= i; j--)
        {
            res.push_back(nums[endy][j]);
        } 
    }
    
    //从下到上
    if (i < endx && i < endy - 1)
    {
        for (int j = endy - 1; j > i; j--)
        {
            res.push_back(nums[j][i]);
        }
    }
}


vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    if (matrix.empty())
    {
        return;
    }
        
    int i = 0;

    while(cols > i * 2 && rows > i * 2){
        printm(matrix, rows, cols, i);
        i++;
    }
    return res;
}
