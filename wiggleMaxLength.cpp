#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

// int wiggleMaxLength(vector<int>& nums) {
//     int lens = nums.size();
//     if (lens < 2)
//     {
//         return lens;
//     }
//     static const int BEGIN = 0;
//     static const int  UP = 1;
//     static const int DOWN = 2;
//     int STATE = BEGIN;
//     int length = 1;

//     for (int i = 1; i < lens; i++)
//     {
//         switch (STATE)
//         {
//         case BEGIN:
//             if(nums[i] < nums[i + 1])
//             {
//                 STATE = UP;
//                 length++;
//             }
//             else if(nums[i] > nums[i + 1])
//             {
//                 STATE = DOWN;
//                 length++;
//             }
//             break;
//         case UP:
//             if (nums[i] < nums[i + 1])
//             {
//                 STATE = DOWN;
//                 length++;
//             }
//             break;
//         case DOWN:
//             if (nums[i] > nums[i + 1])
//             {
//                 STATE = UP;
//                 length++;
//             }
//             break;
//         }
//     }
//     return length;
// }


int wiggleMaxLength(vector<int>& nums) {
    int up = 1, down = 1;
    int lens = nums.size();
    if (lens < 2)
    {
        return lens;
    }
    
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] < nums[i])
        {
            up = down + 1;
        }
        else if (nums[i - 1] > nums[i])
        {
            down = up + 1;
        }
    }
    return max(up, down);
}

//ÓÐÏÞ×´Ì¬»ú
int wiggleMaxLength(vector<int>& nums) {
    int lens = nums.size();
    if(lens < 2) return lens;
    int res = 1;

    const int BEGIN = 0;
    int state = BEGIN;
    const int UP = 1;
    const int DOWN = 2;

    for (int i = 1; i < lens; i++)
    {
        switch (state)
        {
        case BEGIN:
            if(nums[i - 1] < nums[i]){
                state = UP;
                res++;
            }
            else if(nums[i - 1] > nums[i])
            {
                state = DOWN;
                res++;
            }
            break;

        case UP:
            if (nums[i - 1] > nums[i])
            {
                state = DOWN;
                res++;
            }
            break;
        
        case DOWN:
            if (nums[i - 1] < nums[i])
            {
                state = UP;
                res++;
            }
            break;    
        }
    }
    return res;
}


string removeKdigits(string num, int k) {
    int lens = num.length();
    string res = "";
    if(!lens) return num;
    stack<int> stacks;
    stacks.push(num[0] - '0');
    for (int i = 1; i < lens; i++)
    {
        int number = num[i] - '0';

        while (!stacks.empty() && stacks.top() > number && k >0)
        {
            stacks.pop();
            k--;
        }

        if (!stacks.empty() || number != 0)
        {
            stacks.push(number);
        }
    }

    while (k > 0 && !stacks.empty())
    {
        stacks.pop();
        k--;
    }
    int length = stacks.size();
    for (int i = 0; i < length; i++)
    {
        res.append(1, stacks.top() - '0');
        stacks.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}