// An Efficient Solution can find the required element in O(Log n) time. The idea is to use Binary Search. Below is an observation on the input array. 
// All elements before the required have the first occurrence at even index (0, 2, ..) and the next occurrence at odd index (1, 3, …). And all elements after the required elements have the first occurrence at an odd index and the next occurrence at an even index. 

// Find the middle index, say ‘mid’.
// If ‘mid’ is even, then compare arr[mid] and arr[mid + 1]. If both are the same, then the required element after ‘mid’ and else before mid.
// If ‘mid’ is odd, then compare arr[mid] and arr[mid – 1]. If both are the same, then the required element after ‘mid’ and else before mid.

// approach in different manner
// : An Efficient Solution can find the required element in O(Log n) time. The idea is to use Binary Search without recursion. All elements before the required have the first occurrence at even index (0, 2, ..and so on) and the next occurrence at odd index (1, 3, ..and so on). 

// The approach will be as follows:

// Find the middle index assuming mid using start pointer and end pointer. And check the mid element in the following cases

// Case 1) If mid element is not equal to mid+1 element  and mid-1 element. This case returns the answer.
// Case 2) When mid element is even and equal to mid+1 element this means number is not present in the left side of the array. In this case start pointer will change to mid+1.
// Case 3) When mid element is odd and equal to mid-1 element this means number is not present in the left side of the array. In this case start pointer will change to mid+1.
// Case 4) When mid element is odd and equal to mid+1 element this means number is not present in the right side of the array. In this case end pointer will change to mid-1.
// Case 5) When mid element is even and equal to mid-1 element this means number is not present in the right side of the array. In this case end pointer will change to mid-1. 
// Check for all case for possible values of mid till start<=end..

// If all checks fail there is no such element.

// This solution requires extra checks for edge cases.

// Edge Case 1) If only one element is present in the array. Therefore return the only element of the array.
// Edge Case 2) If last element of the array is the required element. Therefore return the last element of the array.
// Edge Case 3) If first element of the array is the required element. Therefore return the first element of the array.

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        while (start <= end)
        {
            if (start == end)
            {
                return nums[start];
            }
            int mid = start + (end - start) / 2;
            if (mid % 2 == 0)
            {
                if (nums[mid] == nums[mid + 1])
                {
                    start = mid + 2;
                }
                else
                {
                    end = mid;
                }
            }
            else
            {
                if (nums[mid] == nums[mid - 1])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return nums[start];
    }
};