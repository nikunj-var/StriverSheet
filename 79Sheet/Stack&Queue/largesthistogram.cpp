#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    vector<int> nextsmall(vector<int> &heights, int n)
    {
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        for (int i = n - 1; i >= 0; i--)
        {
            int curr = heights[i];
            while (s.top() != -1 && heights[s.top()] >= curr)
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevsmall(vector<int> &heights, int n)
    {
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        for (int i = 0; i < n; i++)
        {
            int curr = heights[i];
            while (s.top() != -1 && heights[s.top()] >= curr)
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int> &heights)
    {
        int area = INT_MIN;
        int n = heights.size();
        vector<int> next(n), prev(n);
        next = nextsmall(heights, n);
        prev = prevsmall(heights, n);
        for (int i = 0; i < n; i++)
        {
            int l = heights[i];
            if (next[i] == -1)
            {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newarea = l * b;
            area = max(area, newarea);
        }
        return area;
    }
};