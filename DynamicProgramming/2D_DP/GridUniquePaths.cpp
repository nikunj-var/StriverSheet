#include <vector>
using namespace std;

// Using recursion

class Solution
{
public:
    int solve(int i, int j)
    {
        if (i == 0 && j == 0)
        {
            return 1;
        }
        if (i < 0 || j < 0)
        {
            return 0;
        }

        return solve(i - 1, j) + solve(i, j - 1);
    }
    int uniquePaths(int m, int n)
    {
        return solve(m - 1, n - 1);
    }
};

// using recursion and memoisation
class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
        {
            return 1;
        }
        if (i < 0 || j < 0)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        return dp[i][j] = solve(i - 1, j, dp) + solve(i, j - 1, dp);
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, dp);
    }
};

// using tabulation
class Solution
{
public:
    int solve(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    int up = 0, left = 0;
                    if (i > 0)
                    {
                        up = dp[i - 1][j];
                    }
                    if (j > 0)
                    {
                        left = dp[i][j - 1];
                    }
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
    int uniquePaths(int m, int n)
    {

        return solve(m, n);
    }
};

// using space optimisation
class Solution
{
public:
    int solve(int m, int n)
    {
        vector<int> prev(m, 0);
        for (int i = 0; i < m; i++)
        {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    temp[j] = 1;
                }
                else
                {
                    int up = 0, left = 0;
                    if (i > 0)
                    {
                        up = prev[j];
                    }
                    if (j > 0)
                    {
                        left = temp[j - 1];
                    }
                    temp[j] = up + left;
                }
            }
            prev = temp;
        }
        return prev[n - 1];
    }
    int uniquePaths(int m, int n)
    {

        return solve(m, n);
    }
};