#include <vector>
using namespace std;
class Solution
{
public:
    void solve(vector<int> &candidates, vector<vector<int>> &ans, vector<int> temp, int target, int index)
    {
        if (target < 0)
        {
            return;
        }
        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if (index >= candidates.size())
        {
            return;
        }
        if (target > 0)
        {
            temp.push_back(candidates[index]);
            solve(candidates, ans, temp, target - candidates[index], index);
            temp.pop_back();
        }
        solve(candidates, ans, temp, target, index + 1);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        int index = 0;
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, ans, temp, target, index);
        return ans;
    }
};