#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;


bool patternMatching(string pattern, string value) 
{   
    vector<int> cnt(2, 0);
    for(auto i: pattern){
        cnt[i - 'a']++;
    }

    int cntA = cnt[0], cntB = cnt[1];

    if (value.empty())
    {
        return cntB == 0;
    }

    if (pattern.empty())
    {
        return false;
    }
    
    for (int i = 0; i * cntA <= value.size(); i++)
    {
        int allB = value.size() - i * cntA;
        
    }
    
    
}



















// bool check(string pattern, string value, int lenA, int lenB)
// {
//     string strA = "", strB = "";
//     for (int i = 0, j = 0; i < pattern.size(); i++)
//     {
//         if (pattern[i] == 'a')
//         {
//             if (strA == "")
//             {
//                 strA = value.substr(j, lenA);
//             }
//             else if(strA != value.substr(j, lenA))
//             {
//                 return false;
//             }
//             j += lenA;
//         }
        
//         if (pattern[i] == 'b')
//         {
//             if (strB == "")
//             {
//                 strB = value.substr(j, lenB);
//             }
//             else if(strB != value.substr(j, lenB))
//             {
//                 return false;
//             }
//             j += lenB;
//         }
//     }
//     return true;
// }

// bool help(string value, int num)
// {
//     int valLength = value.length();
    
//     if (valLength % num != 0)
//     {
//         return false;
//     }
    
//     int length = value.size() / num;
//     string str = value.substr(0, length);

//     for (int i = length; i < value.size(); i += length)
//     {
//         if (value.substr(i, length) != str)
//         {
//             return false;
//         }
//     }

//     return true;
// }

// bool patternMatching(string pattern, string value) {
//     int n = pattern.size(), m = value.size();
//     vector<int> cnt(2, 0);
//     for(auto i: pattern)
//         cnt[i - 'a']++;

//     int lenA = cnt[0], lenB = cnt[1];

//     if (!lenA)
//     {
//         return help(value, lenB);
//     }
//     else if(!lenB)
//     {
//         return help(value, lenA);
//     }
    
//     for (int i = 1; i * lenA <= m - lenB ; i++)
//     {   
//         int numB = (m - i * lenA) / lenB;
//         if ((m - i * lenA) % lenB == 0)
//         {
//             continue;
//         }
//         if (check(pattern, value, i, numB))
//         {
//             return true;
//         }
//     }

//     return false;
// }


