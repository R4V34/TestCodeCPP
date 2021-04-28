/*
    Alex and Lee play a game with piles of stones. There are an even number
    of piles arranged in a row, and each pile has a positive integer number of
    stones piles[i].

    The objective of the game is to end with the most stones.  The total number
    of stones is odd, so there are no ties.

    Alex and Lee take turns, with Alex starting first.  Each turn, a player takes
    the entire pile of stones from either the beginning or the end of the row.
    This continues until there are no more piles left, at which point the person
    with the most stones wins.

    Assuming Alex and Lee play optimally, return True if and only if Alex wins
    the game.

    Task source: https://leetcode.com;
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool stoneGame(vector<int>& piles) {
        int N = piles.size();

        int dp[N + 2][N + 2];
        memset(dp, 0, sizeof(dp));

        for (int s = 1; s <= N; s++)
            for (int i = 0, j = s - 1; j < N; i++, j++) {

                int parity = (j + i + N) % 2;
                if (parity == 1)
                    dp[i + 1][j + 1] = max(piles[i] + dp[i + 2][j + 1], piles[j] + dp[i + 1][j]);
                else
                    dp[i + 1][j + 1] = min(-piles[i] + dp[i + 2][j + 1], -piles[j] + dp[i + 1][j]);

            }

    return dp[1][N] > 0;
}

int main()
{
    vector<int> stones = {1,100,2};
    cout << (stoneGame(stones) ? "true" : "false");
    return 0;
}
