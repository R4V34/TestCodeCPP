/*
    You are given an array prices where prices[i]
    is the price of a given stock on the i-th day.

    You want to maximize your profit by choosing
    a single day to buy one stock and choosing a 
    different day in the future to sell that stock.

    Return the maximum profit you can achieve from
    this transaction. If you cannot achieve any profit,
    return 0.
*/


#include<iostream>
#include<string>
#include<vector>

using namespace std;


int maxProfit(vector<int>& prices) {
    if (prices.size() < 2) return 0;
    int mi = prices[0];
    int ma = 0;
    for (int i = 1; i < prices.size(); i++){
        ma = max(prices[i] - mi, ma);
        mi = min(prices[i], mi);
    }
    return ma;
}

int main()
{
    vector<int> vec = {2,3,4};
    cout << to_string(maxProfit(vec));
    return 0;
}
