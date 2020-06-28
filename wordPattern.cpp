#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

bool wordPattern(string pattern, string str) {
    map<string, char> wordMap;
    vector<char> used(128, '0');
    string tmp_word;
    int index = 0;
    str.push_back(' ');

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            if (index == pattern.length())
            {
                return false;
            }
            if (wordMap.find(tmp_word) == wordMap.end())
            {
                if (used[pattern[index]] == 1)
                {
                    return false;
                }
                else
                {
                    wordMap[tmp_word] = pattern[index];
                    used[pattern[index]] = 1;
                }
            }
            else
            {
                if (wordMap[tmp_word] != pattern[index])
                {
                    return false;
                }
            }
            tmp_word = "";
            index++;
        }
        else
        {
            tmp_word += str[i];
        }
    }
    if (index != pattern.size())
    {
        return false;
    }
    return true;
}