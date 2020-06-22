#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

set<string> sets;

void permutations(string& s, int point)
{
    if (point == s.size() - 1)
    {
        sets.insert(s);
    }
    else
    {
        for (int i = point; i < s.size(); ++i)
        {
            swap(s[point], s[i]);
            permutations(s, point+1);
            swap(s[point],s[i]);
        }   
    }
}

vector<string> permutation(string& s)
{   
    if (s.size() == 0)
    {   
        vector<string> res;
        return res;
    }
    
    int point = 0;
    permutations(s, point);

    vector<string> res(sets.begin(), sets.end());
    return res;
}


int main()
{
    string str = "abcd";
    string tmp = str.substr(0, 2);
    vector<string> res = permutation(str);
    return 0;
}