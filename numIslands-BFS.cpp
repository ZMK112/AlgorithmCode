#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<char>> map;
queue<pair<int, int>> Q;
int rows, cols;

void bfs(vector<vector<int>>& visit, int i, int j)
{
    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, -1, 1};
    int tmp_x, tmp_y;

    Q.push({i, j});
    while (!Q.empty())
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            tmp_x = dx[i] + x;
            tmp_y = dy[i] + y;

            if (tmp_x >= 0 && tmp_x < rows && tmp_y >= 0 && tmp_y < cols)
            {
                if (!visit[tmp_x][tmp_y] && map[tmp_x][tmp_y] == '1')
                {
                    Q.push({tmp_x, tmp_y});
                    visit[tmp_x][tmp_y] = 1;
                    map[tmp_x][tmp_y] = '0';
                }
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty())
    {
        return 0;
    }

    rows = grid.size();
    cols = grid[0].size();
    int res = 0;
    vector<vector<int>> visit(rows, vector<int>(cols, 0));
    map = grid;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (map[i][j] == '1' && !visit[i][j])
            {
                bfs(visit, i, j);
                res++;
            }
        }
    }
    return res;
}





























// queue<pair<int, int>> queues;
// vector<vector<char>> map;
// int n,m;

// void add(int x, int y, vector<vector<int>>& gra)
// {
//     if (x >= 0 && y >= 0 && y < m && x < n && map[x][y] == '1' && !gra[x][y])
//     {
//         gra[x][y] = 1;
//         queues.push({x, y});
//     }
// }

// void floodfill(int i, int j, vector<vector<int>>& gra)
// {   
//     queues.push({i, j});
//     gra[i][j] = 1;

//     while (!queues.empty())
//     {   
//         auto q = queues.front();
//         queues.pop();
//         int x = q.first, y = q.second;
//         add(x + 1, y, gra);
//         add(x, y + 1, gra);
//         add(x - 1, y, gra);
//         add(x, y - 1, gra);
//     }
// }

// int numIslands(vector<vector<char>>& grid) {
//     n = grid.size();
//     if (!n)
//     {
//         return 0;
//     }
//     m = grid[0].size();
//     int numRes = 0;    
//     map = grid;
//     vector<vector<int>> gra(n, vector<int>(m, 0));

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (grid[i][j] == '1' && !gra[i][j])
//             {
//                 floodfill(i, j, gra);
//                 numRes++;
//             }
//         }
//     }
//     return numRes;
// }

// int main()
// {   
//     return 0;
// }