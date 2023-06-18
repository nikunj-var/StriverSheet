#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int solve(vector<int> &nums, int target, int start, int end)
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                return mid;
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
        return -1;
    }
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n == 1)
        {
            return (nums[0] == target) ? 0 : -1;
        }
        return solve(nums, target, 0, n);
    }
};