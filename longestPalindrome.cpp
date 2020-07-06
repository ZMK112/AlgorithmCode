#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

int longestPalindrome(string s) {
    vector<int> maps(128, 0);
    int res = 0;
    int flag = 0;

    for (int i = 0; i < s.length(); i++)
    {
        maps[s[i]]++;
    }
    
    for (int i = 0; i < maps.size(); i++)
    {
        if (maps[i] % 2 == 0)
        {
            res += maps[i];
        }
        else
        {
            res += maps[i] - 1;
            flag = 1;
        }
    }
    return res + flag;
}