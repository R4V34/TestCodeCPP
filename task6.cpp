/*
    The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
    of rows like this: (you may want to display this pattern in a fixed font for better legibility)

    P     A     H     N
    A  P  L  S  I  I  G
    Y     I     R

    Task source: https://leetcode.com;
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string my_bad_convert(string str, int numRows) {
    if (numRows == 1) return str;
    string s = "";
    int len = str.size();
    int step1;
    int step2;
    int amount = 0;

    step1 = (numRows - 1) * 2;
    for (int i = 0; i < len; i += step1) s = s + str[i];

    step1 = (numRows - 2) * 2;
    step2 = 2;
    for (int j = 1; j < numRows - 1; j++)
    {
        for (int i = j; i < len; i += (amount % 2) == 1 ? step1 : step2) {
            s = s + str[i];
            amount++;
        }
        step1 -= 2;
        step2 += 2;
        amount = 0;
    }

    step1 = (numRows - 1) * 2;
    for (int i = numRows - 1; i < len; i += step1) s = s + str[i];

    return s;
}

string good_alternative_convert(string s, int numRows) {

        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
}

int main()
{
    string input = "1234567890abcdefg";
    int rows_number = 5;
    cout << my_bad_convert(input, rows_number);
    return 0;
}
