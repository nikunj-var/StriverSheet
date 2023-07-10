#include <iostream>
#include <vector>
using namespace std;
int solve(vector<int> &nums, int index, vector<int> &dp)
{
    if (index >= nums.size())
    {
        return 0;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }

    int include = nums[index] + solve(nums, index + 2, dp);
    int exclude = 0 + solve(nums, index + 1, dp);
    return dp[index] = max(include, exclude);
}

int solve(vector<int> &nums, int index)
{
    int n = nums.size();
    vector<int> dp(nums.size() + 1, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++)
    {
        int include = dp[i - 2] + nums[i];
        int exclude = dp[i - 1];
        dp[i] = max(include, exclude);
    }
    return dp[n - 1];
}
int solve(vector<int> &nums)
{
    int n = nums.size();
    int prev1 = nums[0];
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int include = prev2 + nums[i];
        int exclude = prev1;
        int maxi = max(include, exclude);
        prev2 = prev1;
        prev1 = maxi;
    }
    return prev1;
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    vector<int> dp(nums.size() + 1, -1);
    return solve(nums);
}