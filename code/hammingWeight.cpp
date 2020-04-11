#include <iostream>
#include <string.h>

// int hammingWeight(uint32_t n) {
//     int num = 0;
//     while (n)
//     {
//         if (n & 1)
//         {
//             num++;
//         }
//         n = n >> 1;
//     }
//     return num;
// }

int hammingWeight(uint32_t n)
{
    int num = 0;
    while (n)
    {
        n = (n - 1) & n;
        num++;
    }
    return num;
}

int main()
{
    int num = hammingWeight(00000000000000000000000000001011);
    printf("%d",num);
    return 0;
}