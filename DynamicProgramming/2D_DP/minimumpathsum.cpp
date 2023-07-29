// https://leetcode.com/problems/minimum-path-sum/description/

#include <vector>
using namespace std;

// using recursion
class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &grid)
    {
        if (i == 0 && j == 0)
        {
            return grid[i][j];
        }
        if (i < 0 || j < 0)
        {
            return 1e9;
        }
        int up = INT_MAX;
        int left = INT_MAX;
        up = grid[i][j] + solve(i - 1, j, grid);
        left = grid[i][j] + solve(i, j - 1, grid);
        return min(up, left);
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        return solve(m - 1, n - 1, grid);
    }
};

// using recursion and memoization
class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
        {
            return grid[i][j];
        }
        if (i < 0 || j < 0)
        {
            return 1e9;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int up = INT_MAX;
        int left = INT_MAX;
        up = grid[i][j] + solve(i - 1, j, grid, dp);
        left = grid[i][j] + solve(i, j - 1, grid, dp);
        return dp[i][j] = min(up, left);
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, grid, dp);
    }
};

// using tabulation
class Solution
{
public:
    int solve(int m, int n, vector<vector<int>> &grid)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = grid[0][0];
                }
                else
                {
                    int up = INT_MAX;
                    int left = INT_MAX;
                    if (i > 0)
                        up = grid[i][j] + dp[i - 1][j];
                    if (j > 0)
                        left = grid[i][j] + dp[i][j - 1];
                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        return solve(m, n, grid);
    }
};