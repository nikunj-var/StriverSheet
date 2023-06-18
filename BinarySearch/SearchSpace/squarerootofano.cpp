#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    long long int floorSqrt(long long int x)
    {
        int start = 1;
        long long int ans;
        int end = x;
        long long int mid = start + (end - start) / 2;
        while (start <= end)
        {

            if (mid * mid == x)
            {
                return mid;
            }
            if (mid * mid > x)
            {
                end = mid - 1;
            }
            else
            {
                ans = mid;
                start = mid + 1;
            }
            mid = start + (end - start) / 2;
        }
        return ans;
    }
};
