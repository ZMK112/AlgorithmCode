#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
    
    
queue<int> data;
void push(int x) {
    queue<int> tmp_queue;
    tmp_queue.push(x);
    while (!data.empty())
    {
        tmp_queue.push(data.front());
        data.pop();
    }
    
    while (!tmp_queue.empty())
    {
        data.push(tmp_queue.front());
        tmp_queue.pop();
    }
    
}

int pop() {
    int x = data.front();
    data.pop();
    return x;
}

int top()
{
    return data.front();
}

bool empty()
{
    return data.empty();
}