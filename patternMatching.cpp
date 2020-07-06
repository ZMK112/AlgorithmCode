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

    if (cntA < cntB) {
        swap(cntA, cntB);
        for (char& ch: pattern) {
            ch = (ch == 'a' ? 'b' : 'a');
        }
    }

    if (value.empty())
    {
        return cntB == 0;
    }

    if (pattern.empty())
    {
        return false;
    }
    
    for (int i = 0, j = 0; i * cntA <= value.size(); i++)
    {
        int allB = value.size() - i * cntA;
        
        if ((cntB == 0 && allB == 0) || (cntB != 0 && allB % cntB == 0))
        {
            int lenB = cntB == 0 ? 0 : allB / cntB;
            string strA = "", strB = "";
            bool res = true;
            j = 0; // 错误原因是搞蒙了，以为每次循环j会被重新置0；
            for(auto x : pattern)
            {
                if (x == 'a')
                {
                    string strs = value.substr(j, i);
                    if(strA == "")
                    {
                        strA = strs;
                    }
                    else if(strA != strs)
                    {
                        res = false;
                        break;
                    }
                    j += i;
                }
                else
                {
                    string strs = value.substr(j, lenB);
                    if (strB == "")
                    {
                        strB = strs;
                    }
                    else if(strB != strs)
                    {
                        res =  false;
                        break;
                    }
                    j += lenB;
                }
            }
            if (strA != strB && res)
            {
                return true;
            }
        }
    }
    return false;
}

bool patternMatching2(string pattern, string value) {
        int count_a = 0, count_b = 0;
        for (char ch: pattern) {
            if (ch == 'a') {
                ++count_a;
            } else {
                ++count_b;
            }
        }
        if (count_a < count_b) {
            swap(count_a, count_b);
            for (char& ch: pattern) {
                ch = (ch == 'a' ? 'b' : 'a');
            }
        }
        if (value.empty()) {
            return count_b == 0;
        }
        if (pattern.empty()) {
            return false;
        }
		
        for (int len_a = 0, j = 0; count_a * len_a <= value.size(); ++len_a) {
            int rest = value.size() - count_a * len_a;
            if ((count_b == 0 && rest == 0) || (count_b != 0 && rest % count_b == 0)) {
                int len_b = (count_b == 0 ? 0 : rest / count_b);
                int j = 0;
                bool correct = true;
                string value_a, value_b;
                for (char ch: pattern) {
                    if (ch == 'a') {
                        string sub = value.substr(j, len_a);
                        if (!value_a.size()) {
                            value_a = move(sub);
                        } else if (value_a != sub) {
                            correct = false;
                            break;
                        }
                        j += len_a;
                    } else {
                        string sub = value.substr(j, len_b);
                        if (!value_b.size()) {
                            value_b = move(sub);
                        } else if (value_b != sub) {
                            correct = false;
                            break;
                        }
                        j += len_b;
                    }
                }
                if (correct && value_a != value_b) {
                    return true;
                }
            }
        }
        return false;
    }

int main()
{
    string a = "abba", b = "dogcatcatdog";
    bool res = patternMatching2(a, b);
    return 0;
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


