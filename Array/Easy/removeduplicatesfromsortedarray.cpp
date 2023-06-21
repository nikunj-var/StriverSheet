#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0 || nums.size() == 1)
            return nums.size();

        int left = 0;
        int right = 0;
        while (right < nums.size())
        {
            if (nums[left] != nums[right])
            {
                left++;
            }
            nums[left] = nums[right];
            right++;
        }
        return left + 1;
    }
};