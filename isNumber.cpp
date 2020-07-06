#include <iostream>
#include <vector>
using namespace std;


//如下算法设计实际上失败了，使用指针的方式，可以实现bool值和指针移动，最具有简洁性
// 
// bool flag = false;

// string Unint(string s)
// {
//     while (s[0] >= '0' && s[0] <= '9'){
//         s = s.substr(1);
//     }
//     return s; 
// }

// string ints(string &s)
// {
//     if (s[0] == '+' || s[0] == '-')
//     {
//         s.substr(1);
//     }
//     while (s[0] >= '0' && s[0] <= '9'){
//         s.substr(1);
//     }
//     return s;
// }

// bool compare_one(string one, string two)
// {
//     return one.size() < two.size() ? true : false;
// }

// bool compare_two(string one, string two)
// {
//     return one.size() < two.size() - 1? true : false;
// }

// string trim(string s)
// {   
//     if (s.empty()) 
//     {
//         return s;
//     }
//     s.erase(0,s.find_first_not_of(" "));
//     s.erase(s.find_last_not_of(" ") + 1);
//     return s;
// }

// bool isNumber(string s)
// {   
//     s = trim(s);
//     if (s.empty() || s.find(" ") != s.npos)
//     {
//         return false;
//     }
//     string tmp = ints(s);
//     string tmp_two;
//     bool numeric = compare_two(tmp, s);
//     if (tmp[0] == '.')
//     {
//         tmp = tmp.substr(1);
//         tmp_two = Unint(tmp);
//         numeric = numeric || compare_one(tmp_two, tmp);
//         tmp =tmp_two; 
//     }
//      if (tmp[0] == 'e'|| tmp[0] == 'E')
//      {
//          tmp_two = tmp.substr(1);
//          tmp = ints(tmp_two);
//          numeric = numeric && compare_two(tmp, tmp_two);
//      }
//      return numeric && tmp.empty();
// }

int point = 0;

bool Unint(string s)
{   
    int p = point;
    while (s[point] >= '0' && s[point] <= '9')
    {
        point++;
    }
    return point > p;
}

bool ints(string s)
{
    int p = point;
    if (s[point] == '+' || s[point] == '-')
    {
        point++;
    }
    return Unint(s);
}

string trim(string s)
{   
    if (s.empty()) 
    {
        return s;
    }
    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    if (s.find(" ") != s.npos)
    {
        s = "";
    }    
    return s;
}


bool isNumber(string s)
{   
    s = trim(s);
    if (s.empty())
    {
        return false;
    }

    bool numeric = ints(s);

    if (s[point] == '.')
    {
        point++;
        numeric = Unint(s) || numeric;
    }
    if (s[point] == 'e'|| s[point] == 'E')
    {   
        point++;
        numeric = numeric && ints(s);
    }
    return numeric && (point == s.size());
}

int main()
{
    string s = "0.8";
    bool one = isNumber(s);
    // cout<< s.substr(1);
    return 0;
}
