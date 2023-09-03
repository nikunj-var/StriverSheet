/*
https://leetcode.com/problems/majority-element-ii/description/

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.



Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]

*/

// Using Boyer Moore Algorithm

#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> ans;
        int num1 = INT_MIN, num2 = INT_MIN;
        int count1 = 0, count2 = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (num1 == nums[i])
            {
                count1++;
            }
            else if (num2 == nums[i])
            {
                count2++;
            }
            else if (count1 == 0)
            {
                num1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0)
            {
                num2 = nums[i];
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == num1)
            {
                count1++;
            }
            else if (nums[i] == num2)
            {
                count2++;
            }
        }
        if (count1 > n / 3)
        {
            ans.push_back(num1);
        }
        if (count2 > n / 3)
        {
            ans.push_back(num2);
        }
        return ans;
    }
};

// T.C - O(N) S.C - O(1)