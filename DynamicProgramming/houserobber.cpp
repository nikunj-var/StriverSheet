#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    // Function to find the maximum money the thief can get.
    int solve(int nums[], int n, vector<int> &dp)
    {
        if (n < 0)
            return 0;
        if (n == 0)
            return nums[0];

        if (dp[n] != -1)
            return dp[n];

        int incl = solve(nums, n - 2, dp) + nums[n];
        int excl = solve(nums, n - 1, dp) + 0;
        dp[n] = max(excl, incl);
        return dp[n];
    }
    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n + 1, -1);
        int ans = solve(arr, n - 1, dp);
        return ans;
    }
};
