/*
    Alice and Bob take turns playing a game, with Alice starting first.

    Initially, there is a number n on the chalkboard. On each player's turn,
    that player makes a move consisting of:

    Choosing any x with 0 < x < n and n % x == 0.
    Replacing the number n on the chalkboard with n - x.
    Also, if a player cannot make a move, they lose the game.

    Return true if and only if Alice wins the game, assuming both players
    play optimally.

    Task source: https://leetcode.com;
*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool best_solution(int n)
{
    return n % 2 == 0;
}

vector<int> get_number_factors(int n)
{
    vector<int> vec = {1};
    int l = round(sqrt(n) + 0.5);
    for (int i = 2; i < l; i++)
        if (n % i == 0) {
            vec.push_back(i);
            if (i != n / i) vec.push_back(n / i);
        }
    return vec;
}

bool dynamic_divisorGame(int n) {
    if (n == 1) return false;
    bool* arr = new bool[n];
    arr[n - 1] = 0;
    for (int i = n - 1; i > 0; i--)
    {
        vector<int> vec = get_number_factors(i + 1);
        for (int f: vec) arr[i - f] = !arr[i];
    }
    bool res = arr[0];
    delete [] arr;
    return res;
}

int main()
{
    int number = 1337;
    cout << "Dynamic:   " << (dynamic_divisorGame(number) ? "true" : "false") << "\n"
         << "Best O(1): " << (best_solution(number) ? "true" : "false");
    return 0;
}
