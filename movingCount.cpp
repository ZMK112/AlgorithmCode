#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int movingCount(int m, int n, int k) 
{   
    int movingCountCore(int threshold, int rows, int cols, int i, int j, bool *visited);
    int rows = m, cols = n;
    int threshold = k;

    if (threshold < 0|| rows < 0 || cols < 0)
    {
        return 0;
    }
    
    bool *visited = new bool[rows * cols];
    memset(visited, 0, rows * cols);
    // for (int i = 0; i < rows * cols; i++)
    // {
    //     visited[i] = false;
    // }
    

    int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
    return count;
}

int movingCountCore(int threshold, int rows, int cols, int i, int j, bool *visited)
{   
    bool check(int threshold, int rows, int cols, int i , int j, bool *visited);
    int count = 0;
    if (check(threshold, rows, cols, i, j, visited))
    {
        visited[i * cols + j] = true;
        int one = movingCountCore(threshold,rows, cols, i - 1, j, visited);
        int two = movingCountCore(threshold,rows, cols, i, j - 1, visited);
        int three = movingCountCore(threshold, rows, cols, i + 1, j, visited);
        int four = movingCountCore(threshold, rows, cols, i, j + 1,visited);
        count = 1 + one + two + three + four;
    }
    return count;
}

bool check(int threshold, int rows, int cols, int i , int j, bool *visited)
{   
    int getSum(int row, int col);
    if (i >= 0 && i < rows && j >= 0 && j < cols && getSum(i ,j) <= threshold && !visited[i * cols + j])
    {
        return true;
    }
    return false;
}

int getSum(int row, int col)
{
    int sum = 0;
    while (row > 0)
    {
        sum += row % 10;
        row /= 10;
    }
    while (col > 0)
    {
        sum += col % 10;
        col /= 10;
    }
    return sum;
}

int main()
{
    int row = 2, col = 3, threshold = 1;
    printf("%d",movingCount(row,col,threshold));
    return 0;
}