#include <iostream>
#include <unordered_map>
using namespace std;

// approach1

class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        unordered_map<int, int> mp;
        int *ans = new int[2];
        for (int i = 0; i < n; i++)
        {
            if (mp[arr[i]])
            {
                ans[0] = arr[i];
                continue;
            }
            mp[arr[i]]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (!mp[i])
            {
                ans[1] = i;
                break;
            }
        }
        return ans;
    }
};
// approach 2
int *findTwoElement(int *arr, int n)
{
    int *result = new int[2];

    int origSum = 0;

    int currSum = 0;

    for (int i = 0; i < n; i++)
    {

        int origElement = abs(arr[i]);

        int index = origElement - 1;

        if (arr[index] < 0)
        {

            result[0] = origElement;
        }

        arr[index] = -arr[index];

        origSum += i + 1;

        currSum += origElement;
    }

    result[1] = origSum - (currSum - result[0]);

    return result;
}