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

bool check(vector<int> s, vector<int> t, vector<int>& vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (s[vec[i]] < t[vec[i]])
        {
            return false;
        }
    }
    return true;
}

string minWindow(string s, string t) {
    vector<int> map_s(128, 0);
    vector<int> map_t(128, 0);
    vector<int> vec;

    for (int i = 0; i < t.size(); i++)
    {
        map_t[t[i]]++;
    }

    for (int i = 0; i < 128; i++)
    {
        if (map_t[i] > 0)
        {
            vec.push_back(i);
        }
    }
    
    
    int begin = 0;
    string res = "";

    for (int i = 0; i < s.length(); i++)
    {
        map_s[s[i]]++;
        while (begin < i)
        {
            if (map_t[s[begin]] == 0)
            {
                begin++;
            }
            else if(map_t[s[begin]] < map_s[s[begin]])
            {
                map_s[s[begin]]--;
                begin++;
            }
            else
            {
                break;
            }
        }
        if (check(map_s, map_t, vec))
        {
            if (res.length() > i - begin + 1 || (res.length() == 0))
            {
                res = s.substr(begin, i - begin + 1);
            }
        }
    }
    
    return res;
}