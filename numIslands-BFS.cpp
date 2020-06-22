#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<pair<int, int>> queues;
vector<vector<char>> map;
int n,m;

void add(int x, int y, vector<vector<int>>& gra)
{
    if (x >= 0 && y >= 0 && y < m && x < n && map[x][y] == '1' && !gra[x][y])
    {
        gra[x][y] = 1;
        queues.push({x, y});
    }
}

void floodfill(int i, int j, vector<vector<int>>& gra)
{   
    queues.push({i, j});
    gra[i][j] = 1;

    while (!queues.empty())
    {   
        auto q = queues.front();
        queues.pop();
        int x = q.first, y = q.second;
        add(x + 1, y, gra);
        add(x, y + 1, gra);
        add(x - 1, y, gra);
        add(x, y - 1, gra);
    }
}

int numIslands(vector<vector<char>>& grid) {
    n = grid.size();
    if (!n)
    {
        return 0;
    }
    m = grid[0].size();
    int numRes = 0;    
    map = grid;
    vector<vector<int>> gra(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1' && !gra[i][j])
            {
                floodfill(i, j, gra);
                numRes++;
            }
        }
    }
    return numRes;
}

int main()
{   
    return 0;
}