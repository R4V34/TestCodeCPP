/*
    You are given an integer array cost where cost[i] is the cost of ith
    step on a staircase. Once you pay the cost, you can either climb one
    or two steps.

    You can either start from the step with index 0, or the step with index 1.

    Return the minimum cost to reach the top of the floor.

    Task source: https://leetcode.com;
*/

#include <iostream>
#include <vector>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int len = cost.size();
    int* res = new int[len];
    res[0] = cost[0];
    res[1] = min(cost[1] + cost[0], cost[1]);
    for (int i = 2; i < len; i++)
        res[i] = cost[i] + min(res[i - 2], res[i - 1]);
    len = min(res[len - 1], res[len - 2]);
    delete [] res;
    return len;
}

int main()
{
    vector<int> cost = {10, 15, 20};
    cout << to_string(minCostClimbingStairs(cost));
    return 0;
}
