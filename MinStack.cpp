#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<int> datas;
stack<int> mins;

void push(int x) {
    datas.push(x);
    if (mins.empty() || x < mins.top())
    {
        mins.push(x);
    }
    else
    {
        mins.push(mins.top());
    }
}

void pop() {
    if (!mins.empty() && !datas.empty())
    {
        mins.pop();
        datas.pop();
    }
}

int top() {
    return datas.top();
}

int min() {
    return mins.top();
}