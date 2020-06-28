#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<string>> maps;
    vector<vector<string>> res;

    for(auto x : strs)
    {
        string tmp_str = x; 
        sort(tmp_str.begin(), tmp_str.end());

        if (maps.find(tmp_str) == maps.end())
        {
            vector<string> tmp_num;
            maps[tmp_str] = tmp_num;
        }
        maps[tmp_str].push_back(x);
    }

    map<string, vector<string>>::iterator it;
    for (it = maps.begin(); it != maps.end(); it++)
    {
        res.push_back((*it).second);
    }
    return res;
}