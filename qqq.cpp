#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string str = "abcd";
    string tmp = str.substr(0, str.size());
    cout<<tmp;
    int i = 0;
    while (tmp[i] == '\0')
    {
        printf("%c",tmp[i++]);
    }
    
    return 0;
}