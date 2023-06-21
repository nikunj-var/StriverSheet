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

// second method
class Solution
{
public:
    // arr1,arr2 : the arrays
    //  n, m: size of arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(int arr1[], int arr2[], int m, int n)
    {
        vector<int> ans;
        int i = 0;
        int j = 0;
        unordered_map<int, int> mp;
        while (i < m && j < n)
        {
            if (arr1[i] == arr2[j])
            {
                ans.push_back(arr1[i]);
                mp[arr1[i]]++;
                i++;
                j++;
            }
            else if (arr1[i] < arr2[j])
            {
                ans.push_back(arr1[i]);
                i++;
            }
            else
            {
                ans.push_back(arr2[j]);
                j++;
            }
        }
        while (i < m)
        {
            ans.push_back(arr1[i]);
            i++;
        }
        while (j < n)
        {
            ans.push_back(arr2[j]);
            j++;
        }
        vector<int> ans2;
        ans2.push_back(ans[0]);
        for (int i = 1; i < ans.size(); i++)
        {
            if (ans[i] != ans2.back())
            {
                ans2.push_back(ans[i]);
            }
        }
        return ans2;
    }
};
