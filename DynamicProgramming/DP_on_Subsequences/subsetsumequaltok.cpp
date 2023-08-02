#include <vector>
using namespace std;

// using recursion
bool solve(int n, vector<int> &arr, int k)
{

    if (k == 0)
    {
        return true;
    }
    if (k < 0)
    {
        return false;
    }
    if (n < 0)
    {
        return false;
    }
    bool include = solve(n - 1, arr, k - arr[n]);
    bool exclude = solve(n - 1, arr, k);
    return include || exclude;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    return solve(n - 1, arr, k);
}

// using memoization

bool solve(int ind, vector<int> &arr, int target, vector<vector<int>> &dp)
{

    if (target == 0)
    {
        return true;
    }
    if (target < 0 || ind < 0)
    {
        return false;
    }
    if (dp[ind][target] != -1)
    {
        return dp[ind][target];
    }
    bool include = solve(ind - 1, arr, target - arr[ind], dp);
    bool exclude = solve(ind - 1, arr, target, dp);
    return dp[ind][target] = include || exclude;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(n - 1, arr, k, dp);
}

// using tabulation

bool solve(int n, vector<int> &arr, int target, vector<vector<int>> &dp)
{

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (arr[0] <= target)
    {
        dp[0][arr[0]] = true;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            bool include = false;
            if (arr[i] <= j)
                include = dp[i - 1][j - arr[i]];
            bool exclude = dp[i - 1][j];
            dp[i][j] = include || exclude;
        }
    }
    return dp[n - 1][target];
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, false));
    return solve(n, arr, k, dp);
}