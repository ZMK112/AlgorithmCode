#include <iostream>
#include <vector>
using namespace std;


bool matchCore(char* str, char* pattern)
{
    if (*str == '\0' && *pattern == '\0')
    {
        return true;
    }

    if (*str != '\0' && *pattern == '\0')
    {
        return false;
    }

    if (*(pattern + 1) == '*')
    {
        if (*pattern == *str || (*pattern == '.' && *str != '\0'))
        {
            return matchCore(str + 1,  pattern + 2) //能够进来表示，能跟*匹配
                   || matchCore(str + 1, pattern)   //
                   || matchCore(str, pattern + 2); //
        }
        else
        {
            return matchCore(str, pattern + 2);
        }
    }
    if (*str == *pattern || (*pattern == '.' && *str != '\0'))
    {
        return matchCore(str + 1, pattern + 1);
    }
    return false;
}

bool matches(string s, string p)
{
    if (p.empty())
    {
        return s.empty();
    }

    if (p.size() > 1 && p[1] == '*' )
    {
        if (s[0] == p[0] || (p[0] == '.' && !s.empty()))
        {
            return matches(s.substr(1),p);            
        }
        else
        {
            return matches(s, p.substr(2));
        } 
    }
    if (s[0] == p[0] || (p[0] == '.' && !s.empty()))
    {
        return matches(s.substr(1), p.substr(1));
    }
    return false;
}


bool match(char* str, char* pattern)
{
    if (str == nullptr || pattern == nullptr)
    {
        return false;
    }
    return matchCore(str, pattern);
    
}

bool isMatch(string s, string p)
{
    if (p.empty())
    {
        return s.empty();
    }

    if (p.size() > 1 && p[1] == '*' )
    {
        if (s[0] == p[0] || (p[0] == '.' && !s.empty()))
        {
            return isMatch(s.substr(1),p)||isMatch(s, p.substr(2));            
        }
        else
        {
            return isMatch(s, p.substr(2));
        } 
    }
    if (s[0] == p[0] || (p[0] == '.' && !s.empty()))
    {
        return isMatch(s.substr(1), p.substr(1));
    }
    return false;
}

int main()
{
    string a = "aaaa";
    string  b = "a*a";
    bool res = isMatch(a,b);
    return 0; 
}