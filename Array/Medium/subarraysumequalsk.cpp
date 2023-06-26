#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int subarraySum(vector<int> &arr, int k)
    {
        int n = arr.size();
        int count = 0, sum = 0;

        // create a hashmap
        unordered_map<int, int> Map;

        // when no element is chosen, value of sum is 0
        Map[0] = 1;

        for (int i = 0; i < n; i++)
        {
            // in each step, find the cumulative sum
            sum += arr[i];
            // check if sum-k exists in map
            // if exists the increment count by
            // mapped value for sum-k
            if (Map.find(sum - k) != Map.end())
                count += Map[sum - k];

            // add the cumulative sum obtained until now into the map
            Map[sum] = Map[sum] + 1;
        }
        return count;
    }
};