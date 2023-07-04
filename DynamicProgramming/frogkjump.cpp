#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
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
    int minimizeCost(vector<int> &height, int n, int k)
    {
        vector<int> dp(n + 1, -1);
        return solve(height, n - 1, k, dp);
    }
};
