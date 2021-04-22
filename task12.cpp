/*
    Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

        Symbol       Value
        I             1
        V             5
        X             10
        L             50
        C             100
        D             500
        M             1000

    For example, 2 is written as II in Roman numeral, just two one's added together.
    12 is written as XII, which is simply X + II. The number 27 is written as XXVII,
    which is XX + V + II.

    Roman numerals are usually written largest to smallest from left to right. However,
    the numeral for four is not IIII. Instead, the number four is written as IV.
    Because the one is before the five we subtract it making four. The same principle
    applies to the number nine, which is written as IX. There are six instances where
    subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9.
    X can be placed before L (50) and C (100) to make 40 and 90.
    C can be placed before D (500) and M (1000) to make 400 and 900.

    Given an integer, convert it to a roman numeral.

    Task source: https://leetcode.com;
*/

#include <iostream>
#include <vector>

using namespace std;

string intToRoman(int num) {
    if (num < 1 || num > 3999) return "incorrect number";
    vector<string> r = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
                        "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
                        "", "C", "CC", "CCC", "DC", "D", "DC", "DCC", "DCCC", "CM",
                        "", "M", "MM", "MMM"};
    return r[num / 1000 % 10 + 30] + r[num / 100 % 10 + 20] + r[num / 10 % 10 + 10] + r[num % 10];
}

int main()
{
    int input = 1994;
    cout << intToRoman(input);
    return 0;
}