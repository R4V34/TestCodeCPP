/*
    Given a m x n matrix mat and an integer k, return a matrix answer
    where each answer[i][j] is the sum of all elements mat[r][c] for:

      * i - k <= r <= i + k
      * j - k <= c <= j + k
      * (r, c) is a valid position in the matrix.

    Task source: https://leetcode.com;
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

string to_string(vector<vector<int>> vec, int amount_of_spaces)
{
    string s = "";
    size_t ma = 0;
    string* spac;

    for (auto ve: vec)
        for (auto e: ve)
            ma = max(ma, to_string(e).size());

    spac = new string[ma + amount_of_spaces];
    spac[0] = "";
    for (int i = 1; i < ma + amount_of_spaces; i++) spac[i] = spac[i - 1] + " ";

    for (auto ve: vec)
    {
        for (auto e: ve)
            s = s + to_string(e) + spac[ma - to_string(e).size() + amount_of_spaces];
        s = s + "\n";
    }

    delete [] spac;
    return s;
}

vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k)
{
    if (k == 0) return mat;
    vector<vector<int>> res;
    vector<int> vec;
    short l, r, lI, rI, s1, s2;
    res.push_back(vec);
    res[0].push_back(0);
    short len1 = min(k + 1, (int)mat.size());
    short len2 = min(k + 1, (int)mat[0].size());

    for (int i = 0; i < len1; i++)
        for (int j = 0; j < len2; j++)
            res[0][0] += mat[i][j];

    len2 = mat[0].size();
    for (int j = 1; j < len2; j++)
    {
        res[0].push_back(res[0][j - 1]);
        lI = j - k - 1;
        rI = j + k;
        for (int i = 0; i < len1; i++)
            res[0][j] += (len2 > rI ? mat[i][rI] : 0) -
                         (-1 < lI   ? mat[i][lI] : 0);
    }

    len1 = mat.size();
    for (int z = 1; z < len1; z++){
        vector<int> vec;
        res.push_back(vec);
        for (int j = 0; j < len2; j++)
        {
            res[z].push_back(res[z - 1][j]);
            s1 = max(0, j - k);
            s2 = min(len2 - 1, j + k);
            lI = z - k - 1;
            rI = z + k;
            for (int i = s1; i <= s2; i++)
                res[z][j] += (len1 > rI ? mat[rI][i] : 0) -
                             (-1 < lI   ? mat[lI][i] : 0);
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> input2 = {{1, 2, 3, 1, 2, 3},
                                  {4, 5, 6, 4, 5, 6},
                                  {7, 8, 9, 7, 8, 9}};

    vector<vector<int>> input = {{1, 2, 3},
                                 {4, 5, 6},
                                 {7, 8, 9}};
    int k = 1;

    cout << to_string(matrixBlockSum(input2, k), 2);
    return 0;
}
