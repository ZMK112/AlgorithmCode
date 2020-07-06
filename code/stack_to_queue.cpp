#include <stack>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
using namespace std;

class CQueue {
    stack<int> s1;
    stack<int> s2;
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if (s2.empty())
        {
            if(s1.empty()){
                return -1;
            }
            else{
                while (!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
        }
        int data = s2.top();
        s2.pop();
        return data;
    }
};


class CQueue {
    stack<int> stack_one;
    stack<int> stack_two;
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        stack_one.push(value);
    }
    
    int deleteHead() {
        if (stack_two.empty())
        {
            while (!stack_one.empty())
            {
                int data = stack_one.top();
                stack_two.push(data);
                stack_one.pop();
            }
        }
        else
        {
            int data = stack_two.top();
            stack_two.pop();
        }
        return data;
    }
};