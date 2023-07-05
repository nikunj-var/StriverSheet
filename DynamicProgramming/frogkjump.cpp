#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    // recursion + memoization
    int solve(vector<int> &height, int n, int k, vector<int> &dp)
    {
        if (n == 0)
        {
            return 0;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        int ans = INT_MAX;
        for (int i = 1; i <= k; i++)
        {
            if (n >= i)
            {
                ans = min(ans, abs(height[n] - height[n - i]) + solve(height, n - i, k, dp));
            }
        }
        return dp[n] = ans;
    }
    // tabular
    int solve(vector<int> &height, int n, int k)
    {
        if (n == 0)
        {
            return 0;
        }
        vector<int> dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            int ans = INT_MAX;
            for (int j = 1; j <= k; j++)
            {
                if (i - j >= 0)
                {
                    ans = min(ans, abs(height[i] - height[i - j]) + dp[i - j]);
                }
            }
            dp[i] = ans;
        }
        return dp[n];
    }
    int minimizeCost(vector<int> &height, int n, int k)
    {
        vector<int> dp(n + 1, -1);
        return solve(height, n - 1, k, dp);
    }
};
