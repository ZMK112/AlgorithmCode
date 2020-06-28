#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// int n,m;
// void floodfill(vector<vector<char>>& grid, vector<vector<int>>& map, int i, int j)
// {
//     map[i][j] = 1;
//     if (i - 1 >= 0 && !map[i - 1][j] && grid[i - 1][j] == '1')
//     {
//         floodfill(grid, map, i - 1, j);
//     }
//     if (i + 1 < n && !map[i + 1][j] && grid[i + 1][j] == '1')
//     {
//         floodfill(grid, map, i + 1, j);
//     }
//     if (j - 1 >= 0 && !map[i][j - 1] && grid[i][j -1] == '1')
//     {
//         floodfill(grid, map, i, j - 1);
//     }
//     if (j + 1 < m && !map[i][j + 1] && grid[i][j + 1] == '1')
//     {
//         floodfill(grid, map, i, j + 1);
//     }
// }

// int numIslands(vector<vector<char>>& grid)
// {
//     n = grid.size();
//     if (!n){
//         return 0;
//     }
//     m = grid[0].size();
//     int nums = 0;
    
//     vector<vector<int>> map(n, vector<int>(m,0));

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (grid[i][j] == '1' && !map[i][j])
//             {
//                 floodfill(grid, map, i, j);
//                 nums++;
//             }
//         }
//     }
//     return nums;
// }


int rows, cols;
vector<vector<char>> map;

void dfs(vector<vector<int>>& visit, int i, int j)
{
    map[i][j] = '0';
    visit[i][j] = 1;
    if (i + 1 < rows && !visit[i + 1][j] &&  map[i + 1][j] == '1') 
        dfs(visit, i + 1, j);

    if (i - 1 >= 0 && !visit[i - 1][j] && map[i - 1][j] == '1')
        dfs(visit,i - 1, j);
    
    if (j + 1 < cols && !visit[i][j + 1] && map[i][j + 1] == '1')
        dfs(visit, i, j + 1);

    if(j - 1 >= 0 && !visit[i][j - 1] && map[i][j - 1] == '1')
        dfs(visit, i, j - 1);
}

int numIslands(vector<vector<char>>& grid) {
    rows = grid.size();
    cols = grid[0].size();
    int res = 0;
    vector<vector<int>> visit(rows, vector<int>(cols, 0));
    map = grid;

    if (!rows)
    {
        return 0;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (!visit[i][j] && map[i][j] == '1')
            {
                dfs(visit, i, j);
                res++;
            }
        }
    }
    
    return res;
}