/*
    Given a string s and a dictionary of strings wordDict, return true
    if s can be segmented into a space-separated sequence of one or more
    dictionary words.

    Note that the same word in the dictionary may be reused multiple
    times in the segmentation.

    Task source: https://leetcode.com;
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <limits>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    if (s.size() == 0) return true;
    unordered_map<string, bool> m;
    for (auto const & e: wordDict) m[e] = true;
    int length = s.size();
    bool* mat = new bool[length];
    auto en = m.end();
    string str;
    for (int l = 0; l < length; l++)
    {
        str += s[l];
        if (m.find(str) != en) mat[l] = true;
        else mat[l] = false;
    }

    for (int l = 1; l < length; l++)
        if (mat[l - 1])
        {
            str = "";
            for (int i = l; i < length; i++)
            {
                str += s[i];
                if (m.find(str) != en) mat[i] = true;
            }
        }

    return mat[length - 1];
}

int main()
{
    string s = "applepenapple";
    vector<string> wordDict = {"apple","pen"};

    cout << (wordBreak(s, wordDict) ? "true" : "false");
    return 0;
}
