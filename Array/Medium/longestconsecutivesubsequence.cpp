#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    // arr[] : the input array
    // N : size of the array arr[]

    // Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
        sort(arr, arr + n);

        int count = 1;
        int maxi = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                continue;
            }
            if (arr[i] + 1 != arr[i + 1])
            {
                maxi = max(count, maxi);
                count = 1;
            }
            else
            {
                count++;
            }
        }
        maxi = max(count, maxi);
        return maxi;
    }
};