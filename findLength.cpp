#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
using namespace std;

//滑动窗口的方式
int find(vector<int>& a, vector<int>& b, int pa, int pb, int lens)
{
    int num = 0, res = 0;
    for (int i = 0; i < lens; i++)
    {
        if (a[i + pa] == b[i + pb])
        {
            num++;
        }
        else
        {
            num = 0;
        }
        res = max(res, num);
    }
    return res;
}

    // int find(vector<int>& A, vector<int>& B, int A_initial_position, int B_initial_position, int both_length) {
    //     int k = 0;
    //     int res = 0;
    //     for (int i = 0; i < both_length; i++) {
    //         if (A[A_initial_position + i] == B[B_initial_position + i])
    //             k++;
    //         else k = 0;
    //         res = max(res, k);
    //     }
    //     return res;
    // }


int findLength(vector<int>& A, vector<int>& B) {
    int lens1 = A.size(), lens2 = B.size();
    int res = 0;

    for (int i = 0; i < lens1; i++)
    {
        int length = min(lens1 - i, lens2);
        res = max(res, find(A, B, i, 0, length));    
    }

    for (int j = 0; j < lens2; j++)
    {
        int length = min(lens2 - j, lens2);
        res = max( res, find(A, B, 0, j, length));
    }
    
    return res;
}


int findLength2(vector<int>& A, vector<int>& B) {
    int lens1 = A.size(), lens2 = B.size();
    int res = 0;
    vector<vector<int>> dp(lens1 + 1, vector<int>(lens2 + 1, 0));

    for (int i = 1; i <= lens1; i++)
    {
        for (int j = 1; j <= lens2; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = 0;
            }
            res = max(res, dp[i][j]);
        }
    }
    return res;
}