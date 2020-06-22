#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

vector<string> res;

void generate(int left, int right, string str)
{
    if (left == 0 && right == 0)
    {
        res.push_back(str);
        return;
    }
    if (left > 0)
    {
        str += "(";
        generate(left - 1, right, str);
    }
    if (left < right)
    {
        str += ")";
        generate(left, right - 1, str);
    }
    
}

vector<string> generateParenthesis(int n) {
    if(!n) return res;
    string str = "";
    generate(n, n, str);
    return res;    
}