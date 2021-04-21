/*
    Given a string s, return the longest palindromic substring in s.

    Task source: https://leetcode.com;
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestPalindrome(string s) {
    if (s.size() < 2) return s;
    vector<int> d1;
    int maxL = 0, maxR = 0;
    int l = 0, r = -1;
    for (int i = 0; i < s.size(); i++) {
        int k = i > r ? 1 : min (d1[l + r - i], r - i + 1);
        while (i + k < s.size() && i - k >= 0 && s[i + k] == s[i - k]) k++;
        d1.push_back(k);
        if (i + k - 1 > r)
        {
            l = i - k + 1;
            r = i + k - 1;
        }
        if (maxR - maxL < r - l) {maxR = r; maxL = l;}
    }
    string s1 = s.substr(maxL, maxR - maxL + 1);
    vector<int> d2;
    l = 0; r = -1;
    for (int i = 0; i < s.size(); i++) {
        int k = i > r ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while ( i + k < s.size() && i - k - 1 >= 0 && s[i + k] == s[i - k - 1]) k++;
        d2.push_back(k);
        if (i + k - 1 > r)
        {
            l = i - k;
            r = i + k - 1;
        }
        if (maxR - maxL < r - l)  {maxR = r; maxL = l;}
    }
    string s2 = s.substr(maxL, maxR - maxL + 1);
    return s1.size() > s2.size() ? s1 : s2;
}

int main()
{
    string input = "ababababa";
    cout << longestPalindrome(input);
    return 0;
}
