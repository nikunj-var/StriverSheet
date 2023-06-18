#include <iostream>
#include <climits>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isvalid(vector<int> &weights, int n, int days, int maxi)
    {
        int count = 1;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += weights[i];
            if (sum > maxi)
            {
                count++;
                sum = weights[i];
            }
            if (count > days)
            {
                return false;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int maxi = INT_MIN, sum = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            sum += weights[i];
            maxi = max(weights[i], maxi);
        }
        int start = maxi;
        int end = sum;
        int ans = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (isvalid(weights, weights.size(), days, mid))
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