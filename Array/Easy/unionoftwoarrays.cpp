#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    vector<int> ans;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (!mp[arr1[i]])
        {
            ans.push_back(arr1[i]);
        }
        mp[arr1[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        if (!mp[arr2[i]])
        {
            ans.push_back(arr2[i]);
        }
        mp[arr2[i]]++;
    }
    sort(ans.begin(), ans.end());
    return ans;
}