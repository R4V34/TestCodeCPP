/*
    Given a string s, find the length of the longest
    substring without repeating characters.

    Task source: https://leetcode.com;
*/

#include <iostream>
#include <bits/stdc++.h>
#define NO_OF_CHARS 256

using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int res = 0;
    vector<char> lastIndex();
    int i = 0;
    for (int j = 0; j < n; j++) {
        i = max(i, (int)lastIndex[s[j]] + 1);
        res = max(res, j - i + 1);
        lastIndex[s[j]] = (int)j;
    }
    return res;
}

int main()
{
    string input;
    cin >> input;
    cout << to_string(lengthOfLongestSubstring(input));
    return 0;
}
