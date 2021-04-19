/*
    Given a string s, find the length of the longest
    substring without repeating characters.

    Task source: https://leetcode.com;
*/

#include <iostream>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string str) {
    int j = 0;
    int max_len = -1;
    int str_len = str.size();
    unordered_map<char, int> m;
    for (int i = 0; i < str_len; i++)
        if (m.find(str[i]) == m.end()) m[str[i]] = i;
        else
        {
            if (m[str[i]] >= j) {
                max_len = max(i - j, max_len);
                j = m[str[i]] + 1;
            }
            m[str[i]] = i;
        }

    return max_len == -1 ? str_len : max(max_len, str_len - j);
}

int main()
{
    string input;
    cin >> input;
    cout << to_string(lengthOfLongestSubstring(input));
    return 0;
}
