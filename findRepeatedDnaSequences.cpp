#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
    map<string, int> word_map;
    vector<string> res;

    for (int i = 0; i < s.length(); i++)
    {
        string tmp_str = s.substr(i, 10);
        word_map[tmp_str]++;
    }
    
    map<string, int>::iterator it;
    for(it = word_map.begin(); it != word_map.end(); it++)
    {
        if (it->second > 1)
        {
            res.push_back(it->first);
        }
    }
    return res;
}