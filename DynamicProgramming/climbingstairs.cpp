#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // using recursion
    int solve(int n)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }
        return solve(n - 2) + solve(n - 1);
    }

    // using recursion and memoization
    int solve(int n, vector<int> &dp)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }

    // using tabular method
    int solve(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    // using space optimisation
    int solve(int n)
    {
        if (n == 0 || n == 1)
        {
            return n;
        }
        int prev = 1;
        int curr = 1;
        int next;
        for (int i = 2; i <= n; i++)
        {
            next = curr + prev;
            prev = curr;
            curr = next;
        }
        return next;
    }
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return solve(n);
    }
};