class Solution
{
public:
    int trap(vector<int> &height)
    {
        int waterstored = 0;
        int n = height.size();
        int left[n], right[n];
        left[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            left[i] = max(left[i - 1], height[i]);
        }
        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = max(right[i + 1], height[i]);
        }
        for (int i = 1; i < n - 1; i++)
        {
            int value = min(left[i - 1], right[i + 1]);
            if (value > height[i])
            {
                waterstored += (value - height[i]);
            }
        }
        return waterstored;
    }
};