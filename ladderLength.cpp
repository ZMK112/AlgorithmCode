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

map<string, vector<string>> graph;

bool connect(string &a, string &b)
{
    int cnt = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            cnt++;
        }
    }
    return cnt == 1;
}

void construct(string beginWord, vector<string> wordList)
{
    wordList.push_back(beginWord);
    
    for(auto x : wordList){
        graph[x] = vector<string>();
    }

    for (int i = 0; i < wordList.size(); i++)
    {
        for (int j = i + 1; j < wordList.size(); j++)
        {
            if (connect(wordList[i], wordList[j]))
            {
                graph[wordList[i]].push_back(wordList[j]);
                graph[wordList[j]].push_back(wordList[i]);
            }
            
        }
    }
}

int bfs(string beginWord, string endWord)
{
    queue<pair<string, int>> Q;
    set<string> visit;
    Q.push({beginWord, 1});
    visit.insert(beginWord);

    while (!Q.empty())
    {
        string word = Q.front().first;
        int step = Q.front().second;
        Q.pop();
        if (word == endWord)
        {
            return step;
        }
        vector<string> neibor = graph[word];

        for (auto x : neibor)
        {
            if (visit.find(x) == visit.end())
            {
                Q.push({x, step + 1});
                visit.insert(x);
            }
        }
    }
    return 0;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
{
    construct(beginWord, wordList);
    return bfs(beginWord, endWord);
}