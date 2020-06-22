#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
using namespace std;

bool isPalindrome(string s) {
    string str = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (isalnum(s[i]))
        {
            str += tolower(s[i]);
        }
    }
    int left = 0, right = str.length() - 1;
    while (left < right)
    {
        if(s[left] != s[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}