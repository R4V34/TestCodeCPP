/*
    Given an input string (s) and a pattern (p), implement regular expression matching
    with support for '.' and '*' where:

    '.' Matches any single character.​​​​
    '*' Matches zero or more of the preceding element.

    The matching should cover the entire input string (not partial).

    Task source: https://leetcode.com;
*/

#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

bool isMatch_fun(string s, string p)
{
    std::regex pa(p);
    return std::regex_match(s.c_str(), pa);
}

int fun(vector<vector<int>> &dp, string &s, string &p, int a, int b)
{
    if(a==0 && b==0) return 1;
    if(b==0) return 0;
    if(dp[a][b]!=-1) return dp[a][b];
    if(p[b-1]=='*')
    {
        int f=fun(dp,s,p,a,b-2);
        int r=0;
        while(1)
        {
            if(a-r>0 && (s[a-1-r]==p[b-2] || p[b-2]=='.')) r++;
            else break;
            f=f|(fun(dp,s,p,a-r,b-2));
        }
        return dp[a][b]=f;
    }
    if(a==0) return dp[a][b]=0;
    if(p[b-1]=='.' || s[a-1]==p[b-1]) return dp[a][b]=fun(dp,s,p,a-1,b-1);
    return dp[a][b]=0;
}

bool isMatch(string s, string p) {
    vector<char*> pattern;
    for (auto ch: p)
    {
        if (ch == '.')
        {
            char* ne = new char[2];
            ne[0] = '.';
            ne[1] = '1';
            pattern.push_back(ne);
        }
        else if (ch == '*')
        {
            if (pattern.size() == 0) return false;
            pattern[pattern.size() - 1][1] = 'A';
        }
        else
        {
            char* ne = new char[2];
            ne[0] = ch;
            ne[1] = '1';
            pattern.push_back(ne);
        }
    }
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < pattern.size(); j++)
            cout << pattern[j][i] << " ";
        cout << "\n";
    }

    return true;
}

int main()
{
    string s = "mississippi";
    string p = "mis*is*p*.";
    cout << (isMatch_fun(s, p) ? "true" : "false");
    return 0;
}
