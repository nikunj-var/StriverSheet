#include <vector>
using namespace std;
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (nums[mid] == target)
            {
                return true;
            }
            else if (nums[mid] == nums[start] && nums[mid] == nums[end])
            {
                start++;
                end--;
            }
            else if (nums[start] <= nums[mid])
            {
                if (nums[start] <= target && nums[mid] > target)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else
            {
                if (nums[end] >= target && nums[mid] < target)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};