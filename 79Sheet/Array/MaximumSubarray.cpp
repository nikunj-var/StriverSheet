/*

https://leetcode.com/problems/maximum-subarray/description/

Given an integer array nums, find the
subarray with the largest sum, and return its sum.



Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
*/

#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int currentmax = 0;
        int globalmax = INT_MIN;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            currentmax += nums[i];
            if (currentmax > globalmax)
            {
                globalmax = currentmax;
            }
            if (currentmax < 0)
            {
                currentmax = 0;
            }
        }
        return globalmax;
    }
};