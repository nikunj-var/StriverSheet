#include <iostream>
#include <queue>
using namespace std;
class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.length() != goal.length())
        {
            return false;
        }
        queue<char> q1, q2;
        for (int i = 0; i < s.length(); i++)
        {
            q1.push(s[i]);
        }
        for (int i = 0; i < goal.length(); i++)
        {
            q2.push(goal[i]);
        }
        if (q1 == q2)
            return true;
        for (int i = 0; i < s.length(); i++)
        {
            char temp = q1.front();
            q1.pop();
            q1.push(temp);
            if (q1 == q2)
                return true;
        }
        return false;
    }
};