#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

string removeKdigits(string num, int k) {
    stack<int> stacks;
    string res = "";

    for (int i = 0; i < num.length(); i++)
    {
        int number = num[i] - '0';
        while (!stacks.empty() && stacks.top() > number && k > 0)
        {
            stacks.pop();
            k--;
        }
        if (number != 0 || !stacks.empty())
        {
            stacks.push(number);
        }
    }
    
    while (!stacks.empty() && k > 0)
    {
        stacks.pop();
        k--;
    }

    while (!stacks.empty())
    {
        res.append(1, '0' + stacks.top());
        stacks.pop();
    }
    
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string a = "1432219";
    removeKdigits(a, 3);
    return 0;
}