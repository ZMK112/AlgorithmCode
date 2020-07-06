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

bool wordBreak(string s, vector<string>& wordDict) {
    set<string> words;
    for(auto x: wordDict) words.insert(x);
    vector<int> visit(s.size() + 1, 0);
    queue<int> q;

    q.push(0);
    
    while (!q.empty())w
    {
        int i = q.front();
        q.pop();

        if(visit[i]) continue;
        for (int j = i; j < s.size(); j++)
        {
            string tmp = s.substr(i, j - i + 1);
            if (words.count(tmp))
            {
                if (j == s.size() - 1)
                {
                    return true;
                }
                q.push(j + 1);
            }
        }
        visit[i] = 1;
    }
    return false;
}

int main()
{
    string a = "abcd";
    vector<string> b = {"a","abc","b","cd"};
    wordBreak(a,b);
    return 0;
}