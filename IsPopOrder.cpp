#include <iostream>
#include <vector>
#include <stack>
using namespace std;    
    
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    bool res = false;

    if (!pushed.empty() && !popped.empty())
    {   
        int push = 0;
        int pop = 0;
        int lens = popped.size();
        stack<int> tmpStack;

        while (pop < lens)
        {
            while (tmpStack.empty() || tmpStack.top() != popped[pop])
            {
                if (push == lens)
                {
                    break;
                }
                tmpStack.push(pushed[push]);
                push++;
            }
            if (tmpStack.top() != popped[pop])
            {
                break;
            }
            tmpStack.pop();
            pop++;
        }
        if (tmpStack.empty() && pop == lens)
        {
            res = true;
        }      
    }
    else
    {
        return true;
    }
    
    return res;
}

int main()
{
    vector<int> pop;
    vector<int> push;
    int pushed[5] = {1,2,3,4,5};
    int popped[5] = {4,5,3,2,1};
    for (int i = 0; i < 5; i++)
    {
        pop.push_back(popped[i]);
        push.push_back(pushed[i]);
    }
    
    bool res = validateStackSequences(push, pop);
    return 0;
}