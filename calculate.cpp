#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

stack<int> number;
stack<char> operation;

void cal()
{
    if (number.size() < 2)
    {
        return;
    }

    int b = number.top();
    number.pop();

    int a = number.top();
    number.pop();

    if (operation.top() == '+')
    {
        number.push(a + b);
    }
    else if (operation.top() == '-')
    {
        number.push(a - b);
    }
    operation.pop();
}

int calculate(string s) {
    const int BEGIN = 0;
    const int NUMBER = 1;
    const int OPERATION = 2;
    int flag = 0;
    int state = BEGIN;
    int num = 0;

    for (int i = 0; i < s.length(); i++)
    {   
        if(s[i] == ' ') continue;

        switch (state)
        {
        case BEGIN:
            if(s[i] >= '0' && s[i] <= '9')
            {
                state = NUMBER;
            }
            else
            {
                state = OPERATION;
            }
            i--;
            break;
        
        case NUMBER:
            if (s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + s[i] - '0';
            }
            else
            {
                number.push(num);
                if (flag)
                {
                    cal();
                }
                num = 0;
                i--;
                state = OPERATION;
            }
            break;
        
        case OPERATION:
            if (s[i] == '+' || s[i] == '-')
            {
                operation.push(s[i]);
                flag = 1;
            }
            else if (s[i] == '(')
            {
                state = NUMBER;
                flag = 0;
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                state = NUMBER;
                i--;
            }
            else if (s[i] == ')')
            {
                cal();
            }
            break;
        }
    }
    if (num != 0)
    {
        number.push(num);
        cal();
    }
    if (num == 0 && number.empty())
    {
        return 0;
    }
    return number.top();
}

class Solution {
public:
stack<int> number;
stack<char> operation;

void cal()
{
    if (number.size() < 2)
    {
        return;
    }

    int b = number.top();
    number.pop();

    int a = number.top();
    number.pop();

    if (operation.top() == '+')
    {
        number.push(a + b);
    }
    else if (operation.top() == '-')
    {
        number.push(a - b);
    }
    operation.pop();
}

int calculate(string s) {
    const int BEGIN = 0;
    const int NUMBER = 1;
    const int OPERATION = 2;
    int flag = 0;
    int state = BEGIN;
    long long int num = 0; //注意此处的是 long long int的数据类型

    for (int i = 0; i < s.length(); i++)
    {   
        if(s[i] == ' ') continue;

        switch (state)
        {
        case BEGIN:
            if(s[i] >= '0' && s[i] <= '9')
            {
                state = NUMBER;
            }
            else
            {
                state = OPERATION;
            }
            i--;
            break;
        
        case NUMBER:
            if (s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + s[i] - '0';
            }
            else
            {
                number.push(num);
                if (flag)
                {
                    cal();
                }
                num = 0;
                i--;
                state = OPERATION;
            }
            break;
        
        case OPERATION:
            if (s[i] == '+' || s[i] == '-')
            {
                operation.push(s[i]);
                flag = 1;
            }
            else if (s[i] == '(')
            {
                state = NUMBER;
                flag = 0;
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                state = NUMBER;
                i--;
            }
            else if (s[i] == ')')
            {
                cal();
            }
            break;
        }
    }
    if (num != 0)
    {
        number.push(num);
        cal();
    }
    if (num == 0 && number.empty())
    {
        return 0;
    }
    cout<< number.top();
    return number.top();
}
};

int main()
{
    string a = "2147483647"; 
    calculate(a);
    return 0;
}