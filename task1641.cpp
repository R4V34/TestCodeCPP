/*
    Given an integer n, return the number of strings of length n that consist
    only of vowels (a, e, i, o, u) and are lexicographically sorted.

    A string s is lexicographically sorted if for all valid i, s[i] is the
    same as or comes before s[i+1] in the alphabet.

    Task source: https://leetcode.com;
*/

#include <iostream>
#include <vector>

using namespace std;



int countVowelStrings(int n) {
    if (n < 1) return 0;
    int** mat = new int*[4];
    for (int i = 0; i < 4; i++)
    {
        mat[i] = new int[n];
        mat[i][0] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        mat[0][i] = 1 +         mat[0][i - 1];
        mat[1][i] = mat[0][i] + mat[1][i - 1];
        mat[2][i] = mat[1][i] + mat[2][i - 1];
        mat[3][i] = mat[2][i] + mat[3][i - 1];
    }
    return 1 + mat[0][n - 1] + mat[1][n - 1] + mat[2][n - 1] + mat[3][n - 1];
}

int main()
{
    int n = 33;
    cout << to_string(countVowelStrings(n));
    return 0;
}
