#include <iostream>
#include <vector>
using namespace std;

vector<int> res;
void printm(vector<vector<int>>& nums, int rows, int cols, int i)
{
    //i�ܲ��ܱ���Ϊ��iȦ
    int endx = cols - 1 - i;
    int endy = rows - 1 - i;
    //������
    for (int j = i; j <= endx; j++)
    {
        res.push_back(nums[i][j]);
    }
    //�ұߣ����ϵ��´�ӡ
    if (i < endy)
    {
        for (int j = i + 1; j <= endy; j++)
        {
            res.push_back(nums[j][endx]);
        }
    }
    //�ұߣ����ҵ���
    if (i < endx && i < endy)
    {
        for (int j = endx - 1; j >= i; j--)
        {
            res.push_back(nums[endy][j]);
        } 
    }
    
    //���µ���
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
