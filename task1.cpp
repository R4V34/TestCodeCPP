/*
    Given an array of integers nums and an integer target,
    return indices of the two numbers such that they add up to target.
    You may assume that each input would have exactly one solution,
    and you may not use the same element twice. You can return the
    answer in any order.

    Task source: https://leetcode.com;
*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
        if (m.find(target - nums[i]) != m.end())
            return { min(i, m[target - nums[i]]),
                     max(i, m[target - nums[i]]) };
        else m[nums[i]] = i;
    throw "no solution";
}

int main()
{
    vector<int> nums = {6, 3, 2, 444, 4};
    int target = 6;


    try
    {
        auto res = twoSum(nums, target);
        cout << "{" << res[0] << "; " << res[1] << "}";
    }
    catch (...)
    {
        cout << "no solution";
    }
    return 0;
}
