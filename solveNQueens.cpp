#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;


void putDown(vector<vector<int>>& map, int x, int y)
{
    int n = map.size();
    // int lx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
    // int ly[8] = {1, 0, -1, 0, 1, -1, 1, -1};
    const int lx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    const int ly[] = {0, 0, -1, 1, -1, 1, -1, 1};
    // map[x][y] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int tmpX = x + i * lx[j];
            int tmpY = y + i * ly[j];

            if(tmpX >= 0 && tmpX < n && tmpY >= 0 && tmpY < n)
                map[tmpX][tmpY] = 1;
        }
        
    }
}

void solve(vector<vector<int>>& map, vector<vector<string>>& res,
        vector<string>& tmp, int k, int n)
{
    if (k == n)
    {
        res.push_back(tmp);
        return;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (!map[k][i])
        {
            tmp[k][i] = 'Q';
            cout<< i <<"------"<<tmp[k]<<endl;
            vector<vector<int>> tmpMap = map;
            putDown(map, k, i);
            solve(map, res, tmp, k + 1, n);
            map = tmpMap;
            tmp[k][i] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<int>> map(n, vector<int>(n, 0));
    vector<string> tmp(n);
    for (int i = 0; i < n; i++)
    {
        tmp[i].append(n, '.');    
    }
    // cout<<tmp[0];
    vector<vector<string>> res;
    solve(map, res, tmp, 0 ,n);
    return res;
}