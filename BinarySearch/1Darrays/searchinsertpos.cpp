#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int searchpos(vector<int> &nums, int target, int low, int high)
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
    int searchInsert(vector<int> &nums, int target)
    {
        int size = nums.size();
        return searchpos(nums, target, 0, size - 1);
    }
};