#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

// int cuttingRope(int n) 
// {
    
//     if (n < 2)
//     {
//         return 0;
//     }
//     if (n == 2)
//     {
//         return 1;
//     }
//     if (n == 3)
//     {
//         return 2;
//     }

//     int *res = new int[n + 1];
//     int max = 0;
//     res[1] = 1;
//     res[2] = 2;
//     res[3] = 3;

//     for (int i = 4; i <= n; i++)
//     {   max = 0;
//         for (int j = 1; j <= i/2; j++)
//         {
//             int tmp = res[j] * res[i - j];
//              if (max < tmp){
//                  max = tmp;
//              }
//         }
//         res[i] = max;
//     }
//     max = res[n];
//     return max;
// }


// int pows(int n, int m)
// {   
//     int res = 1;
//     if (m == 3)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             res = (res * 3) % 1000000007;
//         }
//         return res;
//     }
//     else
//     {
//         for (int i = 0; i < n; i++)
//         {
//             res = (res * 2) % 1000000007;
//         }
//         return res;
//     }
// }


// int cuttingRope(int n)
// {
    // if (n < 2)  
    // {
    //     return 1;
    // }
    // if (n == 2)
    // {
    //     return 1;
    // }
    // if (n == 3)
    // {
    //     return 2;
    // }
    
//     int timeThree = n / 3;
//     if (n - timeThree * 3 == 1)
//     {
//         timeThree--;
//     }
//     int timeTwo = (n - timeThree * 3) / 2;
//     int max = pows(timeThree, 3) * pows(timeTwo, 2);
//     return max % 1000000007;
// }

int cuttingRope(int n)
{
    if (n < 2)  
    {
        return 1;
    }
    if (n == 2)
    {
        return 1;
    }
    if (n == 3)
    {
        return 2;
    }

    long long res = 1;
    while (n > 4)
    {
        res *= 3;
        res %= 1000000007;
        n -= 3;
    }
    return res * n % 1000000007;
    
}

int main()
{
    int n = cuttingRope(127);
    printf("%d",n);
    return 0;
}