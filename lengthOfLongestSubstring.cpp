#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int begin = 0;
    int res = 0;
    string word  = "";
    vector<int> map(128, 0);

    for (int i = 0; i < s.length(); i++)
    {
        map[s[i]]++;
        if (map[s[i]] == 1)
        {
            word += s[i];
            res = res > word.length() ? res : word.length();
        }
        else
        {
            while (begin < i && map[s[i]] > 1)
            {
                map[s[begin]]--;
                begin++;
            }
            
            word = "";
            for (int j = begin; j <= i; j++)
            {
                word += s[j];
            }
        }
    }
    return res;
}