/*
    Given a signed 32-bit integer x, return x with its digits reversed.
    If reversing x causes the value to go outside the signed 32-bit integer
    range [-2147483648, 2147483647], then return 0.

    Task source: https://leetcode.com;
*/

#include <iostream>

using namespace std;

int reverse_(int x) {
    long long res = 0;
    while (x != 0)
    {
        res = res * 10 + x % 10;
        x /= 10;
    }
    if (res > 2147483647 || res < -2147483648) return 0;
    return (int)res;
}

int main()
{
    int input = 123456789;
    cout << to_string(reverse_(input));
    return 0;
}
