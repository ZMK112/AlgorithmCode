#include <iostream>
#include <vector>
using namespace std;

string Uint(string s)
{
    while (s[0] > '0' && s[0] < '9'){
        s.substr(1);
    }
    return s; 
}

string ints(string s)
{
    if (s[0] == '+' || s[0] == '-'){
        s.substr(1);
    }
    return Uint(s);
}

bool isNumber(string s)
{
    if (s.empty())
    {
        return false;
    }
    string sOne = 
    
}