#include <iostream>
#include <vector>
using namespace std;

// recursion
int solve(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return solve(n - 1) + solve(n - 2);
}

// recursion and memoization
int solve(int n, vector<int> &dp)
{

    if (n == 0 || n == 1)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
}
// tabular form
int solve(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    for (int i = 0; i <= n; i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
    return dp[n];
}
// space optimisation
int solve(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    int prev = 0;
    int curr = 1;
    int next = 0;
    for (int i = 2; i <= n; i++)
    {
        next = curr + prev;
        prev = curr;
        curr = next;
        cout << next << " ";
    }
    return next;
}
int main()
{
    cout << "enter n";
    int n;
    cin >> n;
    cout << solve(n);
}
