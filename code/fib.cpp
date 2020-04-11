#include <iostream>

// int fib2(int n){
//     if(n == 0){
//         return 0;
//     }
//     else if(n == 1)
//     {
//         return 1;
//     }
//      else
//      {
//         return fib(n - 1) + fib(n - 2);
//      }
     
// }

int fib(int n)
{
    if (n == 0)
    {
        return 0; 
    }
    else if(n == 1){
        return 1;
    }
    else
    {
        long long fib_one = 1;
        long long fib_two = 0;
        long long fibn = 0;
        for (int i = 2; i <= n; i++)
        {
            fibn = (fib_one + fib_two)%1000000007;
            fib_two = fib_one;
            fib_one = fibn;
        }
        return fibn;
    }    
}

int numWays(int n)
{
    if(n == 0){
        return 1;
    }
    if (n == 1){
        return 1;
    }
    int one = 1;
    int two = 1;
    int way = 0;
    for (int i = 2; i <= n; i++)
    {
        way = (one + two) % 1000000007;
        one = two;
        two = way;
    }
    return way;  
}


int main()
{
    int c = numWays(2);
    printf("%d",c);
    return 0;
}