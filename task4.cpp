/*
    Given two sorted arrays nums1 and nums2 of size m and n
    respectively, return the median of the two sorted arrays.

    Task source: https://leetcode.com;
*/

#include <iostream>
#include <vector>

using namespace std;


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() == 0 && nums2.size() == 0) throw "Empty vectors";
    if (nums1.size() == 0 && nums2.size() % 2 == 1) return nums2[nums2.size() / 2];
    if (nums2.size() == 0 && nums1.size() % 2 == 1) return nums1[nums1.size() / 2];
    if (nums1.size() == 0 && nums2.size() % 2 == 0)
        return (nums2[nums2.size() / 2] + nums2[nums2.size() / 2 - 1]) / 2.0;
    if (nums2.size() == 0 && nums1.size() % 2 == 0)
        return (nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1]) / 2.0;

    int len1 = nums1.size();
    int len2 = nums2.size();
    int len = nums1.size() + nums2.size();
    int j1 = -1;
    int j2 = -1;
    bool nowOn1 = nums1[0] < nums1[0];
    int lostJ1 = -1;
    int lostJ2 = -1;
    bool lostNowOn1;

    for (int i = 0; i < len / 2 + 1; i++){
        lostJ1 = j1;
        lostJ2 = j2;
        lostNowOn1 = nowOn1;
        if (j2 + 1 == len2 ||
           (j1 + 1 != len1 && nums1[min(j1 + 1, len1 - 1)] < nums2[min(j2 + 1, len2 - 1)]))
            { j1++; nowOn1 = true; }
        else
            { j2++; nowOn1 = false; }
    }

    if (len % 2 == 1)
        return nowOn1 ? nums1[j1] : nums2[j2];
    else
        return ((nowOn1 ? nums1[j1] : nums2[j2]) +
                (lostNowOn1 ? nums1[lostJ1] : nums2[lostJ2])) / 2.0;
}

int main()
{
    vector<int> v1 = {1,2};
    vector<int> v2 = {3,4};
    try
    {
        cout << to_string(findMedianSortedArrays(v1, v2));
    }
    catch(const char* ex)
    {
        cout << ex;
    }
    return 0;
}
