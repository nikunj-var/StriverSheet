#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int maxLen(vector<int> &a, int n)
    {
        unordered_map<int, int> mp;
        int len = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            if (sum == 0)
            {
                len = i + 1;
            }
            else if (mp[sum] > 0)
            {
                len = max(len, i - mp[sum] + 1);
            }
            else
            {
                mp[sum] = i + 1;
            }
        }
        return len;
    }
};