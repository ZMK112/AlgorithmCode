#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

string str, pattern;
bool match(int i, int j){
    if (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.')
    {
        return true;
    }

    return false;
}

bool isMatch(string s, string p) {
    str = " " +s, pattern = " " + p;
    int n = s.length(), m = p.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[0][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (match(i, j))
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (pattern[j - 1] == '*')
            {
                if (match(i, j - 1))
                {
                    dp[i][j] = dp[i][j - 2] || dp[i - 1][j] || dp[i][j - 1];
                }
                else
                {
                    dp[i][j] = dp[i][j - 2];
                }
            }
        }
    }
    return dp[n][m];
}

bool isMatch(string s, string p) {
        s=" "+s;//·ÀÖ¹¸Ã°¸Àý£º""\n"c*"
        p=" "+p;
        int m=s.size(),n=p.size();
        bool dp[m+1][n+1];
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0]=true;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(match(i, j)){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    if(s[i-1]!=p[j-2] && p[j-2]!='.')
                        dp[i][j]=dp[i][j-2];
                    else{
                        dp[i][j]=dp[i][j-1] || dp[i][j-2] || dp[i-1][j];

                    }
                }
            }
        }
        return dp[m][n];
    }


bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j - 1)) {
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else {
                    if (matches(i, j)) {
                        f[i][j] = f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }

int main()
{
    string a = "aab", b = "accca*b";
    isMatch(a, b);
    return 0;
}