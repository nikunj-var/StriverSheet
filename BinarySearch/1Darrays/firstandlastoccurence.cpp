#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums, int target, int start, int end)
    {
        int mid;
        int pos = -1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                pos = mid;
                end = mid - 1;
            }
            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        cout << pos;
        return pos;
    }
    int solve2(vector<int> &nums, int target, int start, int end)
    {
        int mid, pos = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                pos = mid;
                start = mid + 1;
            }
            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        cout << " " << pos;
        return pos;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans;
        int n = nums.size();

        int first = solve(nums, target, 0, n - 1);
        int second = solve2(nums, target, 0, n - 1);
        ans.push_back(first);
        ans.push_back(second);
        return ans;
    }
};