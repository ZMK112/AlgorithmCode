#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
using namespace std;

string findLongest(string& a, string& b)
{
    int i = 0 , j = 0;
    int lens = min(a.size(), b.size());
    for (; i < lens && a[i] == b[j]; i++ , j++);
    string res = a.substr(0, i);
    return res;
} 

string longestCommonPrefix1(vector<string>& strs) {
    if(strs.empty()) return "";//�˴�return nullptr�����ԣ� 
    string str = strs[0];
    for (int i = 0; i < strs.size(); i++)
    {
        str = findLongest(str, strs[i]);
    }
    return str;
}


//����ķ�ʽ����ÿ���ַ�����һ��
string longestCommonPrefix(vector<string>& strs) {
    for (int i = 0; i < strs[0].size(); i++)
    {
        char c =  strs[0][i];
        for (int j = 0; j < strs.size(); j++) //j��0��ͷ�����һ���Լ�
        {
            if (strs[j][i] != c || i == strs[j].size())
            {
                return strs[0].substr(0, i);
            }
        }
    }
    return strs[0]; //��Ϊ����strs[0]������ַ�����ʼ��
}

