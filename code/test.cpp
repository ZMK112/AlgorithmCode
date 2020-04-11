#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <string.h>
using namespace std;

bool exist(vector<vector<char>>& board, string word) {
    int rows = board.size();
    int cols = board[0].size();
    int lens = 0;

    bool *visited = new bool[rows * cols];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (hasPathCore(board, rows, cols, i, j, word, lens, visited))
            {
                return true;
            }
        }
    }
    delete[] visited;
    return false;
}

bool hasPathCore(const char* matrix, int rows, int cols, int i, int j,
                const char* str, int& lens, bool* visited)
{
    if(str[lens] == '\0') return true;
    bool haspath = false;
    if (i >= 0 && i < rows && j >=0 && j < cols
        && matrix[i * cols + j] ==  str[lens] && !visited[i * cols + j])
    {
        lens++;
        visited[i * cols + j] = true;
        haspath = hasPathCore(matrix,  rows, cols, i, j - 1, str, lens, visited)
                ||hasPathCore(matrix, rows, cols, i - 1, j, str, lens, visited)
                ||hasPathCore(matrix, rows, cols, i + 1, j, str, lens , visited)
                ||hasPathCore(matrix, rows, cols, i + 1, j, str, lens, visited);
        
        if (!haspath)
        {
            lens--;
            visited[i * cols +j] = false;
        }
    }
    return haspath;
}