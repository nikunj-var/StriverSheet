// https : // leetcode.com/problems/unique-paths-ii/description/

#include <vector>
        using namespace std;

// Using Recursion
class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &obstacleGrid)
    {
        if (i == 0 && j == 0)
        {
            return 1;
        }
        if (i < 0 || j < 0)
        {
            return 0;
        }
        int up = 0;
        if (i > 0 && obstacleGrid[i - 1][j] != 1)
        {
            up = solve(i - 1, j, obstacleGrid);
        }
        int left = 0;
        if (j > 0 && obstacleGrid[i][j - 1] != 1)
        {
            left = solve(i, j - 1, obstacleGrid);
        }
        return up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1)
        {
            return 0;
        }
        return solve(m - 1, n - 1, obstacleGrid);
    }
};

// Using Recursion and Memoization
class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
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
        int up = 0;
        if (i > 0 && obstacleGrid[i - 1][j] != 1)
        {
            up = solve(i - 1, j, obstacleGrid, dp);
        }
        int left = 0;
        if (j > 0 && obstacleGrid[i][j - 1] != 1)
        {
            left = solve(i, j - 1, obstacleGrid, dp);
        }
        return dp[i][j] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[m - 1][n - 1] == 1)
        {
            return 0;
        }
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, obstacleGrid, dp);
    }
};

// using tabulation
class Solution
{
public:
    int solve(int m, int n, vector<vector<int>> &obstacleGrid)
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
                    if (i > 0 && obstacleGrid[i - 1][j] != 1)
                    {
                        up = dp[i - 1][j];
                    }
                    if (j > 0 && obstacleGrid[i][j - 1] != 1)
                    {
                        left = dp[i][j - 1];
                    }
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[m - 1][n - 1] == 1)
        {
            return 0;
        }

        return solve(m, n, obstacleGrid);
    }
};

// using space optimisation
class Solution
{
public:
    int solve(int m, int n, vector<vector<int>> &obstacleGrid)
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
                    if (i > 0 && obstacleGrid[i - 1][j] != 1)
                    {
                        up = prev[j];
                    }
                    if (j > 0 && obstacleGrid[i][j - 1] != 1)
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
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[m - 1][n - 1] == 1)
        {
            return 0;
        }

        return solve(m, n, obstacleGrid);
    }
};