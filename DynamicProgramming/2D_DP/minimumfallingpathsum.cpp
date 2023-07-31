// https://leetcode.com/problems/minimum-falling-path-sum/description/

#include <vector>
using namespace std;

// using recursion
class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &matrix, int n)
    {
        if (j < 0 || j >= n)
        {
            return 1e9;
        }
        if (i == 0)
        {
            return matrix[0][j];
        }

        int left = INT_MAX, right = INT_MAX, up = INT_MAX;

        left = matrix[i][j] + solve(i - 1, j - 1, matrix, n);

        right = matrix[i][j] + solve(i - 1, j + 1, matrix, n);

        up = matrix[i][j] + solve(i - 1, j, matrix, n);

        return min(left, min(up, right));
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {

        int mini = INT_MAX;
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, solve(n - 1, i, matrix, n));
        }
        return mini;
    }
};

// using recursion and memoization
class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &matrix, int n, vector<vector<int>> &dp)
    {
        if (j < 0 || j >= n)
        {
            return 1e9;
        }
        if (i == 0)
        {
            return matrix[0][j];
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        // int left = INT_MAX,right=INT_MAX,up=INT_MAX;

        int left = matrix[i][j] + solve(i - 1, j - 1, matrix, n, dp);

        int right = matrix[i][j] + solve(i - 1, j + 1, matrix, n, dp);

        int up = matrix[i][j] + solve(i - 1, j, matrix, n, dp);

        return dp[i][j] = min(left, min(up, right));
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {

        int mini = INT_MAX;
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, solve(n - 1, i, matrix, n, dp));
        }
        return mini;
    }
};

// using tabulation
class Solution
{
public:
    int solve(vector<vector<int>> &matrix, int n)
    {

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = matrix[0][i];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int left = INT_MAX, right = INT_MAX, up = INT_MAX;

                if (j > 0)
                    left = matrix[i][j] + dp[i - 1][j - 1];
                if (j + 1 < n)
                    right = matrix[i][j] + dp[i - 1][j + 1];

                up = matrix[i][j] + dp[i - 1][j];

                dp[i][j] = min(left, min(right, up));
            }
        }
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, dp[n - 1][i]);
        }
        return mini;
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        return solve(matrix, n);
    }
};

// using space optimisation
class Solution
{
public:
    int solve(vector<vector<int>> &matrix, int n)
    {

        vector<int> prev(n, 0);
        for (int i = 0; i < n; i++)
        {
            prev[i] = matrix[0][i];
        }
        for (int i = 1; i < n; i++)
        {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++)
            {
                int left = INT_MAX, right = INT_MAX, up = INT_MAX;

                if (j > 0)
                    left = matrix[i][j] + prev[j - 1];
                if (j + 1 < n)
                    right = matrix[i][j] + prev[j + 1];

                up = matrix[i][j] + prev[j];

                temp[j] = min(left, min(right, up));
            }
            prev = temp;
        }
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, prev[i]);
        }
        return mini;
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        return solve(matrix, n);
    }
};