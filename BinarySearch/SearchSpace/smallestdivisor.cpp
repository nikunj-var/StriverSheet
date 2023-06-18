#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isvalid(vector<int> &nums, int threshold, int maxi)
    {

        int sum = 0;
        for (auto i : nums)
        {
            if (i < maxi)
            {
                sum++;
            }
            else
            {
                int temp = i;
                while (temp > 0)
                {
                    sum++;
                    temp -= maxi;
                }
            }
            if (sum > threshold)
            {
                return false;
            }
        }
        return true;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int maxi = INT_MIN;
        for (auto i : nums)
        {
            maxi = max(i, maxi);
        }
        int start = 1;
        int ans = -1;
        int end = maxi;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (isvalid(nums, threshold, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
};