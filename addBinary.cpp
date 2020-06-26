#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

string addBinary(string a, string b) {
    if (a.length() > b.length())
    {
        swap(a,b);
    }
    
    vector<int> sum(b.length() + 1, 0);

    for (int i = b.length(), j = a.length(); i > 0; i--)
    {
        int bl = b[i - 1] - '0';
        if (j > 0)
        {
            int al = a[j - 1] - '0';
            sum[i] += al + bl;

            if (sum[i] / 2 != 0)
            {
                sum[i - 1] += sum[i] / 2;
                sum[i] %= 2;
            }
            j--;
        }
        else
        {
            sum[i] += bl;
            sum[i - 1] += sum[i] / 2;
            sum[i] %= 2;
        }
    }

    string res = "";

    for (int i = 0; i < sum.size(); i++)
    {   
        if(sum[i] == 0 && i == 0)
            continue;
        res += sum[i] + '0';
    }
    
    return res;
}

int main()
{
    string a = "0", b = "0";
    addBinary(a, b);
    return 0;
}