#include <iostream>
#include <vector>
using namespace std;

double myPow(double x, int n)
{
    if (n < 0)
    {
        int res = myPowCore(x, n);
        return 1/res; 
    }
    else
    {
        int res = myPowCore(x, n);
        return res;
    }
}

double myPowCore(double x, int n) {
    if (n == 0)
    {
        return 1; 
    }
    else if (n == 1)
    {
        return x;
    }
    else
    {
        double res = myPow(x, n >> 1);
        res *= res;
        if (n & 1 == 1)
        {
            res *= x;
        }
        return res;
    }
}



int main()
{
    int res = myPow(2,12);
    printf("%d",res);
    return 0;
}