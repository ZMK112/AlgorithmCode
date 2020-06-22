#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

// int findContentChildren(vector<int>& g, vector<int>& s) {
//     sort(g.begin(), g.end());
//     sort(s.begin(), s.end());
//     int child = 0, cookie = 0, num = 0;
//     while (child < g.size() && cookie < s.size())
//     {
//         if (g[child] <= s[cookie])
//         {
//             num++;
//             child++;
//             cookie++;
//         }
//         else
//         {
//             cookie++;
//         }
//     }
//     return num;
// }


int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int res = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (g[res] < s[i])
        {
            res++;
            if (res == g.size())
            {
                return g.size();
            }
            
        }
    }
    return res;
}

















