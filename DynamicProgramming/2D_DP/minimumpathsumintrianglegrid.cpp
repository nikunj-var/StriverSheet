// https : // leetcode.com/problems/triangle/description/

#include <vector>
using namespace std;
// using recursion
class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &triangle, int n)
    {
        if (i == n - 1)
        {
            return triangle[i][j];
        }
        int down = triangle[i][j] + solve(i + 1, j, triangle, n);
        int diagonal = triangle[i][j] + solve(i + 1, j + 1, triangle, n);
        return min(down, diagonal);
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        return solve(0, 0, triangle, n);
    }
};

// using recursion and memoization
class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
    {
        if (i == n - 1)
        {
            return triangle[i][j];
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int down = triangle[i][j] + solve(i + 1, j, triangle, n, dp);
        int diagonal = triangle[i][j] + solve(i + 1, j + 1, triangle, n, dp);
        return dp[i][j] = min(down, diagonal);
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 0, triangle, n, dp);
    }
};

// using tabulation
class Solution
{
public:
    int solve(vector<vector<int>> &triangle, int n)
    {
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            dp[n - 1][i] = triangle[n - 1][i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int down = triangle[i][j] + dp[i + 1][j];
                int diagonal = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down, diagonal);
            }
        }
        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();

        return solve(triangle, n);
    }
};

// using space optimisation
class Solution
{
public:
    int solve(vector<vector<int>> &triangle, int n)
    {
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++)
        {
            dp[i] = triangle[n - 1][i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            vector<int> prev(n, 0);
            for (int j = i; j >= 0; j--)
            {
                int down = triangle[i][j] + dp[j];
                int diagonal = triangle[i][j] + dp[j + 1];
                prev[j] = min(down, diagonal);
            }
            dp = prev;
        }
        return dp[0];
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();

        return solve(triangle, n);
    }
};