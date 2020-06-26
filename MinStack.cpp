#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// stack<int> datas;
// stack<int> mins;

// void push(int x) {
//     datas.push(x);
//     if (mins.empty() || x < mins.top())
//     {
//         mins.push(x);
//     }
//     else
//     {
//         mins.push(mins.top());
//     }
// }

// void pop() {
//     if (!mins.empty() && !datas.empty())
//     {
//         mins.pop();
//         datas.pop();
//     }
// }

// int top() {
//     return datas.top();
// }

// int min() {
//     return mins.top();
// }

stack<int> data;
stack<int> mins;

void push(int x) {
    if (mins.empty() || x < mins.top())
    {
        mins.push(x);
    }
    else
    {
        mins.push(mins.top());
    }
    data.push(x);
}

void pop() {
    if(!data.empty() && !mins.empty()){
        data.pop();
        mins.pop();
    }

}

int top() {
    return data.top();
}

int getMin() {
    return mins.top();
}