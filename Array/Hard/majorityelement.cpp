#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int n = nums.size();
        vector<int> res;
        if (n == 1 || (n == 2 && nums[0] != nums[1]))
            return nums;
        if (n == 2 && nums[0] == nums[1])
        {
            res.push_back(nums[0]);
            return res;
        }

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        for (auto it : mp)
        {
            if (it.second > n / 3)
            {
                res.push_back(it.first);
            }
        }
        return res;
    }
};