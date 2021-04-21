/*
    Given an integer x, return true if x is palindrome integer.
    An integer is a palindrome when it reads the same backward as
    forward. For example, 121 is palindrome while 123 is not.

    Task source: https://leetcode.com;
*/

#include <iostream>
#include <string>

using namespace std;

bool better_IsPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        return x == revertedNumber || x == revertedNumber / 10;
    }

bool my_isPalindrome(int x) {
    string s = to_string(x);
    for (int i = 0; i < s.size() / 2; i++)
        if (s[i] != s[s.size() - 1 - i]) return false;
    return true;
}

int main()
{
    int input = 1233321;
    cout << (my_isPalindrome(input) ? "true" : "false") << "\n" <<
            (better_IsPalindrome(input) ? "true" : "false");
    return 0;
}
