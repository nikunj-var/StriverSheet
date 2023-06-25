#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> positive;
        vector<int> negative;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                negative.push_back(nums[i]);
            }
            else
            {
                positive.push_back(nums[i]);
            }
        }
        int i = 0, j = 0;
        while (i < positive.size() && j < negative.size())
        {
            ans.push_back(positive[i++]);
            ans.push_back(negative[j++]);
        }
        while (i < positive.size())
        {
            ans.push_back(positive[i++]);
        }
        while (j < negative.size())
        {
            ans.push_back(negative[j++]);
        }
        return ans;
    }
};