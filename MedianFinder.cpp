#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

priority_queue<double, vector<double>, greater<double>> small;
priority_queue<double> big;

void addNum(double num) 
{
    if (big.empty())
    {
        big.push(num);
        return;
    }

    if (small.size() == big.size())
    {
        if (num > big.top())
        {
            small.push(num);
        }
        else
        {
            big.push(num);
        }
    }
    else if (small.size() > big.size())
    {
        if (num < small.top())
        {
            big.push(num);
        }
        else
        {
            big.push(small.top());
            small.pop();
            small.push(num);
        }
    }
    else if(big.size() > small.size())
    {
        if (num > big.top())
        {
            small.push(num);
        }
        else
        {
            small.push(big.top());
            big.pop();
            big.push(num);
        }
    }
}


double findMedian() {
    if (small.size() == big.size())
    {
        return (small.top() + big.top()) / 2.0;
    }
    else if(small.size() > big.size())
    {
        return small.top();
    }
    return big.top();
}