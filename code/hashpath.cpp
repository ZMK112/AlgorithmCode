#include <iostream>
// #include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <string.h>
using namespace std;

bool hasPath(char* matrix, int rows, int cols, char* str)
{
    bool *visited = new bool[rows * cols];
    memset(visited, 0, rows * cols);
    
    int lens = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (hasPath(matrix, rows, cols, i, j, str, lens, visited))
            {
                return true;
            }
            
        }
    }
    delete[] visited;
    return false;
}

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, 
            const char* str, int& lens, bool* visited)
{
    if(str[lens] == '\0') return true;
    bool haspath = false;
    if (row >= 0 && row < rows && col >= 0 && col < cols
        && matrix[row * cols + col] == str[lens] 
        && !visited[row * cols + col])
    {
        lens++;
        visited[row * cols + col] = true;
        haspath = hasPathCore(matrix, rows, cols, row, col - 1, str, lens, visited)
                ||hasPathCore(matrix, rows, cols, row - 1, col, str, lens, visited)
                ||hasPathCore(matrix, rows, cols, row, col + 1, str, lens, visited)
                ||hasPathCore(matrix, rows, cols, row + 1, col, str, lens, visited);
        if(!haspath){
            lens--;
            visited[row * cols + col] = false;
        }
    }
    return haspath;
}