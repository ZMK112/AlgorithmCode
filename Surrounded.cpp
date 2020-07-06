#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<char>> map;
int n, m;

void floodfill(vector<vector<int>>& gra, int i, int j)
{
    gra[i][j] = 1;
    map[i][j] = '#';
    if (i + 1 < n && map[i + 1][j] == 'O' && !gra[i + 1][j])
    {
        floodfill(gra, i + 1, j);
    }
    if (i - 1 >= 0 && map[i - 1][j] == 'O' && !gra[i - 1][j])
    {
        floodfill(gra, i - 1, j);
    }
    if (j + 1 < m && map[i][j + 1] == 'O' && !gra[i][j + 1])
    {
        floodfill(gra, i, j + 1);
    }
    if (j - 1 >= 0 && map[i][j - 1] == 'O' && !gra[i][j - 1])
    {
        floodfill(gra, i, j - 1);
    }
}

void solve(vector<vector<char>>& board) {
    n = board.size();
    if (!n)
    {
        return;
    }
    m = board[0].size();
    map = board;
    vector<vector<int>> gra(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) 
            {
                if (!gra[i][j] && map[i][j] == 'O')
                {
                    floodfill(gra, i, j);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 'O')
            {
                map[i][j] = 'X';
            }
            if (map[i][j] == '#')
            {
                map[i][j] = 'O';
            }
        }
    }
    board = map;
}