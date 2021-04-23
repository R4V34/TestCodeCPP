/*
    Write a function to find the longest common prefix string amongst an array of strings.
    If there is no common prefix, return an empty string "".

    Task source: https://leetcode.com;
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0) return "";
    string res = "";
    int i = 0;
    while (true)
    {
        for (auto str: strs)
            if (i == str.size() || strs[0][i] != str[i]) return res;
        res = res + strs[0][i++];
    }
}

int main()
{
    vector<string> vec = {"aa", "aa"};
    cout << longestCommonPrefix(vec);
    return 0;
}
