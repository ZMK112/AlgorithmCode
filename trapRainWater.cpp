#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

struct item
{
    int x;
    int y;
    int h;
    item(int a, int b, int c) : x(a), y(b), h(c){};  
};

struct cmp
{
    bool operator()(const item &a, const item &b)
    {
        return a.h > b.h;
    }
};

int rows, cols;
priority_queue<item, vector<item>, cmp> Q;


void construct(vector<vector<int>>& map, vector<vector<int>>& visit)
{
    for (int i = 0; i < rows; i++)
    {
        Q.push(item(i, 0, map[i][0]));
        Q.push(item(i, cols - 1, map[i][cols - 1]));    
        visit[i][0] = 1;
        visit[i][cols - 1] = 1;
    }
    
    for (int j = 0; j < cols; j++)
    {
        Q.push(item(0, j, map[0][j]));
        Q.push(item(rows - 1, j, map[rows - 1][j]));
        visit[0][j] = 1;
        visit[rows - 1][j] = 1;
    }
}

int trapRainWater(vector<vector<int>>& heightMap) {
    rows = heightMap.size();
    if (!rows)
    {
        return 0;
    }
    cols = heightMap[0].size();

    vector<vector<int>> visit(rows, vector<int>(cols, 0));

    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, -1, 1};
    int res = 0;

    construct(heightMap, visit);

    while (!Q.empty())
    {
        int x = Q.top().x;
        int y = Q.top().y;
        int h = Q.top().h;

        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int tmp_x = x + dx[i];
            int tmp_y = y + dy[i];

            if (tmp_x >= 0 && tmp_x < rows && tmp_y >= 0 && tmp_y < cols && !visit[tmp_x][tmp_y])
            {
                if (h > heightMap[tmp_x][tmp_y])
                {
                    res += h - heightMap[tmp_x][tmp_y];
                    heightMap[tmp_x][tmp_y] = h;
                }
                Q.push(item(tmp_x, tmp_y, heightMap[tmp_x][tmp_y]));
                visit[tmp_x][tmp_y] = 1;
            }
        }
    }
    
    return res;
}