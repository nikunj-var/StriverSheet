#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int solve(vector<int> &height, int n)
    {
        if (n == 0)
        {
            return 0;
        }
        int onemove = solve(height, n - 1) + abs(height[n] - height[n - 1]);
        int twomove = INT_MAX;
        if (n > 1)
            twomove = solve(height, n - 2) + abs(height[n] - height[n - 2]);
        return min(onemove, twomove);
    }
    int solve(vector<int> &height, int n, vector<int> &dp)
    {
        if (n == 0)
        {
            return 0;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        int onemove = solve(height, n - 1, dp) + abs(height[n] - height[n - 1]);
        int twomove = INT_MAX;
        if (n > 1)
            twomove = solve(height, n - 2, dp) + abs(height[n] - height[n - 2]);
        return dp[n] = min(onemove, twomove);
    }
    int solve(vector<int> &height, int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            int onemove = dp[i - 1] + abs(height[i] - height[i - 1]);
            int twomove = INT_MAX;
            if (i > 1)
            {
                twomove = dp[i - 2] + abs(height[i] - height[i - 2]);
            }
            dp[i] = min(onemove, twomove);
        }
        return dp[n - 1];
    }
    int solve(vector<int> &height, int n)
    {
        int prev1 = 0;
        int prev2 = 0;
        int curr;
        for (int i = 1; i < n; i++)
        {
            int onemove = prev1 + abs(height[i] - height[i - 1]);
            int twomove = INT_MAX;
            if (i > 1)
            {
                twomove = prev2 + abs(height[i] - height[i - 2]);
            }
            curr = min(onemove, twomove);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int minimumEnergy(vector<int> &height, int n)
    {
        vector<int> dp(n + 1, -1);
        return solve(height, n);
    }
};