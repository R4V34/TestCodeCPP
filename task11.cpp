/*
    Given n non-negative integers a1, a2, ..., an , where each represents
    a point at coordinate (i, ai). n vertical lines are drawn such that the
    two endpoints of the line i is at (i, ai) and (i, 0). Find two lines,
    which, together with the x-axis forms a container, such that the container
    contains the most water.

    Notice that you may not slant the container.

    Task source: https://leetcode.com;
*/

#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
    int result = 0;
    int l = 0;
    int r = height.size() - 1;
    while (l < r)
    {
        result = max(result, min(height[l], height[r]) * (r - l));
        if (height[l] < height[r]) l++;
        else r--;
    }
    return result;
}

int main()
{
    vector<int> vec = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << to_string(maxArea(vec));
    return 0;
}
