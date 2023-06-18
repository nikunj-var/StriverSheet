#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.length(); i++)
        {
            mp[s[i]]++;
        }
        for (int i = 0; i < t.length(); i++)
        {
            mp[t[i]]--;
            if (mp[t[i]] == 0)
            {
                mp.erase(t[i]);
            }
        }
        return (mp.size() == 0) ? true : false;
    }
};