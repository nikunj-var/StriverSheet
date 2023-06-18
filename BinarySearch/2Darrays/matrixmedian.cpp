// Algorithm:

// First, we find the minimum and maximum elements in the matrix. The minimum element can be easily found by comparing the first element of each row, and similarly, the maximum element can be found by comparing the last element of each row.
// Then we use binary search on our range of numbers from minimum to maximum, we find the mid of the min and max and get a count of numbers less than or equal to our mid. And accordingly change the min or max.
// For a number to be median, there should be (r*c)/2 numbers smaller than that number. So for every number, we get the count of numbers less than or equal to that by using upper_bound() in each row of the matrix, if it is less than the required count, the median must be greater than the selected number, else the median must be less than or equal to the selected number.

#include <iostream>
#include <vector>
using namespace std;

// User function template for C++

class Solution
{
public:
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < R; i++)
        {
            mini = min(mini, matrix[0][i]);
            maxi = max(maxi, matrix[i][C - 1]);
        }
        int desired = (R * C + 1) / 2;
        while (mini < maxi)
        {
            int mid = mini + (maxi - mini) / 2;
            int place = 0;

            for (int i = 0; i < R; i++)
            {
                place += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if (place < desired)
            {
                mini = mid + 1;
            }
            else
            {
                maxi = mid;
            }
        }
        return mini;
    }
};