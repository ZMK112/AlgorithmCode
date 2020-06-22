#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;


bool cmp(vector<int>& a, vector<int>& b)
{
    return a[0] < b[0];
}

int findMinArrowShots(vector<vector<int>>& points) {
    if(points.empty()) return 0;
    sort(points.begin(),  points.end(), cmp);
    int num = 1;
    int ph = points[0][0], pr = points[0][0];

    for (int i = 1; i < points.size(); i++)
    {
        if (points[i][0] < pr)
        {
            ph = points[i][0];
            if (points[i][1] < pr)
            {
                pr = points[i][1];
            }
        }
        else
        {
            num++;
            ph = points[i][0];
            pr = points[i][1];            
        }
    }
    return num;
}