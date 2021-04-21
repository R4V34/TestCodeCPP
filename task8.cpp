/*
    Given a signed 32-bit integer x, return x with its digits reversed.
    If reversing x causes the value to go outside the signed 32-bit integer
    range [-2147483648, 2147483647], then return 0.

    Task source: https://leetcode.com;
*/

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int bad_but_right_site_myAtoi(string str) {
        int i = 0;
        bool has_minus = false;
        int res = 0;
        if (str.length() == 0) return 0;

        while (i < str.length() && str[i] == ' ') i++;

        if (i < str.length() && (str[i] == '+' || str[i] == '-')) has_minus = str[i++] == '-';

        while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
            if (res > INT_MAX / 10 ||
                    (res == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10)) {
                return has_minus ? INT_MIN : INT_MAX;
            }
            res = res * 10 + (str[i++] - '0');
        }
        return res * (has_minus ? -1 : 1);
    }

int myAtoi(string s) {
    bool is_negative = false;
    int l = 0;
    string num = "";
    while (isspace(s[l]) != 0) l += isspace(s[l]) != 0;
    s = s.substr(l, s.size() - l);

    if (s.size() == 0) return 0;
    if (s[0] == '-') {
        s = s.substr(1, s.size() - 1);
        is_negative = true;
        if (s.size() == 0) return 0;
    }

    l = 0;
    while (l < s.size() && s[l] >= '0' && s[l] <= '9')
    {
        num += s[l];
        l++;
    }

    if (num.size() == 0) return 0;
    l = 0;
    for (auto ch: num) l = l * 10 + ch - '0';
    return l * (is_negative ? -1 : 1);
}

int main()
{
    string input = "    -12345678987654321 THIS TASK SO BAD :(   ";

    cout << "bad_Atoi: " + to_string(bad_but_right_site_myAtoi(input)) << "\n"
         << "myAtoi:   " + to_string(myAtoi(input)) << "\n"
         << "atoi:     " + to_string(atoi(input.c_str()));
    return 0;
}
