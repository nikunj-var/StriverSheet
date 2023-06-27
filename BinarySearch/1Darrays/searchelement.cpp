#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int binarysearch(vector<int> &nums, int target, int low, int high)
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
        return -1;
    }
    int search(vector<int> &nums, int target)
    {
        int size = nums.size();
        return binarysearch(nums, target, 0, size - 1);
    }
};